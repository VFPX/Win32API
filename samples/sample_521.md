[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to hot-track menu item selection in top-level form (requires VFP9)

## Short description:
This code shows how VFP top-level form can get notified upon its menu item selection. Note that the menu item is not clicked on, but selected by the mouse hovering over it or by the keyboard.  
***  


## Before you begin:
This code shows how VFP top-level form can get notified upon its menu item selection. Note that the menu item is not clicked on, but selected by the mouse hovering over it or by the keyboard.  

![](../images/menuhottracking.png)  
The label changes upon menu item selection.  

See also:

* [Reading the structure of VFP main menu](sample_337.md)  
* [Transparent Menu on top-level form](sample_496.md)  
* [Adding user-defined items to the Control Menu of VFP form](sample_512.md)  

  
***  


## Code:
```foxpro  
LOCAL oForm As Tform
oForm = CREATEOBJECT("Tform")
oForm.Visible=.T.
READ EVENTS
* end of main
	
DEFINE CLASS Tform As Form
#DEFINE GWL_WNDPROC -4
#DEFINE WM_DRAWITEM 0x002B
#DEFINE WM_COMMAND 0x0111
#DEFINE WM_MENUSELECT 0x011F
#DEFINE WM_ENTERMENULOOP 0x0211
#DEFINE WM_EXITMENULOOP 0x0212
#DEFINE WM_INITMENU 0x0116
#DEFINE WM_INITMENUPOPUP 0x0117
#DEFINE WM_UNINITMENUPOPUP 0x0125

#DEFINE ODA_DRAWENTIRE 1
#DEFINE ODA_SELECT 2

#DEFINE ODS_SELECTED 1
#DEFINE ODS_GRAYED 2
#DEFINE ODS_DISABLED 4
#DEFINE ODS_NOACCEL 0x100

PROTECTED hOrigProc, hWindow
	hOrigProc=0
	hWindow=0
	Width=500
	Height=450
	Autocenter=.T.
	ShowWindow=2
	Caption="Tracking item selection in VFP menu"

	ADD OBJECT lblCaption As Label WITH Left=10, Top=370,;
		FontName="Arial", FontSize=18, FontBold=.T.,;
		Autosize=.T., BackStyle=0, Caption=""

PROCEDURE Init
	THIS.declare
	THIS.DefineMenu
	THIS.ShowNotSelected

PROCEDURE Destroy
	THIS.ReleaseHook
	CLEAR EVENTS

PROCEDURE Activate
	IF THIS.hWindow = 0
		THIS.SetHook
        SetForegroundWindow(THIS.hWindow)
	ENDIF

PROCEDURE OnWindowProc(hWindow as Integer, nMsgID as Integer,;
	wParam as Integer, lParam as Integer)

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID=WM_DRAWITEM
		THIS.OnDrawItem(m.lParam)
	CASE nMsgID=WM_INITMENUPOPUP
	CASE nMsgID=WM_UNINITMENUPOPUP
	CASE nMsgID=WM_ENTERMENULOOP
	CASE nMsgID=WM_EXITMENULOOP
		THIS.ShowNotSelected
	ENDCASE

	* pass control to the original window procedure
	nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
		m.nMsgID, m.wParam, m.lParam)

RETURN m.nReturn

PROCEDURE OnDrawItem(hDrawItemStruct as Integer)
	LOCAL cBuffer, nItemId, nItemAction, nItemState,;
		hItemData, cItemData, nCaptionLen, cCaption,;
		lSelected, lDisabled, lGrayed, lPopup

	cBuffer = REPLICATE(CHR(0),48)
	= MemToStr(@cBuffer, hDrawItemStruct, LEN(cBuffer))
	
	* menu item id
	nItemId = buf2dword(SUBSTR(cBuffer,9,4))

	* drawing action required: ODA_ constants
	nItemAction = buf2dword(SUBSTR(cBuffer,13,4))

	* visual state of the item: ODS_ constants
	nItemState = buf2dword(SUBSTR(cBuffer,17,4))
	
	* the menu item is selected
	lSelected = (BITAND(nItemAction, ODA_SELECT) <> 0);
		AND (BITAND(nItemState, ODS_SELECTED) <> 0)

	* the menu item is disabled
	lDisabled = (BITAND(nItemState, ODS_DISABLED) <> 0)

	* the menu item is grayed
	lGrayed = (BITAND(nItemState, ODS_GRAYED) <> 0)

	* pointer to application-defined value, which is a standard structure
	* allocated by Visual FoxPro for each menu item
	hItemData = buf2dword(SUBSTR(cBuffer,45,4))
	
	IF hItemData = 0
		cCaption = ""
	ELSE
	* parse the structure to obtain find out:
	* - the menu item caption
	* - whether this is an item or a popup

		* read first four DWORDs from the buffer
		cItemData = REPLICATE(CHR(0), 16)
		= MemToStr(@cItemData, hItemData, LEN(cItemData))

		* the menu item is popup
		lPopup = (buf2dword(SUBSTR(cItemData, 13,4)) <> 0)

		nCaptionLen = buf2dword(SUBSTR(cItemData, 5,4)) * 2

		* read complete buffer including the menu item caption
		cItemData = REPLICATE(CHR(0), 16 + nCaptionLen)
		= MemToStr(@cItemData, hItemData, LEN(cItemData))
		
		* retrieve the menu item caption
		cCaption = STRCONV(SUBSTR(cItemData,;
			buf2dword(SUBSTR(cItemData, 9, 4)) - hItemData + 1,;
			nCaptionLen), 6)
	ENDIF
	
	IF lSelected
		THIS.lblCaption.Caption = m.cCaption + IIF(lPopup, " >", "")
		THIS.lblCaption.ForeColor = IIF(m.lGrayed, RGB(128,128,128), 0)
	ENDIF

PROCEDURE ShowNotSelected
	THIS.lblCaption.Caption = "Select Menu Item"
	THIS.lblCaption.ForeColor = RGB(0,0,196)

PROCEDURE SetHook
	THIS.hWindow=THIS.HWnd
	THIS.hOrigProc = GetWindowLong(THIS.hWindow, GWL_WNDPROC)

	= BINDEVENT(THIS.hWindow, WM_DRAWITEM, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_INITMENUPOPUP, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_COMMAND, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_MENUSELECT, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_ENTERMENULOOP, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_EXITMENULOOP, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_INITMENU, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_UNINITMENUPOPUP, THIS, "OnWindowProc")

PROCEDURE ReleaseHook
	= UNBINDEVENTS(THIS.hWindow)
	THIS.hOrigProc=0

PROTECTED PROCEDURE declare
	DECLARE INTEGER SetForegroundWindow IN user32;
		INTEGER hWindow

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

	DECLARE INTEGER CallWindowProc IN user32;
		INTEGER lpPrevWndFunc, INTEGER hWindow, LONG Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @Dest, INTEGER Src, INTEGER nLength

PROTECTED PROCEDURE DefineMenu
	DEFINE MENU SampleMenu BAR IN WINDOW (THISFORM.Name)

	DEFINE PAD p1 OF SampleMenu PROMPT "File"
	DEFINE PAD pp OF SampleMenu PROMPT "Reports"
	DEFINE PAD p2 OF SampleMenu PROMPT "Tools"
	DEFINE PAD p3 OF SampleMenu PROMPT "Window"
	DEFINE PAD p4 OF SampleMenu PROMPT "Help"

	ON PAD p1 OF SampleMenu ACTIVATE POPUP _MSM_FILE
	ON PAD pp OF SampleMenu ACTIVATE POPUP popupReports
	ON PAD p2 OF SampleMenu ACTIVATE POPUP _MSM_TOOLS
	ON PAD p3 OF SampleMenu ACTIVATE POPUP _MSM_WINDO
	ON PAD p4 OF SampleMenu ACTIVATE POPUP _MSM_SYSTM

	DEFINE POPUP popupReports MARGIN RELATIVE SHADOW COLOR SCHEME 4
	DEFINE BAR 1 OF popupReports PROMPT "Production"
	DEFINE BAR 2 OF popupReports PROMPT "Accounting"
	DEFINE BAR 3 OF popupReports PROMPT "HR"
	ON BAR 1 OF popupReports ACTIVATE POPUP popupProduction
	ON BAR 3 OF popupReports ACTIVATE POPUP hr

	DEFINE POPUP popupProduction MARGIN RELATIVE SHADOW COLOR SCHEME 4
	DEFINE BAR 0x0A0A OF popupProduction PROMPT "Daily"
	DEFINE BAR 2 OF popupProduction PROMPT "Weekly"
	DEFINE BAR 3 OF popupProduction PROMPT "Monthly"
	ON BAR 0x0A0A OF popupProduction ACTIVATE POPUP daily

	DEFINE POPUP daily MARGIN RELATIVE SHADOW COLOR SCHEME 4
	DEFINE BAR 1 OF daily PROMPT "Orders received"
	DEFINE BAR 2 OF daily PROMPT "Pre-shipping list"
	DEFINE BAR 3 OF daily PROMPT "Orders Shipped"

	DEFINE POPUP hr MARGIN RELATIVE SHADOW COLOR SCHEME 4
	DEFINE BAR 1 OF hr PROMPT "Attendance"
	DEFINE BAR 2 OF hr PROMPT "Attendance by departments"

	ACTIVATE MENU SampleMenu NOWAIT

ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[CallWindowProc](../libraries/user32/CallWindowProc.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[SetForegroundWindow](../libraries/user32/SetForegroundWindow.md)  

## Comment:
The BINDEVENT() is used to intercept WM_DRAWITEM messages. This message is sent to the form each time when a menu item is about to be redrawn. The *lpDrawItem* parameter passed with this message points to the <a href="http://www.google.com/search?q=DRAWITEMSTRUCT">DRAWITEMSTRUCT</a> structure.  
  
```cpp
typedef struct tagDRAWITEMSTRUCT {  
    UINT CtlType;  
    UINT CtlID;  
    UINT itemID;  
    UINT itemAction;  
    UINT itemState;  
    HWND hwndItem;  
    HDC hDC;  
    RECT rcItem;  
    ULONG_PTR itemData;  
} DRAWITEMSTRUCT;
```

Read the DRAWITEMSTRUCT structure to find out whether the item is selected or unselected, enabled or disabled and more. The last member points at application-defined value associated with the menu item. This application-defined value seems to be another structure (VFP undocumented) having at least four members.  
  
```cpp
typedef struct VFPMenuItem {  
    DWORD Signature;  
    DWORD CaptionLength;  
    LPWSTR Caption;  
    DWORD PopupId;  
}
```

 
*Signature*  
A constant value; so far I have nothing more on this member.  
  
*CaptionLength*  
The length of the menu item caption.  
  
*Caption*  
Pointer to Unicode string containing the caption of the menu item.  
  
*PopupId*  
For popups, this member contains a sort of Id.  
  
This structure can be also accessed by calling the GetMenuItemInfo and parsing *dwItemData* member of the MENUITEMINFO structure it populates.  
  
***  

