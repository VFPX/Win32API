[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetActiveWindow
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetActiveWindow function retrieves the window handle to the active window attached to the calling thread"s message queue. 
***  


## Code examples:
[Testing Clipboard functions: emptying the clipboard](../../samples/sample_028.md)  
[Who owns the Windows Clipboard](../../samples/sample_029.md)  
[Who is the first in viewing the Clipboard](../../samples/sample_030.md)  
[Printing text on the client area of the main VFP window](../../samples/sample_034.md)  
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Using GetNearestColor](../../samples/sample_044.md)  
[Using the MessageBox Win32 function](../../samples/sample_048.md)  
[Obtaining window class name for the main VFP window](../../samples/sample_049.md)  
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Using InternetGoOnline function](../../samples/sample_067.md)  
[Comparing dimensions of the VFP main window with _SCREEN properties](../../samples/sample_078.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[Locking mouse and keyboard input for the VFP application](../../samples/sample_084.md)  
[GetFocus returns a HWND value](../../samples/sample_090.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Retrieving information about the main VFP window](../../samples/sample_111.md)  
[FindText -- the hopeless and useless Common Dialog](../../samples/sample_160.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Retrieving Window Class information for the VFP window](../../samples/sample_201.md)  
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  
[Drawing cursors for the classes defined by the system (preregistered): BUTTON, EDIT, LISTBOX etc.](../../samples/sample_203.md)  
[Retrieving long values associated with the class of the VFP window](../../samples/sample_204.md)  
[Using IsChild() for testing ThisForm.ShowWindow property](../../samples/sample_207.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[How to make the caption of a VFP application flashing in the Windows task bar](../../samples/sample_228.md)  
[Obtaining the bounding rectangle for the specified device context](../../samples/sample_237.md)  
[Drawing a window caption using the DrawCaption routine](../../samples/sample_238.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  
[Confining Windows calculator inside the VFP main window](../../samples/sample_245.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Drawing Windows frame controls using the DrawFrameControl function](../../samples/sample_254.md)  
[Drawing a rectangle using Windows regular edges and borders](../../samples/sample_256.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[Using the ChooseColor function](../../samples/sample_264.md)  
[Creating the Save dialog box to specify the drive, directory, and name of a file to save](../../samples/sample_265.md)  
[The window and its ancestors](../../samples/sample_266.md)  
[Using FlashWindowEx to flash the taskbar button of the VFP application](../../samples/sample_271.md)  
[Sending a standard message with one or more attached files using default email client](../../samples/sample_273.md)  
[Getting a bit more than the _CLIPTEXT offers](../../samples/sample_278.md)  
[Setting the mouse capture to the specified window](../../samples/sample_282.md)  
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Using the DrawText function](../../samples/sample_303.md)  
[Using Font and Text functions](../../samples/sample_304.md)  
[Using the IsWindowEnabled function](../../samples/sample_306.md)  
[Starting a dialog box for connecting to network resources (mapping network drive)](../../samples/sample_309.md)  
[Initiating Inet connection using a modem](../../samples/sample_312.md)  
[How to display the Properties dialog box for a file (ShellExecuteEx)](../../samples/sample_320.md)  
[Deleting files into the Recycle Bin](../../samples/sample_321.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Reading metrics for the currently selected font](../../samples/sample_339.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[Using the GradientFill function](../../samples/sample_353.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Using the RestartDialog function -- restarting Windows](../../samples/sample_361.md)  
[How to display the port-configuration dialog box for a port on the specified server](../../samples/sample_362.md)  
[Creating the Open dialog box to specify the drive, directory, and name of a file to open](../../samples/sample_363.md)  
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  
[Creating an Open dialog box to specify the drive, directory, and name of a file to open (Shell32 version)](../../samples/sample_365.md)  
[Displaying printer-properties Property Sheet for the specified printer](../../samples/sample_372.md)  
[How to browse and connect to printers on a network (WinNT)](../../samples/sample_376.md)  
[How to display a dialog box with which the user can add a data source (DSN)](../../samples/sample_380.md)  
[Adding an ODBC data source with the SQLConfigDataSource; use automatic or interactive mode](../../samples/sample_381.md)  
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[Simple MAPI: how to pick an email recipient from Outlook Express address book](../../samples/sample_407.md)  
[Form Magnifier](../../samples/sample_414.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  
[How to remove a directory that is not empty](../../samples/sample_541.md)  

## Declaration:
```foxpro  
HWND GetActiveWindow(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetActiveWindow IN user32
  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is the handle to the active window attached to the calling thread"s message queue. Otherwise, the return value is NULL.   
***  


## Comments:
For a VFP application you always have this function pointing to the main VFP window.   
  
To get the handle to the foreground window, you can use GetForegroundWindow.   
  
Windows 98/Me and Windows NT 4.0 SP3 and later: To get the window handle to the active window in the message queue for another thread, use GetGUIThreadInfo.  
  
Starting with version 7th the Visual FoxPro includes window handle in standard properties of the Form object.  
  
See also: [GetFocus](../user32/GetFocus.md), [GetForegroundWindow](../user32/GetForegroundWindow.md), [SwitchToThisWindow](../user32/SwitchToThisWindow.md).  
  
***  

