<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRapiGetError
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
```txt  
None.  
```  
***  


## Return value:
This function returns standard Win32 error values.  
***  

