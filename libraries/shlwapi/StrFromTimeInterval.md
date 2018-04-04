[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrFromTimeInterval
Group: [String](../../functions_group.md#String)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Converts a time interval, specified in milliseconds, to a string.
***  


## Code examples:
[Time in milliseconds represented as string (e.g. 1 hour 24 min 36 sec)](../../samples/sample_105.md)  

## Declaration:
```foxpro  
int StrFromTimeInterval(
    LPTSTR pszOut,
    UINT cchMax,
    DWORD dwTimeMS,
    int digits
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrFromTimeInterval IN Shlwapi;
	STRING @ pszOut,;
   	INTEGER  cchMax,;
   	INTEGER  dwTimeMS,;
	INTEGER  digits  
```  
***  


## Parameters:
pszOut 
[out] Pointer to a character buffer that receives the converted string. 

cchMax 
[in] Size of pszOut, in characters. If cchMax is set to zero, StrFromTimeInterval will return the minimum size of the character buffer needed to hold the converted string. In this case, pszOut will not contain the converted string. 

dwTimeMS 
[in] Time interval, in milliseconds. 

digits 
[in] Maximum number of digits to be represented in pszOut.  
***  


## Return value:
Returns the number of characters in pszOut, excluding the NULL terminator.  
***  


## Comments:
An example of this function"s return: 3 hour 07 min 21 sec  
  
***  

