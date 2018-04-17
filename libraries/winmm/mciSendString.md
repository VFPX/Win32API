[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mciSendString
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The <b>mciSendString</b> function sends a command string to an MCI device. The device that the command is sent to is specified in the command string. 
***  


## Code examples:
[Accessing a CD device (cdaudio) with Multimedia Command Strings](../../samples/sample_279.md)  
[Using Multimedia Command Strings to play MIDI files](../../samples/sample_538.md)  

## Declaration:
```foxpro  
MCIERROR mciSendString(
  LPCTSTR lpszCommand,
  LPTSTR lpszReturnString,
  UINT cchReturn,
  HANDLE hwndCallback
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mciSendString IN winmm;
	STRING    lpszCommand,;
	STRING  @ lpszReturnString,;
	INTEGER   cchReturn,;
	INTEGER   hwndCallback
  
```  
***  


## Parameters:
lpszCommand 
Pointer to a null-terminated string that specifies an MCI command string. For a list, see [Multimedia Command Strings](https://msdn.microsoft.com/en-us/library/windows/desktop/dd743572(v=vs.85).aspx). 

lpszReturnString 
Pointer to a buffer that receives return information. If no return information is needed, this parameter can be NULL. 

cchReturn 
Size, in characters, of the return buffer specified by the lpszReturnString parameter. 

hwndCallback 
Handle to a callback window if the "notify" flag was specified in the command string.  
***  


## Return value:
Returns zero if successful or an error otherwise. To retrieve a text description of mciSendString return values, pass the return value to the mciGetErrorString function.   
***  

