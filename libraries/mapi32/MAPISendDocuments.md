[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPISendDocuments
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
***  


#### The MAPISendDocuments function sends a standard message with one or more attached files and a cover note. 
***  


## Code examples:
[Sending a standard message with one or more attached files using default email client](../../samples/sample_273.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPISendDocuments(
  ULONG ulUIParam,
  LPTSTR lpszDelimChar,
  LPTSTR lpszFullPaths,
  LPTSTR lpszFileNames,
  ULONG ulReserved
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPISendDocuments IN mapi32;
	INTEGER ulUIParam,;
	STRING  lpszDelimChar,;
	STRING  lpszFullPaths,;
	STRING  lpszFileNames,;
	INTEGER ulReserved  
```  
***  


## Parameters:
ulUIParam 
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. 

lpszDelimChar 
[in] Pointer to a character that the caller uses to delimit the names pointed to by the lpszFullPaths and lpszFileNames parameters. 

lpszFullPaths 
[in] Pointer to a string containing a list of full paths (including drive letters) to attachment files. 

lpszFileNames 
[in] Pointer to a null-terminated list of the original filenames as they should appear in the message. 

ulReserved 
Reserved; must be zero.   
***  


## Return value:
If the call succeeded and the message was sent the function returns SUCCESS_SUCCESS, otherwise this is an error code.  
***  

