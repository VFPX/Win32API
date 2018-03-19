
## Function name : CeRapiGetError
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function reports remote API related failures. CeRapiGetError can be used to determine if a call failed due to a failure in the remote API. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
HRESULT CeRapiGetError(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiGetError IN rapi  
```  
***  


## Parameters:
None.  
***  


## Return value:
This function returns standard Win32 error values.  
***  

