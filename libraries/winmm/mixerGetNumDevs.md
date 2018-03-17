<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetNumDevs
Group: Windows Multimedia - Library: winmm    
***  


#### The mixerGetNumDevs function retrieves the number of mixer devices present in the system.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
UINT mixerGetNumDevs(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetNumDevs IN winmm  
```  
***  


## Parameters:
```txt  
This function takes no parameters.  
```  
***  


## Return value:
Returns the number of mixer devices or zero if no mixer devices are available.  
***  

