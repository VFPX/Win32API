<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetMailslotInfo
Group: Mailslot - Library: kernel32    
***  


#### The SetMailslotInfo function sets the time-out value used by the specified mailslot for a read operation. 
***  


## Code examples:
[Creating a mailslot](../../samples/sample_267.md)  

## Declaration:
```foxpro  
BOOL SetMailslotInfo(
  HANDLE hMailslot,    // mailslot handle
  DWORD lReadTimeout   // read time-out interval
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMailslotInfo IN kernel32;
	INTEGER hMailslot,;
	INTEGER lReadTimeout  
```  
***  


## Parameters:
```txt  
hMailslot
[in] Handle to a mailslot. The CreateMailslot function must create this handle.

lReadTimeout
[in] Specifies the amount of time, in milliseconds, a read operation can wait for a message to be written to the mailslot before a time-out occurs.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

