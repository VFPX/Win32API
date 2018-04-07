[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### This function creates, opens, or truncates a file, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.

Use the CloseHandle function to close an object handle returned by CreateFile
***  


## Code examples:
[Using the CreateFile](../../samples/sample_010.md)  
[Using the DeleteFile](../../samples/sample_011.md)  
[Creating a file, then moving it to another destination](../../samples/sample_015.md)  
[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](../../samples/sample_101.md)  
[HOWTO: Use the Win32 API to Access File Dates and Times](../../samples/sample_177.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Using mailslots to send messages on the network](../../samples/sample_269.md)  
[Testing serial ports](../../samples/sample_308.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  
[Monitoring changes occurring within a directory](../../samples/sample_400.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
HANDLE CreateFile(
	LPCTSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDispostion,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateFile IN kernel32;
	STRING  lpFileName,;
	INTEGER dwDesiredAccess,;
	INTEGER dwShareMode,;
	INTEGER lpSecurityAttributes,;
	INTEGER dwCreationDisposition,;
	INTEGER dwFlagsAndAttributes,;
	INTEGER hTemplateFile  
```  
***  


## Parameters:
Skipped  
***  


## Return value:
An open handle to the specified file indicates success  
***  


## Comments:
lpSecurityAttributes is ignored for Win9*.  
  
Attribute FILE_FLAG_DELETE_ON_CLOSE -- is handy for creating temporary files. Indicates that the operating system is to delete the file immediately after all of its handles have been closed. So you don"t care to delete this file afterwards. When you do not need it anymore -- just close the handle or exit VFP.  
  
The huge variety of avilable attributes makes this command very strong and sophisticated.  
The function also can be used to put a message in a mailslot.  
  
See also: [CreateFileTransacted](../kernel32/CreateFileTransacted.md).  
  
***  

