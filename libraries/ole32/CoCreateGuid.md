[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CoCreateGuid
Group: [COM](../../functions_group.md#COM)  -  Library: [ole32](../../Libraries.md#ole32)  
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
pguid 
[out] Pointer to the requested GUID on return.   
***  


## Return value:
Returns S_OK (0) if the GUID has been successfully created.   
***  


## Comments:
To a very high degree of certainty, this function returns a unique value – no other invocation, on the same or any other system (networked or not), should return the same value.  
  
Read article <a href="http://betterexplained.com/articles/the-quick-guide-to-guids/">GUIDs and UUIDs explained</a> on the BetterExplained.  
  
See also: [StringFromGUID2](../ole32/StringFromGUID2.md), [UuidCreate](../rpcrt4/UuidCreate.md).  
  
***  

