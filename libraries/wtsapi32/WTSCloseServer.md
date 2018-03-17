<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSCloseServer
Group: Terminal Services - Library: wtsapi32    
***  


#### Closes an open handle to a terminal server.
***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
void WTSCloseServer(
	HANDLE hServer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE WTSCloseServer IN Wtsapi32;
	INTEGER hServer  
```  
***  


## Parameters:
```txt  
hServer
[in] Handle to a terminal server opened by a call to the WTSOpenServer function.  
```  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Call the WTSCloseServer function as part of your program"s clean-up routine to close all the server handles opened by calls to the WTSOpenServer function.   
  
***  

