[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetDlgItemText
Group: [Dialog Box](../../functions_group.md#Dialog_Box)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetDlgItemText function sets the title or text of a control in a dialog box. 
***  


## Code examples:
[Extended MessageBox Class](../../samples/sample_418.md)  

## Declaration:
```foxpro  
BOOL SetDlgItemText(
	HWND hDlg,
	int nIDDlgItem,
	LPCTSTR lpString
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetDlgItemText IN user32;
	INTEGER hDlg,;
	INTEGER nIDDlgItem,;
	STRING  lpString
  
```  
***  


## Parameters:
hDlg
[in] Handle to the dialog box that contains the control. 

nIDDlgItem
[in] Specifies the control with a title or text to be set. 

lpString
[in] Pointer to the null-terminated string that contains the text to be copied to the control.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

