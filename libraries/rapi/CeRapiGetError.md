[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRapiGetError
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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

