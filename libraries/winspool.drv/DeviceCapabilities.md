[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeviceCapabilities
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The DeviceCapabilities function retrieves the capabilities of a printer device driver.
***  


## Code examples:
[Retrieving list of supported paper names (for example, Letter or Legal) for a given printer](../../samples/sample_356.md)  

## Declaration:
```foxpro  
DWORD DeviceCapabilities(
  LPCTSTR pDevice,         // printer name
  LPCTSTR pPort,           // port name
  WORD fwCapability,       // device capability
  LPTSTR pOutput,          // output buffer
  CONST DEVMODE *pDevMode  // device data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeviceCapabilities IN winspool.drv;
	STRING    pDevice,;
	STRING    pPort,;
	INTEGER   fwCapability,;
	STRING  @ pOutput,;
	INTEGER   pDevMode  
```  
***  


## Parameters:
pDevice 
[in] Pointer to a null-terminated string that contains the name of the printer. Note that this is the name of the printer, not of the printer driver. 

pPort 
[in] Pointer to a null-terminated string that contains the name of the port to which the device is connected, such as LPT1. 

fwCapability 
[in] Specifies the capabilities to query. This parameter can be one of the predefined values. 
pOutput 
[out] Pointer to an array. The format of the array depends on the setting of the fwCapability parameter.

pDevMode 
[in] Pointer to a DEVMODE structure.  
***  


## Return value:
If the function fails, the return value is -1.  
***  


## Comments:
See also: [EnumForms](../winspool.drv/EnumForms.md), [DocumentProperties](../winspool.drv/DocumentProperties.md).  
  
***  

