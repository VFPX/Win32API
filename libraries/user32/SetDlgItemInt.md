<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetDlgItemInt
Group: Dialog Box - Library: user32    
***  


#### The SetDlgItemInt function sets the text of a control in a dialog box to the string representation of a specified integer value. 
***  


## Declaration:
```foxpro  
BOOL SetDlgItemInt(
	HWND hDlg,
	int nIDDlgItem,
	UINT uValue,
	BOOL bSigned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetDlgItemInt IN user32;
	INTEGER hDlg,;
	INTEGER nIDDlgItem,;
	INTEGER uValue,;
	INTEGER bSigned
  
```  
***  


## Parameters:
```txt  
hDlg
[in] Handle to the dialog box that contains the control.

nIDDlgItem
[in] Specifies the control to be changed.

uValue
[in] Specifies the integer value used to generate the item text.

bSigned
[in] Specifies whether the uValue parameter is signed or unsigned.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

