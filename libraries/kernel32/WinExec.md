[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinExec
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  
## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.


#### The WinExec function runs the specified application.

Note  This function is provided only for compatibility with 16-bit Windows. Win32-based applications should use the CreateProcess function

***  


## Code examples:
[Starting an external application in VFP using WinExec](../../samples/sample_002.md)  
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Setting properties of the window: caption and user-defined value](../../samples/sample_182.md)  
[Confining Windows calculator inside the VFP main window](../../samples/sample_245.md)  
[Accessing Windows Control Panel from VFP Application](../../samples/sample_391.md)  

## Declaration:
```foxpro  
UINT WinExec(
  LPCSTR lpCmdLine,  // command line
  UINT uCmdShow      // window style
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinExec IN kernel32;
	STRING cCmdLine,;
	INTEGER nCmdShow
  
```  
***  


## Parameters:
lpCmdLine 
[in] Pointer to a null-terminated character string that contains the command line (file name plus optional parameters) for the application to be executed

uCmdShow 
[in] Specifies how a Windows-based application window is to be shown ...
  
***  


## Return value:
If the function succeeds, the return value is greater than 31.

If the function fails, the return value is one of the following error values: 

* The system is out of memory or resources. 
* 0 

* The .exe file is invalid (non-Win32 .exe or error in .exe image). 
#DEFINE ERROR_BAD_FORMAT	11 

* The specified file was not found. 
#DEFINE ERROR_FILE_NOT_FOUND 	2

* The specified path was not found. 
#DEFINE ERROR_PATH_NOT_FOUND	3
  
***  


## Comments:
The native VFP command RUN | ! Command probably uses the same way, though I feel that sometimes the direct calling is more effective.  
  
Microsoft says:  
If a malicious user were to create an application called "Program.exe" on a system, any program that incorrectly calls WinExec using the Program Files directory will run this application instead of the intended application.  

<!-- Anatoliy --> 
<a href="videos/WinExec.wmv">Watch a short video</a> to see how to use the WinExec in VFP.  
  
***  

