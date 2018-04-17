[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Accessing Adobe Reader 7.0 main menu from VFP application

## Short description:
I was looking for a simple way of closing Adobe Reader document and leaving intact other open PDF documents and the reader itself. Presented AdobeAcrobat7 class enumerates opened pdf documents. It also can close any Acrobat document window or all document windows and more.  
***  


## Before you begin:
I was looking for a simple way of closing Adobe Reader document (PDF) and leaving intact other open documents and the Reader itself.  

Presented on this page, the AdobeAcrobat7 class enumerates opened pdf documents. It also can close any Acrobat document window or all document windows and more.  

Use the following code to test the class:  

```foxpro
LOCAL oReader As AdobeAcrobat7, oDoc As AdobeDocument  
oReader = CREATEOBJECT("AdobeAcrobat7")  

IF NOT oReader.AcrobatIsRunning()  
	cDocument = GETFILE("PDF", "Acrobat document",;  
		"Open",0,"Open Acrobat Reader document")  
	IF EMPTY(cDocument)  
		RETURN  
	ENDIF  
	IF NOT oReader.OpenAcrobatDocument(cDocument)  
		= MESSAGEBOX("Could not open " +;  
			"Acrobat Reader document.     ",;  
			48, "Error!")  
		RETURN  
	ENDIF  
ENDIF  

FOR EACH oDoc IN oReader.documents  
	? oDoc.filename  
	IF oDoc.filename = "mydoc.pdf"  
		oReader.CloseDocument(m.oDoc)  
	ENDIF  
NEXT  

IF MESSAGEBOX("Exit Acrobat?",32+4)=6  
	oReader.ExitAcrobat  
ENDIF
```
See also:

* [How to control Adobe Reader 9.0 from VFP application](sample_550.md)  
  
***  


## Code:
```foxpro  
#DEFINE WM_COMMAND 0x0111
#DEFINE ACROBAT_WINCLASS "AdobeAcrobat"
#DEFINE POS_SUBMENU_WINDOW 6
#DEFINE ID_FILE_OPEN 6001
#DEFINE ID_FILE_CLOSE 6005
#DEFINE ID_FILE_EXIT 6026
#DEFINE ID_FILE_CLOSEALL 6143
#DEFINE ID_WINDOW_FIRSTDOC 6004
#DEFINE SW_SHOWNORMAL 1

DEFINE CLASS AdobeAcrobat7 As Session
PROTECTED hWindow, hMenu
	hWindow=0
	hMenu=0
	documents=0
	ActiveDocumentName=""

PROCEDURE Init
	THIS.declare
	THIS.documents = CREATEOBJECT("Collection")
	THIS.FindMainWindow
	THIS.EnumOpenDocuments

FUNCTION AcrobatIsRunning() As Boolean
RETURN (IsWindow(THIS.hWindow) <> 0)

PROCEDURE ExitAcrobat
* closes Adobe Reader main window
	THIS.ExecMenu(ID_FILE_EXIT)

FUNCTION OpenAcrobatDocument(cDocument) As Boolean
	IF FILE(m.cDocument) AND ".pdf" $ LOWER(cDocument)
		LOCAL nResult
		nResult = ShellExecute(0, "open", m.cDocument,;
			"", "", SW_SHOWNORMAL)
		IF nResult <= 32
			RETURN .F.
		ENDIF
		THIS.EnumOpenDocuments
		RETURN .T.  && simplified
	ELSE
		RETURN .F.
	ENDIF

PROCEDURE InitDlgOpenFile
* initiates Open File dialog
	IF IsWindow(THIS.hWindow) <> 0
		= SwitchToThisWindow(THIS.hWindow, 1)
		THIS.ExecMenu(ID_FILE_OPEN)
	ENDIF

PROCEDURE SwitchToDocument(oDocument As AdobeDocument)
* makes document active
	THIS.ExecMenu(oDocument.windowmenuid)
	THIS.GetOpenDocumentName
RETURN (oDocument.filename==THIS.ActiveDocumentName)

PROCEDURE CloseDocument(oDocument As AdobeDocument)
* closes open Adobe Reader document
	IF THIS.SwitchToDocument(oDocument)
		THIS.ExecMenu(ID_FILE_CLOSE)
		THIS.EnumOpenDocuments
	ENDIF

PROCEDURE CloseAllDocuments
* closes all open Adobe Reader documents
	THIS.ExecMenu(ID_FILE_CLOSEALL)

FUNCTION GetOpenDocumentName() As String
* returns name of active Adobe Reader document
	LOCAL cWinText, nPos, cDocname
	cWinText = THIS.GetWinText(THIS.hWindow)
	nPos=AT("[",cWinText)
	IF nPos = 0
		THIS.ActiveDocumentName = ""
	ELSE
		cDocname = SUBSTR(cWinText, nPos+1)
		cDocname = SUBSTR(cDocname, 1, LEN(cDocname)-1)
		THIS.ActiveDocumentName = cDocname
	ENDIF
RETURN THIS.ActiveDocumentName

FUNCTION EnumOpenDocuments As Number
* enumerates open Adobe Reader documents
	DO WHILE THIS.documents.Count > 0
		THIS.documents.Remove(1)
	ENDDO
	
	IF IsMenu(THIS.hMenu)=0
		RETURN 0
	ENDIF
	
	LOCAL hSubmenu, nIndex, nCount, nItemID, lDocItem, cDocname

	* obtain handle of WINDOW submenu
	hSubmenu = GetSubMenu(THIS.hMenu, POS_SUBMENU_WINDOW)
	IF IsMenu(hSubmenu)=0
		RETURN 0
	ENDIF

	lDocItem=.F.
	nCount = GetMenuItemCount(m.hSubmenu)

	* scan menu items in WINDOW submenu
	FOR nIndex=0 TO nCount-1
		nItemID = GetMenuItemID(m.hSubmenu, nIndex)

		IF nItemID = ID_WINDOW_FIRSTDOC
			lDocItem=.T.
		ENDIF
		
		IF m.lDocItem
			THIS.ExecMenu(nItemID)
			THIS.GetOpenDocumentName

			IF NOT EMPTY(THIS.ActiveDocumentName)
				LOCAL oDocument As AdobeDocument
				oDocument = CREATEOBJECT("AdobeDocument",;
					THIS.ActiveDocumentName, nItemID)
				THIS.documents.Add(oDocument)
			ENDIF
		ENDIF
	NEXT
RETURN THIS.documents.Count
	
PROTECTED PROCEDURE ExecMenu(nCommand)
* initiates application menu command
	IF IsWindow(THIS.hWindow)<>0 AND IsMenu(THIS.hMenu)<>0
		= SendMessage(THIS.hWindow, WM_COMMAND, m.nCommand, 0)
		DOEVENTS
	ENDIF

HIDDEN PROCEDURE FindMainWindow
* finds Adobe Acrobat main window
	THIS.hWindow = FindWindow(ACROBAT_WINCLASS, Null)
	THIS.hMenu = GetMenu(THIS.hWindow)

HIDDEN FUNCTION GetWinText(hWindow)
* returns caption for a given window handle
	LOCAL nBufsize, cBuffer
	nBufsize = 250
	cBuffer = REPLICATE(CHR(0), nBufsize)
	nBufsize = GetWindowText(hWindow, @cBuffer, nBufsize)
RETURN IIF(nBufsize=0, "", LEFT(cBuffer, nBufsize))

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetMenu IN user32 INTEGER hWindow
	DECLARE INTEGER GetSubMenu IN user32 INTEGER hMenu, INTEGER nPos
	DECLARE INTEGER GetMenuItemID IN user32 INTEGER hMenu, INTEGER nPos
	DECLARE INTEGER GetMenuItemCount IN user32 INTEGER hMenu
	DECLARE SwitchToThisWindow IN user32 INTEGER hWindow, INTEGER fAltTab
	DECLARE INTEGER IsMenu IN user32 INTEGER hMenu
	DECLARE INTEGER IsWindow IN user32 INTEGER hWindow

	DECLARE INTEGER FindWindow IN user32;
		STRING lpClassName, STRING lpWindowName

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hWindow, STRING @lpString, INTEGER cch

	DECLARE INTEGER SendMessage IN user32;
		INTEGER hWindow, INTEGER Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hWindow, STRING lpOperation,;
		STRING lpFile, STRING lpParameters,;
		STRING lpDirectory, INTEGER nShowCmd

ENDDEFINE

DEFINE CLASS AdobeDocument As Session
	filename=""
	windowmenuid=0

PROCEDURE Init(cFilename, nMenuID)
	THIS.filename=cFilename
	THIS.windowmenuid=nMenuID

ENDDEFINE  
```  
***  


## Listed functions:
[FindWindow](../libraries/user32/FindWindow.md)  
[GetMenu](../libraries/user32/GetMenu.md)  
[GetMenuItemCount](../libraries/user32/GetMenuItemCount.md)  
[GetMenuItemID](../libraries/user32/GetMenuItemID.md)  
[GetSubMenu](../libraries/user32/GetSubMenu.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[IsMenu](../libraries/user32/IsMenu.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[SendMessage](../libraries/user32/SendMessage.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  
[SwitchToThisWindow](../libraries/user32/SwitchToThisWindow.md)  

## Comment:
When started, the AcrobatReader creates a window with the class name *AdobeAcrobat*. All pdf documents opened are its child windows with the class name *AcrobatMDIChildWnd*. Use Microsoft Spy++ or a similar tool to find out more.  
  
Once the window class name is known, it is easy to find the process linked to this window and terminate it. This will also terminate all open pdf documents. So it does not help when only one document window is to be closed.  
  
* * *  
It is possible to enumerate all *AcrobatMDIChildWnd*windows currently existing. Yet no such window can be closed by calling the DestroyWindow: *a thread cannot use DestroyWindow to destroy a window created by a different thread*.   
  
Acrobat document window closes upon receiving a special window message:  
```foxpro
PostMessage(hDocument, WM_SYSCOMMAND, SC_CLOSE, 0)
```
where *hDocument* is the handle for a document window parented by the main Acrobat window.  
  
* * *  
Finally, I decided to go through using the Acrobat`s menu. First I obtained identifiers for several submenu popups and menu items, like *Close All, Exit, File, Window* etc. For that I used program code similar to [Reading structure of a menu attached to the main VFP window](sample_337.md) code sample.  
  
Once the identifier for a menu item is known, it is simple to create a virtual click on this item without even moving the mouse:   
```foxpro
= SendMessage(hWindow, WM_COMMAND, nMenuItemID, 0)
```

where *hWindow* is the main Acrobat window handle, and *nMenuItemID* is a menu item`s identifier. For example, identifier 6026 is assigned to *File - Exit* menu item.  
  
* * *  
An article called [A simple wrapper to control Acrobat Reader from your application](https://www.codeproject.com/articles/8763/a-simple-wrapper-to-control-acrobat-reader-from-yo) written by *seasidetech* explains how to use selected DDE messages to control the reader from outside.  
  
* * *  
If AdobeAcrobat settings are configured to display each PDF document in a separate window, then all document windows are created with window class AcrobatSDIWindow. Which means the code sample will not work, since it searches windows with AdobeAcrobat class name.  
  
Still this approach will work after reshaping the code, because each SDI window has a menu that can be reached through SendMessage calls.  
  
Menu IDs in the Adobe Reader 8.1 seem to be different from those used in previous versions, which prevents the code sample from working properly with the newer Adobe Reader version.  
  
* * *  
In Acrobat Reader 9 the class of the main window is "AcrobatSDIWindow", not "AdobeAcrobat" anymore. The number of open windows of this class corresponds to the the number of  PDF documents currently open. Each AcrobatSDIWindow has a separate menu. All main Acrobat windows are aware of  other open Acrobat documents.  
  

  

***  

