
## Function name : FindMediaType
Group: URL Monikers - Library: urlmon    
***  


#### Retrieves the 32-bit value assigned to the specified media type.
***  


## Code examples:
[Using the FindMediaType function](../../samples/sample_297.md)  

## Declaration:
```foxpro  
HRESULT FindMediaType(
	LPCSTR rgszTypes,
	CLIPFORMAT* rgcfTypes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindMediaType IN urlmon;
	STRING    rgszTypes,;
	INTEGER @ rgcfTypes  
```  
***  


## Parameters:
rgszTypes
Address of a string value that identifies the media type. 

rgcfTypes
Address of the CLIPFORMAT value assigned to the specified media type.   
***  


## Return value:
Returns S_OK (0) if successful, or an error value otherwise.
  
***  

