[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AddPort
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Adds the name of a port to the list of supported ports. The AddPort function is exported by the port monitor.
***  


## Code examples:
[Enumerating ports that are available for printing on a specified server](../../samples/sample_334.md)  

## Declaration:
```foxpro  
BOOL AddPort(
	LPTSTR pName,         // server name
	HWND hWnd,            // handle to parent window
	LPTSTR pMonitorName   // monitor name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AddPort IN winspool.drv;
	STRING pName,;
	INTEGER hWindow,;
	STRING pMonitorName
  
```  
***  


## Parameters:
pName 
[in] Pointer to a zero-terminated string that specifies the name of the server to which the port is connected. If this parameter is NULL, the port is local. 

hWnd 
[in] Handle to the parent window of the AddPort dialog box. 

pMonitorName 
[in] Pointer to a zero-terminated string that specifies the monitor associated with the port.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The AddPort function browses the network to find existing ports, and displays a dialog box for the user. The AddPort function should validate the port name entered by the user by calling EnumPorts to ensure that no duplicate names exist.  
  
The caller of the AddPort function must have SERVER_ACCESS_ADMINISTER access to the server to which the port is connected.  
  
See also: [DeletePort](../winspool.drv/DeletePort.md), [EnumPorts](../winspool.drv/EnumPorts.md).  
  
***  

