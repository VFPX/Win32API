<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RestartDialog
Group: Shell Functions - Library: shell32    
***  


#### Displays a dialog box that prompts the user to restart Microsoft® Windows®. When the user clicks the button, the function calls ExitWindowsEx to attempt to restart Windows.
***  


## Code examples:
[Using the RestartDialog function -- restarting Windows](../../samples/sample_361.md)  

## Declaration:
```foxpro  
int RestartDialog(
	HWND hParent,
	LPCWSTR pszPrompt,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RestartDialog IN shell32;
	INTEGER hParent,;
	STRING  pszPrompt,;
	LONG    dwFlags
  
```  
***  


## Parameters:
```txt  
hParent
[in] A handle to the parent window.

pszPrompt
[in] A NULL-terminated Unicode string that contains the text that displays in the dialog box which prompts the user.

dwFlags
[in] Flags that specifies the type of shutdown.  
```  
***  


## Return value:
Returns the identifier of the button that was pressed to close the dialog box.
  
***  

