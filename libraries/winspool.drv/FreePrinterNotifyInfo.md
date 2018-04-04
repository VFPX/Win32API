[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FreePrinterNotifyInfo
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
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
pPrinterNotifyInfo 
[in] Pointer to a PRINTER_NOTIFY_INFO buffer returned from a call to the FindNextPrinterChangeNotification function. FreePrinterNotifyInfo deallocates this buffer.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

