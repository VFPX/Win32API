[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : TaskDialog
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comctl32](../../Libraries.md#comctl32)  
***  


#### Creates, displays, and operates a task dialog.
***  


## Code examples:
[How to display a Task Dialog (Vista)](../../samples/sample_557.md)  
[How to display advanced Task Dialog (Vista)](../../samples/sample_558.md)  

## Declaration:
```foxpro  
HRESULT TaskDialog(
	HWND hWndParent,
	HINSTANCE hInstance,
	PCWSTR pszWindowTitle,
	PCWSTR pszMainInstruction,
	PCWSTR pszContent,
	TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons,
	PCWSTR pszIcon,
	int *pnButton
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER TaskDialog IN comctl32;
	INTEGER hWndParent,;
	INTEGER hInstance,;
	STRING pszWindowTitle,;
	STRING pszMainInstruction,;
	STRING pszContent,;
	INTEGER dwCommonButtons,;
	INTEGER pszIcon,;
	INTEGER @pnButton  
```  
***  


## Parameters:
hWndParent
[in] Handle to the owner window of the task dialog to be created.

hInstance
[in] Handle to the module that contains the icon resource identified by the pszIcon member, and the string resources identified by the pszWindowTitle and pszMainInstruction members.

pszWindowTitle
[in] Pointer to the string to be used for the task dialog title.

pszMainInstruction
[in] Pointer to the string to be used for the main instruction.

pszContent
[in] Pointer to a string used for additional text that appears below the main instruction, in a smaller font.

dwCommonButtons
[in] Specifies the push buttons displayed in the dialog box. 

pszIcon
[in] Pointer to a string that identifies the icon to display in the task dialog.

pnButton
[out] 
When this function returns, contains either 0 (on error) or Id of the pressed button.  
***  


## Return value:
On success returns S_OK (0).  
***  


## Comments:
Minimum operating systems: <Em>Windows Vista</Em>  
  
All strings passed to this function must be in <Em>Unicode</Em> format.  
  
The task dialog contains application-defined message text and title, icons, and any combination of predefined push buttons.  

![](../../images/taskdlg_sample.png)  

See also: [TaskDialogIndirect](../comdlg32/TaskDialogIndirect.md), [MessageBox](../user32/MessageBox.md), [MessageBoxIndirect](../user32/MessageBoxIndirect.md).  
  
***  

