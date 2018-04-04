[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRapiUninit
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function uninitializes the Windows CE remote application programming interface (RAPI). 
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
STDAPI CeRapiUninit(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiUninit IN rapi  
```  
***  


## Parameters:
None.  
***  


## Return value:
E_FAIL indicates that RAPI was not originally initialized.   
***  


## Comments:
The CeRapiUnInit function should be called when the application has completed its use of the remote API services. It gracefully closes down the connection to the Windows CE device. If called when not in an initialized state, it will return E_FAIL.   
  
***  

