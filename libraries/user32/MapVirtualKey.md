[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MapVirtualKey
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Translates (maps) a virtual-key code into a scan code or character value, or translates a scan code into a virtual-key code.
***  


## Code examples:
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  

## Declaration:
```foxpro  
UINT WINAPI MapVirtualKey(
  __in  UINT uCode,
  __in  UINT uMapType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MapVirtualKey IN user32;
	LONG uCode,;
	LONG uMapType  
```  
***  


## Parameters:
uCode [in]
The virtual key code or scan code for a key. How this value is interpreted depends on the value of the uMapType parameter.

uMapType [in]
The translation to be performed. The value of this parameter depends on the value of the uCode parameter.  
***  


## Return value:
The return value is either a scan code, a virtual-key code, or a character value, depending on the value of uCode and uMapType. If there is no translation, the return value is zero.  
***  


## Comments:
To specify a handle to the keyboard layout to use for translating the specified code, use the MapVirtualKeyEx function.  
  
***  

