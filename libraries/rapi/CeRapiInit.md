[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRapiInit
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function attempts to initialize the Windows CE remote application programming interface (RAPI).
***  


## Declaration:
```foxpro  
HRESULT CeRapiInit(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiInit IN rapi  
```  
***  


## Parameters:
None.  
***  


## Return value:
S_OK (0) indicates success. E_FAIL indicates failure.  
***  


## Comments:
The functions CeRapiInit or CeRapiInitEx must be called before any remote API calls can be performed. They initialize the underlying communications layers between the desktop computer and the target device.  
  
A call to CeRapiInit does not return until the connection is made, an error occurs, or another thread calls CeRapiUninit.  
  
I see no reason of using the CeRapiInit in FoxPro code because of its blocking nature. Once you call this function with no mobile device connected -- your application is frozen forever. The non-blocking CeRapiInitEx followed by the WaitForSingleObject call works very good.  
  
Call CeRapiUninit even if the connection failed.  
  
***  

