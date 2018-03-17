<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DeletePort
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### Displays a dialog box that allows the user to delete a port name.
***  


## Code examples:
[Enumerating ports that are available for printing on a specified server](../../samples/sample_334.md)  

## Declaration:
```foxpro  
BOOL DeletePort(
	LPTSTR pName,      // server name
	HWND hWnd,         // handle to parent window
	LPTSTR pPortName   // port name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeletePort IN winspool.drv;
	STRING  pName,;
	INTEGER hWindow,;
	STRING  pPortName
  
```  
***  


## Parameters:
```txt  
pName
[in] Pointer to a zero-terminated string that specifies the name of the server for which the port should be deleted. If this parameter is NULL, a local port is deleted.

hWnd
[in] Handle to the parent window of the port-deletion dialog box.

pPortName
[in] Pointer to a zero-terminated string that specifies the name of the port that should be deleted.
  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The DeletePort function returns an error if a printer is currently connected to the specified port.   
  
The caller of the DeletePort function must have SERVER_ACCESS_ADMINISTER access to the server to which the port is connected.  
  
See also: AddPort, EnumPorts.  
  
***  

