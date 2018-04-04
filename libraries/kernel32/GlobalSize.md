[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalSize
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GlobalSize function retrieves the current size, in bytes, of the specified global memory object
***  


## Code examples:
[Enumerating data formats currently available on the clipboard](../../samples/sample_032.md)  
[Reading and setting explicit Application User Model ID for the current process (Win7)](../../samples/sample_038.md)  
[Retrieving the command line for the VFP session](../../samples/sample_051.md)  
[Storing the environment strings in cursor](../../samples/sample_089.md)  
[Enumerating files opened on the network](../../samples/sample_121.md)  
[Dynamic strings implemented through VFP Custom class](../../samples/sample_157.md)  
[URL: splitting into its component parts](../../samples/sample_184.md)  
[Sending email messages with Simple MAPI](../../samples/sample_193.md)  
[How to write and read Window Properties for the specified window](../../samples/sample_205.md)  
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Converting command-line string to a set of Unicode argument strings](../../samples/sample_212.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  
[Creating the Save dialog box to specify the drive, directory, and name of a file to save](../../samples/sample_265.md)  
[How to display the Properties dialog box for a file (ShellExecuteEx)](../../samples/sample_320.md)  
[Deleting files into the Recycle Bin](../../samples/sample_321.md)  
[Adding printer to the list of supported printers for the specified server](../../samples/sample_335.md)  
[MapiSendMail class for Visual FoxPro application](../../samples/sample_342.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  
[Creating the Open dialog box to specify the drive, directory, and name of a file to open](../../samples/sample_363.md)  
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  
[Mapping and disconnecting network drives](../../samples/sample_387.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[Retrieving configuration information for the specified server (Win2000/XP)](../../samples/sample_425.md)  
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  
[Obtaining names of local and global groups for current user (WinNT/XP/2K)](../../samples/sample_431.md)  
[Adding and deleting User Accounts](../../samples/sample_478.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  
[How to assemble an array of strings and pass it to external function](../../samples/sample_487.md)  
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  
[Displaying standard progress dialog box when copying files](../../samples/sample_508.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  
[How to enumerate terminal servers within the specified Windows domain](../../samples/sample_520.md)  
[Reading entries from Event logs](../../samples/sample_524.md)  
[How to display the Print property sheet](../../samples/sample_531.md)  
[Extensible Storage Engine class library](../../samples/sample_532.md)  
[Using WM_COPYDATA for interprocess communication (VFP9)](../../samples/sample_536.md)  
[How to remove a directory that is not empty](../../samples/sample_541.md)  
[Starting a dialog box for connecting to network resources and passing input parameters](../../samples/sample_551.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  
[How to display advanced Task Dialog (Vista)](../../samples/sample_558.md)  
[Writing entries to custom Event Log](../../samples/sample_564.md)  
[Compressing and decompressing files with Windows API Runtime Library routines](../../samples/sample_568.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
SIZE_T GlobalSize(
  HGLOBAL hMem   // handle to global memory object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
  
```  
***  


## Parameters:
hMem 
[in] Handle to the global memory object  
***  


## Return value:
If the function succeeds, the return value is the size, in bytes, of the specified global memory object. 

If the specified handle is not valid or if the object has been discarded, the return value is zero. 
  
***  

