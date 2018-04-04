[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShellAbout
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Displays a Shell About dialog box
***  


## Declaration:
```foxpro  
int ShellAbout (
	HWND    hWnd,         // handle of parent window
	LPCTSTR szApp,        // title bar and first line text
	LPCTSTR szOtherStuff, // other dialog text
	HICON   hIcon         // icon to display
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShellAbout IN shell32;
	INTEGER hwnd,;
	STRING  szApp,;
	STRING  szOtherStuff,;
	INTEGER hIcon  
```  
***  


## Parameters:
hWnd
Identifies a parent window

szApp
Points to text that the function displays in the title bar of the Shell About dialog box

szOtherStuff
Points to text that the function displays in the dialog box after the version and copyright information

hIcon
Identifies an icon that the function displays in the dialog box  
***  


## Return value:
If the function succeeds in displaying the dialog box, the return value is TRUE  
***  

