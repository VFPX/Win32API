[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mciSendCommand
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Sends a command message to the specified MCI device.
***  


## Declaration:
```foxpro  
MCIERROR mciSendCommand(
	MCIDEVICEID IDDevice,
	UINT uMsg,
	DWORD fdwCommand,
	DWORD_PTR dwParam
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mciSendCommand IN winmm;
	INTEGER IDDevice,;
	LONG uMsg,;
	LONG fdwCommand,;
	LONG dwParam
  
```  
***  


## Parameters:
IDDevice
Device identifier of the MCI device that is to receive the command message. This parameter is not used with the MCI_OPEN command message.

uMsg
Command message, a multimedia command.

fdwCommand
Flags for the command message.

dwParam
Pointer to a structure that contains parameters for the command message.  
***  


## Return value:
Returns zero if successful or an error otherwise.  The low-order word of the returned DWORD value contains the error return value.

To retrieve a text description of return values, pass the return value to the mciGetErrorString function.  
***  


## Comments:
<a href="http://msdn.microsoft.com/en-us/library/dd743571(VS.85).aspx">List of Multimedia Commands</a> on MSDN.  
  
See also: [mciSendString](../winmm/mciSendString.md), [mciGetDeviceID](../winmm/mciGetDeviceID.md).  
  
***  

