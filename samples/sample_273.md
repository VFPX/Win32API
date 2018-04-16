[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Sending a standard message with one or more attached files using default email client

## Before you begin:
You do not have much control over the sending process with this function, comparing to the MAPISendMail.   

Some parameters you should enter manually through a dialog box: a list of recipients, and optional message. As well this function requires the user to push Send button on the dialog for the message to be sent.  
  
***  


## Code:
```foxpro  
DO decl

LOCAL lcPath, hWindow, lcDelimiter, lcFiles, lcMsgSubj

* save default directory (Outlook Express)
lcPath = SYS(5) + SYS(2003)

* providing the function with a handle to the VFP window
* to keep this window foreground later
hWindow = GetActiveWindow()

* delimiting character; should not be used in the file names
lcDelimiter = ";"

* list of attached files
* this is just an example; provide real file names here
lcFiles = "C:\Program Files\WinZip\WZCLUN.DLL" + lcDelimiter +;
	"C:\Program Files\WinZip\WZFM32.DLL" + lcDelimiter +;
	"C:\Program Files\WinZip\WZSHLSTB.DLL"

* the original filenames as they should appear in the subject of a message
* not always works properly
lcMsgSubj = "Files attached: " +;
	"WZCLUN.DLL" + lcDelimiter +;
	"WZFM32.DLL" + lcDelimiter +;
	"WZSHLSTB.DLL"

* a dialog box "Send New Message" appears
* if all files to be attached to the message are valid filenames
= MAPISendDocuments (hWindow, lcDelimiter, lcFiles, lcMsgSubj, 0)

* restore default directory
SET DEFAULT TO (lcPath)
* end of main

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER MAPISendDocuments IN mapi32;
		INTEGER ulUIParam, STRING lpszDelimChar,;
		STRING lpszFullPaths, STRING lpszFileNames,;
		INTEGER ulReserved  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[MAPISendDocuments](../libraries/mapi32/MAPISendDocuments.md)  

## Comment:
Provide this function with a handle to your VFP application main window to keep it on the top after the sending dialog window closes. The Outlook Express changes the default directory, that is why it needs to be saved and restored. Just another way how to send email from FoxPro application.  
  
***  

