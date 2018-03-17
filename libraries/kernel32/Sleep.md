<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : Sleep
Group: Process and Thread - Library: kernel32    
***  


#### The Sleep function suspends the execution of the current thread for the specified interval
***  


## Code examples:
[How to make the caption of a VFP application flashing in the Windows task bar](../../samples/sample_228.md)  
[Using Beep and Sleep functions to make the old tin <s>buzz</s> sing (WinNT only?)](../../samples/sample_240.md)  
[How to play MIDI notes](../../samples/sample_537.md)  
[GDI+ fun: roach-infested desktop](../../samples/sample_548.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
VOID Sleep(
	DWORD dwMilliseconds   // sleep time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE Sleep IN kernel32 INTEGER dwMilliseconds  
```  
***  


## Parameters:
```txt  
dwMilliseconds
[in] Specifies the time, in milliseconds, for which to suspend execution  
```  
***  


## Return value:
This function does not return a value  
***  


## Comments:
A value INFINITE = DWORD(0xffffffff) causes the infinite delay for the thread (the process for the VFP).  
  
***  

