<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetDlgItem
Group: Dialog Box - Library: user32    
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
```txt  
hDlg
[in] Handle to the dialog box that contains the control.

nIDDlgItem
[in] Specifies the identifier of the control to be retrieved.  
```  
***  


## Return value:
If the function succeeds, the return value is the window handle of the specified control.  
***  


## Comments:
See also: SetDlgItemText, GetDlgCtrlID   
  
***  

