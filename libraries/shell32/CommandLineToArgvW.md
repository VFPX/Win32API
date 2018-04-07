[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CommandLineToArgvW
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Parses a Unicode command-line string, and returns a pointer to a set of Unicode argument strings and a count of arguments, similar to the standard C run-time argv and argc values
***  


## Code examples:
[Converting command-line string to a set of Unicode argument strings](../../samples/sample_212.md)  

## Declaration:
```foxpro  
LPWSTR * CommandLineToArgvW(
  LPCWSTR lpCmdLine,  // pointer to a command-line string
  int *pNumArgs       // receives the argument count
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CommandLineToArgvW IN shell32;
	INTEGER   lpCmdLine,;
	INTEGER @ pNumArgs  
```  
***  


## Parameters:
lpCmdLine 
[in] Pointer to a null-terminated Unicode command-line string. 

pNumArgs 
[out] Pointer to an integer variable that receives the count of arguments parsed. 
  
***  


## Return value:
If the function succeeds, the return value is a non-NULL pointer to the constructed argument list, which is an array of Unicode strings. 

If the function fails, the return value is NULL.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
MSDN: if the first parameter is the empty string, "", the function returns the path to the current executable file.   
  
See also: [GetCommandLine](../kernel32/GetCommandLine.md).  
  
***  

