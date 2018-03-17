<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FreePrinterNotifyInfo
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### Frees a system-allocated buffer created by the FindNextPrinterChangeNotification function.

***  


## Code examples:
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  

## Declaration:
```foxpro  
BOOL FreePrinterNotifyInfo(
	PPRINTER_NOTIFY_INFO pPrinterNotifyInfo  // buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FreePrinterNotifyInfo IN winspool.drv;
	INTEGER pPrinterNotifyInfo
  
```  
***  


## Parameters:
```txt  
pPrinterNotifyInfo
[in] Pointer to a PRINTER_NOTIFY_INFO buffer returned from a call to the FindNextPrinterChangeNotification function. FreePrinterNotifyInfo deallocates this buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

