[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumForms
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumForms function enumerates the forms supported by the specified printer.
***  


## Code examples:
[Enumerating forms supported by a specified printer](../../samples/sample_390.md)  

## Declaration:
```foxpro  
BOOL EnumForms(
  HANDLE hPrinter,    // handle to printer object
  DWORD Level,        // data level
  LPBYTE pForm,       // form information buffer
  DWORD cbBuf,        // size of form information buffer
  LPDWORD pcbNeeded,  // bytes received or required
  LPDWORD pcReturned  // number of forms received
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumForms IN winspool.drv;
	INTEGER   hPrinter,;
	INTEGER   lvl,;
	INTEGER   pForm,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer for which the forms should be enumerated.

Level 
[in] Specifies the version of the structure to which pForm points. This value must be 1. 

pForm 
[out] Pointer to a FORM_INFO_1 structure. 

cbBuf 
[in] Specifies the size, in bytes, of the buffer to which pForm points. 

pcbNeeded 
[out] Pointer to a variable that receives the number of bytes copied to or the number of bytes required for the array to which pForm points.

pcReturned 
[out] Pointer to a variable that receives the number of FORM_INFO_1 structures copied into the array to which pForm points.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

