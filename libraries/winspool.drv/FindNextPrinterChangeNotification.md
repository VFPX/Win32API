<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindNextPrinterChangeNotification
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### Retrieves information about the most recent change notification for a change notification object associated with a printer or print server. Call this function when a wait operation on the change notification object is satisfied.
***  


## Code examples:
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  

## Declaration:
```foxpro  
BOOL FindNextPrinterChangeNotification(
	HANDLE hChange,                // change notification
	PDWORD pdwChange,              // condition that changed
	LPVOID pPrinterNotifyOptions,  // refresh option
	LPVOID *ppPrinterNotifyInfo    // printer information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextPrinterChangeNotification;
IN winspool.drv;
	INTEGER   hChange,;
	INTEGER @ pdwChange,;
	STRING  @ pPrinterNotifyOptions,;
	INTEGER @ ppPrinterNotifyInfo
  
```  
***  


## Parameters:
```txt  
hChange
[in] Handle to a change notification object associated with a printer or print server obtained by calling the FindFirstPrinterChangeNotification function.

pdwChange
[out] Pointer to a variable whose bits are set to indicate the changes that occurred to cause the most recent notification.

pPrinterNotifyOptions
[in] Pointer to a PRINTER_NOTIFY_OPTIONS structure.

ppPrinterNotifyInfo
[out] Pointer to a pointer variable that receives a pointer to a system-allocated, read-only buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
Call the FindNextPrinterChangeNotification function after a wait operation on a notification object created by FindFirstPrinterChangeNotification has been satisfied. Calling FindNextPrinterChangeNotification lets you obtain information about the change that satisfied the wait operation, and resets the notification object so it can be signaled when the next change occurs.  
  
See also: FindClosePrinterChangeNotification, FreePrinterNotifyInfo.  
  
***  

