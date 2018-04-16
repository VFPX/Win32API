[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShellExecuteEx
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Performs an action on a file.
***  


## Code examples:
[How to display the Properties dialog box for a file (ShellExecuteEx)](../../samples/sample_320.md)  

## Declaration:
```foxpro  
BOOL ShellExecuteEx(
	LPSHELLEXECUTEINFO lpExecInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShellExecuteEx IN Shell32;
	STRING @lpExecInfo  
```  
***  


## Parameters:
lpExecInfo
Address of a <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/shell/reference/structures/shellexecuteinfo.asp">SHELLEXECUTEINFO</a> structure that contains and receives information about the application being executed.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
<Strong>lpVerb</Strong> in <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/shell/reference/structures/shellexecuteinfo.asp">SHELLEXECUTEINFO</a> Structure:  
String, referred to as a verb, that specifies the action to be performed. The set of available verbs depends on the particular file or folder. Generally, the actions available from an object`s shortcut menu are available verbs.  
  
```foxpro
cBuffer = num2dword(INFO_SIZE) +;  
	num2dword(nFlag) +;  
	num2dword(hWindow) +;  
	num2dword(oVerb.GetAddr()) +;  
	num2dword(oFile.GetAddr()) +;  
	Repli(Chr(0), 40)  
  
= ShellExecuteEx(@cBuffer)
```
The following verbs are commonly used:   
  
<Strong>edit</Strong>  
Launches an editor and opens the document for editing.  
  
<Strong>explore</Strong>  
Explores the folder specified by lpFile.  
  
<Strong>find</Strong>  
Initiates a search starting from the specified directory.  
  
<Strong>open</Strong>  
Opens the file specified by the lpFile parameter. The file can be an executable file, a document file, or a folder.  
  
<Strong>print</Strong>  
Prints the document file specified by lpFile.  
  
<Strong>properties</Strong>  
Displays the file or folder`s properties.  
  
***  

