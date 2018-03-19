[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating raw input devices attached to the system (keyboard, mouse, human interface device)

## Before you begin:
There are many user-input devices beside the traditional keyboard and mouse.   

For example, user input can come from a joystick, a touch screen, a microphone, or other devices that allow great flexibility in user input.   

![](../images\rawinputdevices.png)  

These devices are collectively known as Human Interface Devices (HIDs). The raw input API provides a stable and robust way for applications accepting raw input from any HID, including the keyboard and mouse.  

See also:

* [Capturing keyboard activity of another application using the Raw Input API](sample_572.md)  

  
***  


## Code:
```foxpro  
LOCAL oDevices As RawInputDevices,;
	oDevice As RawInputDevice

oDevices = CREATEOBJECT("RawInputDevices")

CREATE CURSOR csInputDevices (;
	devhandle I, devtype C(5),;
	devdescr C(100), devname C(100))

FOR EACH oDevice IN oDevices
	WITH oDevice
		INSERT INTO csInputDevices (;
			devhandle, devtype,;
			devdescr, devname) VALUES (;
				.devicehandle,;
				.devicetypename,;
				.DeviceDescription(),;
				.devicename;
			)
	ENDWITH
NEXT

GO TOP IN csInputDevices
BROWSE NORMAL NOWAIT
* end of main

DEFINE CLASS RawInputDevices As Collection
#DEFINE RIDI_DEVICENAME 0x20000007
#DEFINE RIDI_DEVICEINFO 0x2000000b
#DEFINE RIM_TYPEMOUSE 0
#DEFINE RIM_TYPEKEYBOARD 1
#DEFINE RIM_TYPEHID 2
#DEFINE RAWINPUTDEVICELIST_SIZE 8

PROCEDURE Init
	WITH THIS
		.declare
		.EnumDevices
	ENDWITH

PROCEDURE EnumDevices
	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO

	LOCAL cBuffer, nDeviceCount, nDeviceIndex,;
		hDevice, nDeviceType, oDevice As RawInputDevice

	nDeviceCount=0
	= GetRawInputDeviceList(NULL, @nDeviceCount,;
		RAWINPUTDEVICELIST_SIZE)

	cBuffer = REPLICATE(CHR(0),;
		RAWINPUTDEVICELIST_SIZE * nDeviceCount)

	= GetRawInputDeviceList(@cBuffer, @nDeviceCount,;
		RAWINPUTDEVICELIST_SIZE)

	FOR nDeviceIndex=0 TO nDeviceCount-1
		hDevice = buf2dword(SUBSTR(m.cBuffer,;
			nDeviceIndex*RAWINPUTDEVICELIST_SIZE+1,4))

		nDeviceType = buf2dword(SUBSTR(m.cBuffer,;
			nDeviceIndex*RAWINPUTDEVICELIST_SIZE+5,4))
		
		DO CASE
		CASE nDeviceType = RIM_TYPEMOUSE
			oDevice = CREATEOBJECT("MouseDevice", m.hDevice)
		CASE nDeviceType = RIM_TYPEKEYBOARD
			oDevice = CREATEOBJECT("KeyboardDevice", m.hDevice)
		CASE nDeviceType = RIM_TYPEHID
			oDevice = CREATEOBJECT("HIDDevice", m.hDevice)
		OTHERWISE
			LOOP
		ENDCASE

		THIS.Add( m.oDevice )
		oDevice=NULL
	NEXT
	
PROCEDURE declare
	DECLARE INTEGER GetRawInputDeviceList IN user32;
		STRING @pRawInputDeviceList, LONG @puiNumDevices,;
		LONG cbSize

	DECLARE INTEGER GetRawInputDeviceInfo IN user32;
		INTEGER hDevice, LONG uiCommand,;
		STRING @pData, LONG @pcbSize

ENDDEFINE

DEFINE CLASS RawInputDevice As Relation
	devicehandle=0
	devicename=""
	devicetype=-1
	deviceinfo=""
	devicetypename="undefined"

PROCEDURE Init(hDevice As Number)
	LOCAL nBufsize, cBuffer, nDeviceType

	WITH THIS
		.devicehandle = m.hDevice
		.devicetype = nDeviceType
		
		* retrieving device name
		nBufsize=0
		= GetRawInputDeviceInfo(.devicehandle,;
			RIDI_DEVICENAME, NULL, @nBufsize)

		cBuffer = REPLICATE(CHR(0), m.nBufsize)
		= GetRawInputDeviceInfo(.devicehandle,;
			RIDI_DEVICENAME, @cBuffer, @nBufsize)

		.devicename = ALLTRIM(STRTRAN(m.cBuffer, CHR(0), ""))

		* retrieving device info
		nBufsize=0
		= GetRawInputDeviceInfo(.devicehandle,;
			RIDI_DEVICEINFO, NULL, @nBufsize)
		
		cBuffer = REPLICATE(CHR(0), m.nBufsize)
		= GetRawInputDeviceInfo(.devicehandle,;
			RIDI_DEVICEINFO, @cBuffer, @nBufsize)

		.deviceinfo = m.cBuffer
		.devicetype = buf2dword(SUBSTR(m.cBuffer,5,4))
	ENDWITH

FUNCTION DeviceDescription() As String
RETURN "" &&THIS.devicetypename + " : "

ENDDEFINE

DEFINE CLASS MouseDevice As RawInputDevice
	devicetypename="MOUSE"
	* RID_DEVICE_INFO_MOUSE Structure
	Mse_Id=0
	Mse_ButtonCount=0
	Mse_SampleRate=0
	Mse_HasHorizontalWheel=0

PROCEDURE Init(hDevice As Number)
	RawInputDevice::Init( m.hDevice)

	WITH THIS
		.Mse_Id = buf2dword(SUBSTR(.deviceinfo,9,4))
		.Mse_ButtonCount = buf2dword(SUBSTR(.deviceinfo,13,4))
		.Mse_SampleRate = buf2dword(SUBSTR(.deviceinfo,17,4))
		.Mse_HasHorizontalWheel = buf2dword(SUBSTR(.deviceinfo,21,4))
	ENDWITH

FUNCTION DeviceDescription() As String
	LOCAL cDescription
	WITH THIS
		cDescription =;
			"Id=" + TRANSFORM(.Mse_Id) + ", " +;
			"Buttons=" + TRANSFORM(.Mse_ButtonCount) + ", " +;
			"Smp.Rate=" + TRANSFORM(.Mse_SampleRate) + ", " +;
			"Hor.Wheel=" + TRANSFORM(.Mse_HasHorizontalWheel)
	ENDWITH
RETURN RawInputDevice::DeviceDescription() + m.cDescription

ENDDEFINE

DEFINE CLASS KeyboardDevice As RawInputDevice
	devicetypename="KBD"
	* RID_DEVICE_INFO_KEYBOARD Structure
	Kbd_Type=0
	Kbd_SubType=0
	Kbd_Mode=0
	Kbd_FunctionKeyCount=0
	Kbd_IndicatorCount=0
	Kbd_KeyCount=0

PROCEDURE Init(hDevice As Number)
	RawInputDevice::Init( m.hDevice )

	WITH THIS
		.Kbd_Type = buf2dword(SUBSTR(.deviceinfo,9,4))
		.Kbd_SubType = buf2dword(SUBSTR(.deviceinfo,13,4))
		.Kbd_Mode = buf2dword(SUBSTR(.deviceinfo,17,4))
		.Kbd_FunctionKeyCount = buf2dword(SUBSTR(.deviceinfo,21,4))
		.Kbd_IndicatorCount = buf2dword(SUBSTR(.deviceinfo,25,4))
		.Kbd_KeyCount = buf2dword(SUBSTR(.deviceinfo,29,4))
	ENDWITH

FUNCTION DeviceDescription() As String
	LOCAL cDescription
	WITH THIS
		cDescription =;
			"Type=" + TRANSFORM(.Kbd_Type) + ", " +;
			"Subtype=" + TRANSFORM(.Kbd_SubType) + ", " +;
			"Mode=" + TRANSFORM(.Kbd_Mode) + ", " +;
			"Fn.Keys=" + TRANSFORM(.Kbd_FunctionKeyCount) + ", " +;
			"Indic.=" + TRANSFORM(.Kbd_IndicatorCount) + ", " +;
			"Keys=" + TRANSFORM(.Kbd_KeyCount)
	ENDWITH
RETURN RawInputDevice::DeviceDescription() + m.cDescription

ENDDEFINE

DEFINE CLASS HIDDevice As RawInputDevice
	devicetypename="HID"
	* RID_DEVICE_INFO_HID Structure
	Hid_VendorId=0
	Hid_ProductId=0
	Hid_VersionNumber=0
	Hid_UsagePage=0
	Hid_Usage=0

PROCEDURE Init(hDevice As Number)
	RawInputDevice::Init( m.hDevice )

	WITH THIS
		.Hid_VendorId = buf2dword(SUBSTR(.deviceinfo,9,4))
		.Hid_ProductId = buf2dword(SUBSTR(.deviceinfo,13,4))
		.Hid_VersionNumber = buf2dword(SUBSTR(.deviceinfo,17,4))
		.Hid_UsagePage = buf2word(SUBSTR(.deviceinfo,21,2))
		.Hid_Usage = buf2word(SUBSTR(.deviceinfo,23,2))
	ENDWITH

FUNCTION DeviceDescription() As String
	LOCAL cDescription
	WITH THIS
		cDescription =;
			"Vendor=" + TRANSFORM(.Hid_VendorId) + ", " +;
			"Product=" + TRANSFORM(.Hid_ProductId) + ", " +;
			"Version=" + TRANSFORM(.Hid_VersionNumber) + ", " +;
			"Usage Page=" + TRANSFORM(.Hid_UsagePage) + ", " +;
			"Usage=" + TRANSFORM(.Hid_Usage)
	ENDWITH
RETURN RawInputDevice::DeviceDescription() + m.cDescription

ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[GetRawInputDeviceInfo](../libraries/user32/GetRawInputDeviceInfo.md)  
[GetRawInputDeviceList](../libraries/user32/GetRawInputDeviceList.md)  
