[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetLocaleInfo
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about a locale.
***  


## Code examples:
[Saving available locale records into a cursor](../../samples/sample_076.md)  

## Declaration:
```foxpro  
int GetLocaleInfo(
  LCID Locale,      // locale identifier
  LCTYPE LCType,    // information type
  LPTSTR lpLCData,  // information buffer
  int cchData       // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetLocaleInfo IN kernel32;
	INTEGER  Locale,;
	INTEGER  LCType,;
	STRING @ lpLCData,;
	INTEGER  cchData
  
```  
***  


## Parameters:
Locale 
[in] Specifies the locale to retrieve information for. 

LCType 
[in] Specifies the type of locale information to be retrieved, by using an LCTYPE constant. 

lpLCData 
[out] Pointer to a buffer that receives the requested data.

cchData 
[in] Specifies the size, in TCHARs, of the lpLCData buffer.  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs written to the destination buffer.  
***  


## Comments:
The GetLocaleInfo function always retrieves information in text format.  
  
***  

