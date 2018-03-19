
## Function name : SetConsoleTitle
Group: Console - Library: kernel32    
***  


#### The SetConsoleTitle function sets the title bar string for the current console window.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL SetConsoleTitle(
  LPCTSTR lpConsoleTitle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetConsoleTitle IN kernel32;
	STRING lpConsoleTitle  
```  
***  


## Parameters:
lpConsoleTitle 
[in] Pointer to a null-terminated string that contains the string to be displayed in the title bar of the console window.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function uses either Unicode characters or 8-bit characters from the current code page for the console.  
  
See also:  GetConsoleTitle, SetConsoleCP, SetConsoleOutputCP.  
  
***  

