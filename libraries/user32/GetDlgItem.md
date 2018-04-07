[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDlgItem
Group: [Dialog Box](../../functions_group.md#Dialog_Box)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a handle to a control in the specified dialog box. 
***  


## Declaration:
```foxpro  
HWND GetDlgItem(
	HWND hDlg,
	int nIDDlgItem
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDlgItem IN user32;
	INTEGER hDlg,;
	INTEGER nIDDlgItem  
```  
***  


## Parameters:
hDlg
[in] Handle to the dialog box that contains the control. 

nIDDlgItem
[in] Specifies the identifier of the control to be retrieved.   
***  


## Return value:
If the function succeeds, the return value is the window handle of the specified control.  
***  


## Comments:
See also: [SetDlgItemText](../user32/SetDlgItemText.md), [GetDlgCtrlID](../user32/GetDlgCtrlID.md).  
  
***  

