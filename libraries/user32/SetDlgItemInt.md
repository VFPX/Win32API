[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetDlgItemInt
Group: [Dialog Box](../../functions_group.md#Dialog_Box)  -  Library: [user32](../../Libraries.md#user32)  
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
hDlg
[in] Handle to the dialog box that contains the control. 

nIDDlgItem
[in] Specifies the control to be changed. 

uValue
[in] Specifies the integer value used to generate the item text. 

bSigned
[in] Specifies whether the uValue parameter is signed or unsigned.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

