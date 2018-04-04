[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ConfigurePort
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The ConfigurePort function displays the port-configuration dialog box for a port on the specified server. 
***  


## Code examples:
[How to display the port-configuration dialog box for a port on the specified server](../../samples/sample_362.md)  

## Declaration:
```foxpro  
BOOL ConfigurePort(
  LPTSTR pName,      // server name
  HWND hWnd,         // handle to parent window
  LPTSTR pPortName   // port name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ConfigurePort IN winspool.drv;
	STRING  pName,;
	INTEGER hWnd,;
	STRING  pPortName
  
```  
***  


## Parameters:
pName 
[in] Pointer to a null-terminated string that specifies the name of the server on which the specified port exists. 

hWnd 
[in] Handle to the parent window of the port-configuration dialog box. 

pPortName 
[in] Pointer to a null-terminated string that specifies the name of the port to be configured. 
  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

