[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRapiInvoke
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function can be used as a general-purpose mechanism to remotely execute a routine on the Windows CE device.
***  


## Code examples:
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
HRESULT CeRapiInvoke(
  LPCWSTR pDllPath,
  LPCWSTR pFunctionName,
  DWORD cbInput,
  BYTE* pInput,
  DWORD* pcbOutput,
  BYTE** ppOutput,
  IRAPIStream** ppIRAPIStream,
  DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiInvoke IN rapi;
	STRING    pDllPath,;
	STRING    pFunctionName,;
	INTEGER   cbInput,;
	STRING  @ pInput,;
	INTEGER @ pcbOutput,;
	STRING  @ ppOutput,;
	INTEGER @ ppIRAPIStream,;
	INTEGER   dwReserved  
```  
***  


## Parameters:
pDllPath 
[in] Pointer to a buffer containing the name of a DLL on the Windows CE device containing pFunctionName. 

pFunctionName 
[in] Pointer to a buffer containing the name of the function that RAPI should call on the Windows CE device. 

cbInput 
[in] Number of bytes in the input buffer *pInput. 

pInput 
[in] Pointer to a buffer containing the input data. 

pcbOutput 
[out] Pointer to a variable that is set to the number of bytes in the output buffer ppOutput when the function returns. 

ppOutput 
[out] Pointer to a variable that is set to the location of the output buffer upon return. 

ppIRAPIStream 
[out] Pointer to a variable that is set to the address of the IRAPIStream interface. 

dwReserved 
Reserved.   
***  


## Return value:
If RAPI services on the Windows CE device successfully locate and call the client function, then in <Em>Block Mode</Em> the return value is that which is returned on the Windows CE device by the called function. 

In <Em>Stream Mode</Em> the return value is S_OK. If the function was not called successfully, or an exception occurred during its execution, an error code is returned.   
***  


## Comments:
The CeRapiInvoke function operates in either block mode or stream mode.  
  
***  

