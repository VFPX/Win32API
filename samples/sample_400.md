[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Monitoring changes occurring within a directory

## Before you begin:
To stop the following code after it has been started, open and save any file in C:\TEMP directory.  

See also:

* [FileSystemWatcher ActiveX Control for Visual FoxPro](../downloads/DirectoryWatch.zip)  
* [Monitoring changes in a directory](sample_117.md)  
* [Enumerating files opened on the network](sample_121.md)  
  
***  


## Code:
```foxpro  
DO declare

#DEFINE FILE_LIST_DIRECTORY 1
#DEFINE GENERIC_WRITE  0x40000000
#DEFINE GENERIC_READ   0x80000000
#DEFINE FILE_SHARE_DELETE 4
#DEFINE FILE_SHARE_READ   1
#DEFINE OPEN_EXISTING     3
#DEFINE FILE_FLAG_BACKUP_SEMANTICS 0x02000000
#DEFINE FILE_FLAG_OVERLAPPED 0x40000000

#DEFINE FILE_NOTIFY_CHANGE_FILE_NAME   1
#DEFINE FILE_NOTIFY_CHANGE_LAST_WRITE  16

LOCAL cFolder, hFolder
cFolder = "c:\temp"

hFolder = CreateFile(cFolder, FILE_LIST_DIRECTORY,;
	FILE_SHARE_READ+FILE_SHARE_DELETE, 0, OPEN_EXISTING,;
	FILE_FLAG_BACKUP_SEMANTICS+FILE_FLAG_OVERLAPPED, 0)

IF hFolder = -1
	? "Error code:", GetLastError()
	RETURN
ENDIF

LOCAL nFilter, cBuffer, nReturned
nFilter = FILE_NOTIFY_CHANGE_FILE_NAME + FILE_NOTIFY_CHANGE_LAST_WRITE
cBuffer = Repli(Chr(0), 16384)
nReturned = 0

*|typedef struct _FILE_NOTIFY_INFORMATION {
*|  DWORD NextEntryOffset;   0:4
*|  DWORD Action;            4:4
*|  DWORD FileNameLength;   12:4
*|  WCHAR FileName[1];      16:
*|} FILE_NOTIFY_INFORMATION, *PFILE_NOTIFY_INFORMATION;

= ReadDirectoryChangesW(hFolder, @cBuffer, Len(cBuffer),;
	1, nFilter, @nReturned, 0,0)

IF nReturned <> 0
	? SUBSTR(cBuffer, 1,nReturned)
ENDIF

= CloseHandle(hFolder)
* end of main

PROCEDURE declare
	DECLARE INTEGER ReadDirectoryChangesW IN kernel32;
		INTEGER hDirectory, STRING @lpBuffer, INTEGER nBufferLength,;
		INTEGER bWatchSubtree, INTEGER dwNotifyFilter, INTEGER @lpBytesReturned,;
		INTEGER lpOverlapped, INTEGER lpCompletionRoutine

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetLastError IN kernel32  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[ReadDirectoryChangesW](../libraries/kernel32/ReadDirectoryChangesW.md)  

## Comment:
To stop the following code after it has been started, open and save any file in C:\TEMP directory.  
  
* * *  
The C++ sample displays file and directory changes for drive C in a console window. Close the window when you no longer need it.   
  
This code itself makes an interesting tool. [Download C++ project](../downloads/DirectoryWatch.zip) , compile and start the executable. Then open VFP or IE window, or even move the mouse above the Windows taskbar -- you will see how many files and directory modifications may hide behind such a simple action.  
  
* * *  
Deleting a directory with subdirectories into the Recycle Bin produces a single FILE_NOTIFY_INFORMATION structure with the directory data. While a direct delete (the Recycle Bin is bypassed) triggers ReadDirectoryChangesW for each subdirectory, and finally for the directory.  
  
* * *  
When designing a file monitoring utility (FLL or ActiveX control), it should be considered that VFP creates single threaded applications.   
  
While busy with processing directory changes, an application is unable to receive other changes coming. Frequent changes and substantial processing time make such miss unavoidable.  
  
Thus a VFP application must receive not the actual directory changes, but rather be notified when they occur. Notifications may come through window messages or by events raised.   
  
A monitoring utility must take care of piling changes in its own memory, and dispatching them to a client application upon request.  
  
***  

