<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindClosePrinterChangeNotification
Group: Printing and Print Spooler - Library: winspool.drv    
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
```txt  
hChange
[in] Handle to the change notification object to be closed. This is a handle created by calling the FindFirstPrinterChangeNotification function.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
After this call, the printer or print server associated with the change notification object will no longer be monitored by that object.  
  
See also: FindNextPrinterChangeNotification.  
  
***  

