[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using Shell for performing operations on files

## Before you begin:
Select valid file and directory names before testing this code.  

Other code samples you might be interested in:  
* [Running external applications from VFP using WinExec](sample_002.md)  
* [Running external applications from VFP using CreateProcess](sample_003.md)  
* [Running an external program from FoxPro and waiting for its termination](sample_377.md)  
* [How to Start a Process as Another User (NT/XP/2K)](sample_426.md)  

  
***  


## Code:
```foxpro  
#DEFINE SW_SHOWNORMAL 1
#DEFINE SW_SHOWMINIMIZED 2
#DEFINE SW_SHOWMAXIMIZED 3

	DECLARE INTEGER GetSystemDirectory IN kernel32;
		STRING @lpBuffer, INTEGER nSize

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hWindow, STRING lpOperation,;
		STRING lpFile, STRING lpParameters,;
		STRING lpDirectory, INTEGER nShowCmd

	* opens data files with their associated applications
*	= ShellExecute(0, "open", "c:\aa\index.mdb", "", "", SW_SHOWMAXIMIZED)
*	= ShellExecute(0, "open", "c:\aa\aa.bmp", "", "", SW_SHOWMAXIMIZED)
*	= ShellExecute(0, "open", "c:\aa\lacrymosa.mp3", "", "", SW_SHOWMAXIMIZED)
*	= ShellExecute(0, "open", "c:\aa\mkart.doc", "", "", SW_SHOWMAXIMIZED)
*	= ShellExecute(0, "open", "c:\aa\aa.txt", "", "", SW_SHOWMAXIMIZED)

	* opens a folder
*	= ShellExecute(0, "explore", "c:\Temp", "", "", SW_SHOWMAXIMIZED)

	* open Search window starting from the specified directory
*	= ShellExecute(0, "find", "", "", getSysDir(), SW_SHOWMAXIMIZED)
	
	* prints the text file using the associated application
*	= ShellExecute(0, "print", "c:\aa\index.txt", "", "", SW_SHOWMAXIMIZED)

	* accessing a site on the Internet
*	= ShellExecute(0, "open", "http://www.microsoft.com/",;
*		"", "", SW_SHOWMAXIMIZED)

	* sending an email:
	* Mike Lewis, http://www.ml-consult.demon.co.uk/foxst-22.htm

	LOCAL lcMail
	lcMail = "mailto:buddy1@somwhere.com" +;
		"?CC=buddy2@somwhere.com&Subject=Meet for lunch" +;
		"&Body=Please join me for a sandwich at noon."

	= ShellExecute(0, "open", lcMail, "", "", SW_SHOWNORMAL)
	
FUNCTION GetSysDir
	lpBuffer = SPACE(250)
	nSizeRet = GetSystemDirectory(@lpBuffer, Len(lpBuffer))
RETURN SUBSTR(lpBuffer, 1, nSizeRet)  
```  
***  


## Listed functions:
[GetSystemDirectory](../libraries/kernel32/GetSystemDirectory.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  

## Comment:
There is one more action type -- EDIT.   
  
For some actions failed, GetLastError returns() value 1155, that means ERROR_NO_ASSOCIATION | No application is associated with the specified file for this operation..  
  
Links: 

* [HOWTO: Use ShellExecute to Launch Associated File (32-bit) (Q170918)](https://jeffpar.github.io/kbarchive/kb/170/Q170918/).  
* [Tip 168: Using the ShellExecute Function to Print Files](http://www.visualbasicsource.net/redirectpage.html?http://www.visualbasicsource.net/VBTips/168.html).  
* [An easy way sending emails from a Visual FoxPro application](http://www.ml-consult.co.uk/foxst-22.htm) -- an article of Mike Lewis.  
* VBNet: [Sending Large Emails via ShellExecute](http://www.mvps.org/vbnet/index.html?code/internet/shellexecutelargeemail.htm).  
  

  
***  

