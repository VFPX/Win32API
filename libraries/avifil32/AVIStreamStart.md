<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AVIStreamStart
Group: Windows Multimedia - Library: avifil32    
***  


#### The AVIStreamStart function returns the starting sample number for the stream.
***  


## Code examples:
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  

## Declaration:
```foxpro  
STDAPI_(LONG) AVIStreamStart(
  PAVISTREAM pavi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamStart IN avifil32;
	INTEGER pavi  
```  
***  


## Parameters:
```txt  
pavi
Handle to an open stream.
  
```  
***  


## Return value:
Returns the number if successful or - 1 otherwise.   
***  

