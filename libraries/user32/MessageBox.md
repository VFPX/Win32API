<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MessageBox
Group: Dialog Box - Library: user32    
***  


#### Creates, displays, and operates a message box. The message box contains an application-defined message and title, plus any combination of predefined icons and push buttons
***  


## Code examples:
[Using the MessageBox Win32 function](../../samples/sample_048.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  

## Declaration:
```foxpro  
int MessageBox(
  HWND hWnd,          // handle to owner window
  LPCTSTR lpText,     // text in message box
  LPCTSTR lpCaption,  // message box title
  UINT uType          // message box style
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MessageBox IN user32 As MessageBoxA;
	INTEGER hwnd,;
	STRING  lpText,;
	STRING  lpCaption,;
	INTEGER wType  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the owner window of the message box to be created

lpText
[in] Pointer to a null-terminated string that contains the message to be displayed

lpCaption
[in] Pointer to a null-terminated string that contains the dialog box title

uType
[in] Specifies the contents and behavior of the dialog box. This parameter can be a combination of flags  
```  
***  


## Return value:
If the function succeeds, the return value is one of the predefined menu-item values  
***  


## Comments:
See also: MessageBoxIndirect, TaskDialog, TaskDialogIndirect, SetWindowsHookEx   
  
Right-to-left MessageBox (see Usage code above):  
  
<img src="images/messagebox_rtl.png">  
  
* * *  
Click on the picture below to download   
Extended MessageBox library (FLL) for Visual FoxPro.  
  
<a href="http://www.news2news.com/vfp/?solution=3"><img src="images/udficon_skype.png" border=0 alt="Download MsgBox FLL"></a>  
  
* * *  
The Visual FoxPro contains a limited edition of this function, which is implemented via MESSAGEBOX() function. In most of the cases that is enough. Through the Win32 function you can reach all functionality of this dialog box.  
  
The VFP, up to the version 6, gives an access to three groups of constants defining the contents and behavior of this object. There are several more groups (see the examples), which could be helpful.  
  
For example, you can create a message box, which is placed on top of all open windows, not only the FoxPro Main window. Some other combinations of constants can give even more functionality, just try.  
  
* * *  
Another application of this function you might be interested in is to invoke a dailog in Automation Servers (EXE, DLL or MTDLL) created with Visual FoxPro. Built-in MessageBox generates an error (or at least fails to appear) while the API version of this function works Ok.  
  
* * *  
There are so many interfaces to this simple function from various programming languages. Here is another one from the Windows Scripting with the <Em>Timeout</Em> parameter puzzlingly positioned at the second place:  
  
<code>Usage:  
object.Popup (Message [, TimeOut][, Title] [, Format])</code>  
  
<div class="precode">WshShell = CREATEOBJECT("WScript.Shell")  
Result = WshShell.Popup("This is a popup box!", 10, "Title", 65)  
? Result  
</div>  
  
* * *  
An enhancement in the MessageBox implementation in Vista: the OS wraps long messages maintaining a reasonable width of the dialog window.  
  
* * *  
The SetWindowsHookEx, while virtually useless in pure VFP code, can easily be utillized in Visual FoxPro via creating a FLL or DLL library.  
  
For example, provided a certain windows hook set, each following MESSAGEBOX() dialog within current VFP session would appear not centered but instead would automatically position itself at the specified screen location.  
  
  
***  

