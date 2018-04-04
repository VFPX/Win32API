[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInOpen function opens the given waveform-audio input device for recording.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInOpen(
  LPHWAVEIN       phwi,
  UINT_PTR       uDeviceID,
  LPWAVEFORMATEX pwfx,
  DWORD_PTR      dwCallback,
  DWORD_PTR      dwCallbackInstance,
  DWORD          fdwOpen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInOpen IN winmm;
	INTEGER @ phwi,;
	INTEGER   uDeviceID,;
	STRING  @ pwfx,;
	INTEGER   dwCallback,;
	INTEGER   dwCallbackInstance,;
	LONG      fdwOpen
  
```  
***  


## Parameters:
phwi 
Pointer to a buffer that receives a handle identifying the open waveform-audio input device. 
uDeviceID 
Identifier of the waveform-audio input device to open.

pwfx 
Pointer to a WAVEFORMATEX structure that identifies the desired format for recording waveform-audio data. 

dwCallback 
Pointer to a fixed callback function, an event handle, a handle to a window, or the identifier of a thread to be called during waveform-audio recording to process messages related to the progress of recording.

dwCallbackInstance 
User-instance data passed to the callback mechanism. 

fdwOpen 
Flags for opening the device.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.   
***  


## Comments:
Use the waveInGetNumDevs function to determine the number of waveform-audio input devices present on the system.   
  
The device identifier specified by uDeviceID varies from zero to one less than the number of devices present. The WAVE_MAPPER constant can also be used as a device identifier.  
  
***  

