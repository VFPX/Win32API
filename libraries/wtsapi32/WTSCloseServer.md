[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSCloseServer
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
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
hServer 
[in] Handle to a terminal server opened by a call to the WTSOpenServer function.  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Call the WTSCloseServer function as part of your program"s clean-up routine to close all the server handles opened by calls to the WTSOpenServer function.   
  
***  

