*|==============================================================
*|    FoxTray.ocx
*|    A sample ActiveX control: using System Tray icon and menu 
*|    in VFP applications
*|
*|    August 2002
*|
*|    http://www.news2news.com/vfp/?example=336
*|==============================================================

+---------------+
|      File     |
+---------------+
FoxTray.ocx


+---------------+
|  OLE Class    |
+---------------+
FoxTrayCtl.cFoxTray


+----------------------------------+
| Register the class before using  |
+----------------------------------+
REGSVR32 FoxTray.ocx
Use full path to FoxTray.ocx

+----------------------------------+
|  Public Properties of the class  |
+----------------------------------+
STRING IconSource
Read-write; *.ICO file name

STRING IconTip
Read-write, icon tip text


+----------------------------------+
|    Public Methods of the class   |
+----------------------------------+
VOID ShowIcon
Shows an icon in the Windows System Tray. Displays ICO file stored in the IconSource property or default application icon.

VOID HideIcon
Hides the icon in the Windows System Tray.

POPUPITEM GetPopupItem (LONG Index)
Returns a reference to the POPUPITEM object, in this version the Index range is from 1 to 5.
Read-write properties for the POPUPITEM object:
   - CHAR caption
   - BOOL separator
   - BOOL enabled
   - BOOL visible


+---------------+
|    Events     |
+---------------+
BeforePopupActivate(BOOL Result)
Occurs after LeftMouseClick on the icon before popup activation. Set Result to false to cancel popup activation.

OnPopupItemSelected(LONG Item, CHAR Caption)
Occurs after a popup item selection. Contains an order -- from 1 to 5 (only 5 items available in this version), and caption for the selected item.

+--------------------+
|    VB6 Project     |
+--------------------+
mDecl.bas
mFoxTray.bas
cPopup.cls
cPopItem.cls
cFoxTray.ctl
FoxTray.vbp
FoxTray.vbw

+---------------+
|    Author     |
+---------------+
1361529 Ontario, Inc. (News2News)
Anatoliy Mogylevets
devicecontext@msn.com


+---------------+
|    Links      |
+---------------+
http://www.news2news.com/vfp/?example=336
http://fox.wikis.com/wc.dll?Wiki~Win32Api_Shell_NotifyIcon~VFP
http://support.microsoft.com/default.aspx?scid=kb;EN-US;Q162613
http://support.microsoft.com/default.aspx?scid=kb;EN-US;Q149276
http://support.microsoft.com/default.aspx?scid=kb;EN-US;Q177095
