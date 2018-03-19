
## Function name : GetKeyNameText
Group: Keyboard Input - Library: user32    
***  


#### The GetKeyNameText function retrieves a string that represents the name of a key.
***  


## Code examples:
[Reading virtual key status values and key names](../../samples/sample_305.md)  

## Declaration:
```foxpro  
int GetKeyNameText(
	LONG lParam,
	LPTSTR lpString,
	int nSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyNameText IN user32;
	INTEGER   lParam,;
	STRING  @ lpString,;
	INTEGER   nSize
  
```  
***  


## Parameters:
lParam
[in] Specifies the second parameter of the keyboard message (such as WM_KEYDOWN) to be processed.

lpString
[out] Pointer to a buffer that will receive the key name.

nSize
[in] Specifies the maximum length, in TCHAR, of the key name, including the terminating null character.  
***  


## Return value:
If the function succeeds, a null-terminated string is copied into the specified buffer, and the return value is the length of the string, in TCHAR, not counting the terminating null character.   
***  

