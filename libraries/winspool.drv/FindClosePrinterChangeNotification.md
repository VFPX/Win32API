[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindClosePrinterChangeNotification
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### Closes a change notification object created by calling the FindFirstPrinterChangeNotification function.
***  


## Code examples:
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  

## Declaration:
```foxpro  
BOOL FindClosePrinterChangeNotification(
	HANDLE hChange // handle to change notification object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindClosePrinterChangeNotification;
IN winspool.drv;
	INTEGER hChange
  
```  
***  


## Parameters:
hChange 
[in] Handle to the change notification object to be closed. This is a handle created by calling the FindFirstPrinterChangeNotification function.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
After this call, the printer or print server associated with the change notification object will no longer be monitored by that object.  
  
See also: [FindNextPrinterChangeNotification](../winspool.drv/FindNextPrinterChangeNotification.md).  
  
***  

