[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MessageBoxIndirect
Group: [Dialog Box](../../functions_group.md#Dialog_Box)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Creates, displays, and operates a message box. The message box contains application-defined message text and title, any icon, and any combination of predefined push buttons.

***  


## Code examples:
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  

## Declaration:
```foxpro  
int MessageBoxIndirect(
	const LPMSGBOXPARAMS lpMsgBoxParams
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MessageBoxIndirect IN user32;
	STRING @lpMsgBoxParams  
```  
***  


## Parameters:
lpMsgBoxParams
[in] Pointer to a MSGBOXPARAMS structure that contains information used to display the message box.   
***  


## Return value:
If the function succeeds, the return value is one of the predefined menu-item values.  
***  

