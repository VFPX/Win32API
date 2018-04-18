[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Transparent Menu Class (requires VFP9)

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Short description:
The SetLayeredWindowAttributes function sets the opacity and transparency color key of a layered window. All menu popups are layered windows, so this technique can be applied to them.  
***  


## Before you begin:
The SetLayeredWindowAttributes function sets the opacity and the transparency color key of a layered window. Find an example of using this function in [Semi-transparent Form](sample_453.md) code sample in this reference.  

All menu popups are layered windows, which makes this technique applicable to them.  

All VFP menus are [owner-draw menus](http://msdn.microsoft.com/en-us/library/bb756947.aspx). The WM_DRAWITEM message is sent to the parent window of an owner-drawn menu when its visual aspect has changed. Through this message the window procedure obtains a pointer to the <a href="http://msdn.microsoft.com/en-us/library/bb775802(v=vs.85).aspx">DRAWITEMSTRUCT structure</a>.  

This structure contains the hDC for a menu popup window. Pass this hDC to the WindowFromDC function to obtain the window handle (HWND) for the menu pop window.  

In VFP9, BINDEVENT() function can intercept Windows messages including the WM_DRAWITEM. Thus a VFP application can be notified whenever any menu popup is redrawn. So the application can intervene and make a popup window transparent or semi-transparent.  

![](../images/transparentmenu.jpg)  

To test the MenuManager class, copy the code sample to MenuManager.prg and type in the Command Window:  
 
```foxpro
oManager = NEWOBJECT("MenuManager", "MenuManager.prg")  
oManager.SetHook(Application.hWnd)  && VFP9 required
```
After that the VFP System Menu will show semi-transparent. Release the MenuManager object to return the menu back to its normal state.  

See also:

* [Testing Transparent Menu Class with top-level form](sample_497.md)  
* [How to hot-track menu item selection in top-level form](sample_521.md)  
* [Adding user-defined items to the Control Menu of VFP form](sample_512.md)  
* [Reading structure of a menu attached to the main VFP window](sample_337.md)  
* [Semi-transparent Form](sample_453.md)  
* [How to draw a custom Window Caption on FoxPro form](sample_499.md)  

  
***  


## Code:
```foxpro  
#DEFINE GWL_WNDPROC -4
#DEFINE GWL_EXSTYLE -20
#DEFINE WS_EX_LAYERED 0x80000
#DEFINE LWA_COLORKEY 1
#DEFINE LWA_ALPHA 2
#DEFINE WM_DRAWITEM 0x002B
#DEFINE WM_COMMAND 0x0111
#DEFINE WM_MENUSELECT 0x011F
#DEFINE WM_ENTERMENULOOP 0x0211
#DEFINE WM_EXITMENULOOP 0x0212
#DEFINE WM_INITMENU 0x0116
#DEFINE WM_INITMENUPOPUP 0x0117
#DEFINE WM_UNINITMENUPOPUP 0x0125

DEFINE CLASS MenuManager As Relation
PROTECTED hOrigProc, hWindow, TransparentColor,;
	AlphaOpacity, LayeredWindowFlags, LastHDC
	hOrigProc=0
	hWindow=0
	LastHDC=0
	TransparentColor=0
	AlphaOpacity=192
	LayeredWindowFlags=LWA_ALPHA

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	THIS.ReleaseHook

PROCEDURE SetHook(hWindow)
	THIS.ReleaseHook
	THIS.hWindow = m.hWindow
	THIS.hOrigProc = GetWindowLong(THIS.hWindow, GWL_WNDPROC)

	* these two are really important
	= BINDEVENT(THIS.hWindow, WM_DRAWITEM, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_INITMENUPOPUP, THIS, "OnWindowProc")

	* the following messages are trapped for debug purposes only
	= BINDEVENT(THIS.hWindow, WM_COMMAND, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_MENUSELECT, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_ENTERMENULOOP, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_EXITMENULOOP, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_INITMENU, THIS, "OnWindowProc")
	= BINDEVENT(THIS.hWindow, WM_UNINITMENUPOPUP, THIS, "OnWindowProc")

PROCEDURE ReleaseHook
	= UNBINDEVENTS(THIS.hWindow)
	THIS.hOrigProc=0

PROCEDURE OnWindowProc(hWindow as Integer, nMsgID as Integer,;
	wParam as Integer, lParam as Integer)

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID=WM_DRAWITEM
		THIS.OnMenuDraw(m.lParam)

	CASE nMsgID=WM_INITMENUPOPUP
	* drop-down menu or submenu is about to become active
		THIS.LastHDC=0
	
	ENDCASE

	* pass control to the original window procedure
	nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
		m.nMsgID, m.wParam, m.lParam)

RETURN m.nReturn

PROCEDURE OnMenuDraw(hDrawItemStruct)
	LOCAL cBuffer, nItemAction, hDC, hPopupWindow

	* copy DRAWITEMSTRUCT from memory address to VFP string
	cBuffer = REPLICATE(CHR(0),48)  && size of DRAWITEMSTRUCT
	= MemToStr(@cBuffer, hDrawItemStruct, LEN(cBuffer))

	* obtain device context for this menu popup window
	hDC = buf2dword(SUBSTR(cBuffer,25,4))

	IF THIS.LastHDC <> m.hDC
	* no need to be done for every WM_DRAWITEM trapped
		THIS.LastHDC = m.hDC
		hPopupWindow = WindowFromDC(m.hDC)

		* change the extended window style to enable
		* opacity/transparency for the popup window
		= SetWindowLong(m.hPopupWindow, GWL_EXSTYLE,;
			BITOR(GetWindowLong(hPopupWindow,;
			GWL_EXSTYLE), WS_EX_LAYERED))

		* set the opacity and transparency color key
		* for the popup window
		= SetLayeredWindowAttributes(m.hPopupWindow,;
			THIS.TransparentColor,;
			THIS.AlphaOpacity,;
			THIS.LayeredWindowFlags)
	ENDIF

PROCEDURE GetLayeredWindowFlags() As Number
RETURN THIS.LayeredWindowFlags

PROCEDURE EnableTransparentColor(nRgb As Number)
	THIS.LayeredWindowFlags =;
		BITOR(THIS.LayeredWindowFlags,LWA_COLORKEY)
	IF VARTYPE(m.nRgb)="N"
		THIS.TransparentColor=m.nRgb
	ENDIF

PROCEDURE DisableTransparentColor
	THIS.LayeredWindowFlags =;
		BITXOR(THIS.LayeredWindowFlags,LWA_COLORKEY)

PROCEDURE SetTransparentColor(nRgb As Number)
	THIS.TransparentColor=m.nRgb

FUNCTION GetTransparentColor() As Number
RETURN THIS.TransparentColor

PROCEDURE EnableAlphaOpacity(nAlpha As Number)
	THIS.LayeredWindowFlags =;
		BITOR(THIS.LayeredWindowFlags,LWA_ALPHA)
	IF VARTYPE(m.nAlpha)="N"
		THIS.AlphaOpacity=m.nAlpha
	ENDIF

PROCEDURE DisableAlphaOpacity
	THIS.LayeredWindowFlags =;
		BITXOR(THIS.LayeredWindowFlags,LWA_ALPHA)

PROCEDURE SetAlphaOpacity(nAlpha As Number)
	THIS.AlphaOpacity=m.nAlpha

FUNCTION GetAlphaOpacity() As Number
RETURN THIS.AlphaOpacity

PROCEDURE declare
	DECLARE INTEGER WindowFromDC IN user32 INTEGER hDC

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

	DECLARE INTEGER SetWindowLong IN user32;
		INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong

	DECLARE INTEGER CallWindowProc IN user32;
		INTEGER lpPrevWndFunc, INTEGER hWindow, LONG Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @Dest, INTEGER Src, INTEGER nLength

	DECLARE INTEGER SetLayeredWindowAttributes IN user32;
		INTEGER hWindow, INTEGER crKey,;
		SHORT bAlpha, INTEGER dwFlags

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
[SetLayeredWindowAttributes](../libraries/user32/SetLayeredWindowAttributes.md)  
[SetWindowLong](../libraries/user32/SetWindowLong.md)  
[WindowFromDC](../libraries/user32/WindowFromDC.md)  

## Comment:
Transparency settings (*crKey* and *bAlpha* parameters in SetLayeredWindowAttributes call) should be carefully picked to ensure menu readability.  
  
Menu related Windows messages:  
WM_ENTERMENULOOP  
WM_INITMENU  
WM_MENUSELECT  
WM_INITMENUPOPUP  
WM_DRAWITEM  
WM_UNINITMENUPOPUP  
WM_COMMAND  
WM_EXITMENULOOP  
WM_ENTERIDLE  
WM_SYSCOMMAND  
  
* * *  

Several third-party Menu Builders -- <a href="http://fox.wikis.com/wc.dll?Wiki~VFEMenuBuilder">VFXMenuBuilder</a>, <a href="http://fox.wikis.com/wc.dll?Wiki~VFEMenuBuilder">VFEMenuBuilder</a>, <a href="http://fox.wikis.com/wc.dll?Wiki~VMPMenuBuilder">VMPMenuBuilder</a> and more probably coming -- all implement object-oriented menus.  
  
* * *  
<!-- Anatoliy -->
<a href="?solution=4&src=x496" style="color:#008000;">ContextMenu Control</a>

Designed for generating and displaying shortcut menus on VFP forms. A generated menu is object-oriented: menu items are accessible during runtime, can be modified, added and deleted. A menu can be exported to XML string, as well as loaded from a XML string.  
<a href="?solution=4&src=x496img"><img style="margin-top:10px;" src="http://www.news2news.com/vfp/solutions/images/context_menu/contextmenu_sample_green.png" border="0"></a>  
  
***  
 

