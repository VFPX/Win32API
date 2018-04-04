[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseHandle
Group: [Handle and Object](../../functions_group.md#Handle_and_Object)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CloseHandle function closes an open object handle.

The CloseHandle function closes handles to the following objects:
	- Access token
	- Communications device
	- Console input
	- Console screen buffer
	- Event
	- File
	- File mapping
	- Job
	- Mailslot
	- Mutex (<B>Mut</B>ually<B>Ex</B>clusive)
	- Named pipe
	- Process
	- Semaphore
	- Socket

***  


## Code examples:
[Using the Semaphore object](../../samples/sample_008.md)  
[Using the CreateFile](../../samples/sample_010.md)  
[Using the DeleteFile](../../samples/sample_011.md)  
[Creating a file, then moving it to another destination](../../samples/sample_015.md)  
[Setting the date and time that a file was created](../../samples/sample_065.md)  
[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](../../samples/sample_101.md)  
[Using GetFileSize](../../samples/sample_114.md)  
[Using the Semaphore object to allow only one instance of VFP application running](../../samples/sample_147.md)  
[Locking and unlocking file of a VFP table](../../samples/sample_154.md)  
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  
[Enumerating Processes -- Win9*](../../samples/sample_164.md)  
[Comparing file times](../../samples/sample_171.md)  
[HOWTO: Use the Win32 API to Access File Dates and Times](../../samples/sample_177.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  
[Retrieving file information for the VFP executable running](../../samples/sample_242.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Creating a mailslot](../../samples/sample_267.md)  
[Using mailslots to send messages on the network](../../samples/sample_269.md)  
[Testing serial ports](../../samples/sample_308.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[Starting external program from VFP and waiting for its termination](../../samples/sample_377.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[How to suspend or hibernate your system](../../samples/sample_395.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  
[Monitoring changes occurring within a directory](../../samples/sample_400.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  
[How to Start a Process as Another User (NT/XP/2K)](../../samples/sample_426.md)  
[How to run FoxPro application under different user name (impersonating user)](../../samples/sample_470.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  
[Using named pipes for interprocess communication](../../samples/sample_522.md)  
[How to find when the application started](../../samples/sample_534.md)  
[Obtaining I/O counts for the current process](../../samples/sample_535.md)  
[Copying files as a transacted operation (Vista)](../../samples/sample_540.md)  
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[How to check whether the system is 32-bit or 64-bit](../../samples/sample_580.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL CloseHandle(
  HANDLE hObject   // handle to object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseHandle IN kernel32;
	INTEGER hObject  
```  
***  


## Parameters:
hObject 
[in/out] Handle to an open object  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  

