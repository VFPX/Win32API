[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindFirstPrinterChangeNotification
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### Creates a change notification object and returns a handle to the object. You can then use this handle in a call to one of the wait functions to monitor changes to the printer or print server.

***  


## Code examples:
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  

## Declaration:
```foxpro  
HANDLE FindFirstPrinterChangeNotification(
	HANDLE hPrinter,  // handle to printer
	DWORD fdwFlags,   // conditions to monitor
	DWORD fdwOptions, // reserved, must be zero
	LPVOID pPrinterNotifyOptions  // fields to monitor
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindFirstPrinterChangeNotification;
IN winspool.drv;
	INTEGER  hPrinter,;
	LONG     fdwFlags,;
	LONG     fdwOptions,;
	STRING @ pPrinterNotifyOptions
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer or print server that you want to monitor.

fdwFlags 
[in] Specify the conditions that will cause the change notification object to enter a signaled state.

fdwOptions 
Reserved; must be zero.

pPrinterNotifyOptions 
[in] Pointer to a PRINTER_NOTIFY_OPTIONS structure.  
***  


## Return value:
If the function succeeds, the return value is a handle to a change notification object associated with the specified printer or print server.  
***  


## Comments:
To monitor a printer or print server, call the FindFirstPrinterChangeNotification function, then use the returned change notification object handle in a call to one of the wait functions, like WaitForSingleObject.  
  
See also: [FindNextPrinterChangeNotification](../winspool.drv/FindNextPrinterChangeNotification.md), [FindClosePrinterChangeNotification](../winspool.drv/FindClosePrinterChangeNotification.md), [OpenPrinter](../winspool.drv/OpenPrinter.md).  
  
***  

