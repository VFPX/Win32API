<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CoCreateGuid
Group: COM - Library: ole32    
***  


#### Creates a GUID, a unique 128-bit integer used for CLSIDs and interface identifiers.
***  


## Code examples:
[How to generate GUID values](../../samples/sample_456.md)  

## Declaration:
```foxpro  
HRESULT CoCreateGuid(
  GUID * pguid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CoCreateGuid IN ole32;
	STRING @ pguid  
```  
***  


## Parameters:
```txt  
pguid
[out] Pointer to the requested GUID on return.  
```  
***  


## Return value:
Returns S_OK (0) if the GUID has been successfully created.   
***  


## Comments:
To a very high degree of certainty, this function returns a unique value – no other invocation, on the same or any other system (networked or not), should return the same value.  
  
Read article <a href="http://betterexplained.com/articles/the-quick-guide-to-guids/">GUIDs and UUIDs explained</a> on the BetterExplained.  
  
See also: StringFromGUID2, UuidCreate   
  
***  

