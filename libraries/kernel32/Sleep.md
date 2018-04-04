[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Sleep
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
dwMilliseconds 
[in] Specifies the time, in milliseconds, for which to suspend execution  
***  


## Return value:
This function does not return a value  
***  


## Comments:
A value INFINITE = DWORD(0xffffffff) causes the infinite delay for the thread (the process for the VFP).  
  
***  

