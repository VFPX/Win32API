[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalFree
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GlobalFree function frees the specified global memory object and invalidates its handle
***  


## Code examples:
[Enumerating printer drivers installed](../../samples/sample_082.md)  
[Using EnumPrinters function to enumerate locally installed printers](../../samples/sample_146.md)  
[Copying strings through the global memory block](../../samples/sample_156.md)  
[Dynamic strings implemented through VFP Custom class](../../samples/sample_157.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Enhanced GetFont dialog](../../samples/sample_159.md)  
[FindText -- the hopeless and useless Common Dialog](../../samples/sample_160.md)  
[URL: splitting into its component parts](../../samples/sample_184.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Sending email messages with Simple MAPI](../../samples/sample_193.md)  
[Using FillMemory](../../samples/sample_198.md)  
[How to write and read Window Properties for the specified window](../../samples/sample_205.md)  
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Converting command-line string to a set of Unicode argument strings](../../samples/sample_212.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  
[Using the ChooseColor function](../../samples/sample_264.md)  
[Creating the Save dialog box to specify the drive, directory, and name of a file to save](../../samples/sample_265.md)  
[Enumerating network resources](../../samples/sample_313.md)  
[How to display the Properties dialog box for a file (ShellExecuteEx)](../../samples/sample_320.md)  
[Deleting files into the Recycle Bin](../../samples/sample_321.md)  
[Enumerating ports that are available for printing on a specified server](../../samples/sample_334.md)  
[Adding printer to the list of supported printers for the specified server](../../samples/sample_335.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[MapiSendMail class for Visual FoxPro application](../../samples/sample_342.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[How to enumerate cookies and URL History entries in the cache of the local computer](../../samples/sample_350.md)  
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  
[Creating the Open dialog box to specify the drive, directory, and name of a file to open](../../samples/sample_363.md)  
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  
[How to browse and connect to printers on a network (WinNT)](../../samples/sample_376.md)  
[Mapping and disconnecting network drives](../../samples/sample_387.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[Enumerating forms supported by a specified printer](../../samples/sample_390.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  
[WAV file player](../../samples/sample_417.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Quering Audio Mixer Device](../../samples/sample_423.md)  
[GDI+: reading and writing metadata in JPEG and TIFF files](../../samples/sample_461.md)  
[How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory](../../samples/sample_471.md)  
[Adding and deleting User Accounts](../../samples/sample_478.md)  
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  
[How to assemble an array of strings and pass it to external function](../../samples/sample_487.md)  
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  
[Obtaining addresses for the adapters on the local computer (Win XP/2003/Vista)](../../samples/sample_506.md)  
[Displaying standard progress dialog box when copying files](../../samples/sample_508.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  
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
[Verifying a file using the Authenticode policy provider](../../samples/sample_569.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
HGLOBAL GlobalFree(
  HGLOBAL hMem   // handle to global memory object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalFree IN kernel32;
	INTEGER hMem  
```  
***  


## Parameters:
hMem 
[in] Handle to the global memory object  
***  


## Return value:
If the function succeeds, the return value is NULL. If the function fails, the return value is equal to a handle to the global memory object.
  
***  

