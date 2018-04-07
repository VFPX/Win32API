[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCommandLine
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Returns a pointer to the command-line string for the current process.
***  


## Code examples:
[Retrieving the command line for the VFP session](../../samples/sample_051.md)  
[Converting command-line string to a set of Unicode argument strings](../../samples/sample_212.md)  

## Declaration:
```foxpro  
LPTSTR GetCommandLine(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCommandLine IN kernel32  
```  
***  


## Parameters:
This function has no parameters  
***  


## Return value:
The return value is a pointer to the command-line string for the current process  
***  


## Comments:
SYS(16), SYS(2019), and PCOUNT() all give same amount of information about the command line. May be for the VPF3 there is no other way to define a configuration file name but using this function.  
  
There is another difference. GetCommandLine keeps its data as long as the process is running, whereas using native VFP functions you must store the input parameters in global variables, if you want to reach them later.  
  
See also: [CommandLineToArgvW](../shell32/CommandLineToArgvW.md).  
  
***  

