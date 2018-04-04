[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CopyMemory
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  

***  


## Code examples:
[Converting command-line string to a set of Unicode argument strings](../../samples/sample_212.md)  
[Winsock: retrieving information from a host database for a given host name](../../samples/sample_216.md)  
[Testing serial ports](../../samples/sample_308.md)  
[Connecting a local device to a network resource](../../samples/sample_318.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  
[Verifying a file using the Authenticode policy provider](../../samples/sample_569.md)  

## Declaration:
```foxpro  
VOID CopyMemory(
  PVOID Destination,   // copy destination
  CONST VOID* Source,  // memory block
  SIZE_T Length        // size of memory block
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
    STRING  @ Destination,;
    INTEGER   Source,;
    INTEGER   nLength  
```  
***  


## Comments:
The FoxPro declaration looks a bit tricky. There is no direct CopyMemory declaration in KERNEL32 module. Actually you can omit the alias and work directly with the name RtlMoveMemory.  
  
***  

