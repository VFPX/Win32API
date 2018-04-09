[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShowHTMLDialog
Group: [MSHTML Reference](../../functions_group.md#MSHTML_Reference)  -  Library: [mshtml](../../Libraries.md#mshtml)  
***  


#### Creates a modal dialog box that displays HTML.
***  


## Code examples:
[Yet another modal dialog: now HTML-based](../../samples/sample_561.md)  

## Declaration:
```foxpro  
HRESULT ShowHTMLDialog(
	HWND hwndParent,
	IMoniker *pMk,
	VARIANT *pvarArgIn,
	LPWSTR pchOptions,
	VARIANT *pvarArgOut
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShowHTMLDialog IN mshtml;
	INTEGER hwndParent,;
	INTEGER pMk,;
	STRING pvarArgIn,;
	STRING pchOptions,;
	STRING @pvarArgOut  
```  
***  


## Parameters:
hwndParent
A handle to the parent of the dialog box.

pMk
The address of an IMoniker interface from which the HTML for the dialog box is loaded.

pvarArgIn
The address of a VARIANT structure that contains the input data for the dialog box. This parameter can be NULL.

pchOptions
[in] The address of a VARIANT structure that contains the window ornaments for the dialog box. This parameter can be NULL.

pvarArgOut
The address of a VARIANT structure that contains the output data for the dialog box. This parameter can be NULL.  
***  


## Return value:
Returns S_OK (0) if successful, or an error value otherwise.  
***  


## Comments:
This is yet another modal dialog functionally similar to the dialogs created by calling the MessageBox or the TaskDialog.  
  
![](../../images/htmlmodaldlg.png)

A very attractive feature of this dialog is its HTML-defined content. In other words, the whole client part of the dialog is described in HTML terms. This is like a miniature IE window.  
  
See also: [CreateURLMonikerEx](../urlmon/CreateURLMonikerEx.md), [MessageBox](../user32/MessageBox.md), [MessageBoxIndirect](../user32/MessageBoxIndirect.md), [TaskDialog](../comctl32/TaskDialog.md), [TaskDialogIndirect](../comdlg32/TaskDialogIndirect.md).  
  
***  

