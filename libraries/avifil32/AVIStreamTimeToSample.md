
## Function name : AVIStreamTimeToSample
Group: Windows Multimedia - Library: avifil32    
***  


#### The AVIStreamTimeToSample function converts from milliseconds to samples.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  

## Declaration:
```foxpro  
STDAPI_(LONG) AVIStreamTimeToSample(
  PAVISTREAM pavi,
  LONG lTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamTimeToSample IN avifil32;
	INTEGER pavi,;
	LONG    lTime
  
```  
***  


## Parameters:
pavi
Handle to an open stream.

lTime
Time, expressed in milliseconds.
  
***  


## Return value:
Returns the converted time if successful or - 1 otherwise.   
***  


## Comments:
Samples typically correspond to audio samples or video frames. Other stream types might support different formats than these.  
  
***  

