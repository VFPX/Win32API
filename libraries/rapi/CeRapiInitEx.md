<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRapiInitEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function attempts to initialize the Windows CE remote application programming interface (RAPI) and initially returns an event handle.
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
HRESULT CeRapiInitEx(
  RAPIINIT* pRapiInit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiInitEx IN rapi;
	STRING @ pRapiInit  
```  
***  


## Parameters:
```txt  
pRapiInit
[in] Pointer to a RAPIINIT structure.  
```  
***  


## Return value:
S_OK indicates success. E_FAIL indicates failure.  
***  


## Comments:
This non-blocking function creates an event handle, which can be retrieved from the RAPIINIT structure immediately after the call. Use WaitForSingleObject to check either for the signaled state of the event or for the time-out.  
  
The <Em>HRESULT hrRapiInit</Em> parameter in the RAPIINIT may be not reliable.  
  
Call CeRapiUninit even if the connection failed.  
  
***  

