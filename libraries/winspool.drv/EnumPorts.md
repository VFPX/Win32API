[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumPorts
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumPorts function enumerates the ports that are available for printing on a specified server.
***  


## Code examples:
[Enumerating ports that are available for printing on a specified server](../../samples/sample_334.md)  

## Declaration:
```foxpro  
BOOL EnumPorts(
  LPTSTR pName,       // server name
  DWORD Level,        // information level
  LPBYTE pPorts,      // port information buffer
  DWORD cbBuf,        // size of port information buffer
  LPDWORD pcbNeeded,  // bytes received or required
  LPDWORD pcReturned  // number of ports received
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPorts IN winspool.drv;
	STRING    pName,;
	INTEGER   Level,;
	STRING  @ pPorts,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned
  
```  
***  


## Parameters:
pName 
[in] Pointer to a null-terminated string that specifies the name of the server whose printer ports you wish to enumerate. 

Level 
[in] Specifies the type of information returned in the pPorts buffer.

pPorts 
[out] Pointer to a buffer that receives an array of PORT_INFO_1 or PORT_INFO_2 structures. 

cbBuf 
[in] Specifies the size, in bytes, of the buffer pointed to by pPorts. 

pcbNeeded 
[out] Pointer to a variable that receives the number of bytes copied to the pPorts buffer.

pcReturned 
[out] Pointer to a variable that receives the number of PORT_INFO_1 or PORT_INFO_2 structures returned in the pPorts buffer.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

