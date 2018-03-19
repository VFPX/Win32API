
## Function name : MessageBeep
Group: Error Handling - Library: user32    
***  


#### Plays a waveform sound. The waveform sound for each sound type is identified by an entry in the [sounds] section of the registry
***  


## Code examples:
[Using MessageBeep](../../samples/sample_037.md)  

## Declaration:
```foxpro  
BOOL MessageBeep(
	UINT  uType 	// sound type
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MessageBeep IN user32 INTEGER wType  
```  
***  


## Parameters:
uType
Specifies the sound type  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  

