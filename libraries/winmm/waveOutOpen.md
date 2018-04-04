[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveOutOpen function opens the given waveform-audio output device for playback.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutOpen(
  LPHWAVEOUT     phwo,
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
DECLARE INTEGER waveOutOpen IN winmm;
	INTEGER @ phwo,;
	INTEGER   uDeviceID,;
	STRING  @ pwfx,;
	INTEGER   dwCallback,;
	INTEGER   dwCallbackInst,;
	INTEGER   fdwOpen
  
```  
***  


## Parameters:
phwo 
Pointer to a buffer that receives a handle identifying the open waveform-audio output device.

uDeviceID 
Identifier of the waveform-audio output device to open.

pwfx 
Pointer to a WAVEFORMATEX structure that identifies the format of the waveform-audio data to be sent to the device.

dwCallback 
Pointer to a fixed callback function, an event handle, a handle to a window, or the identifier of a thread to be called during waveform-audio playback to process messages related to the progress of the playback.

dwCallbackInstance 
User-instance data passed to the callback mechanism. This parameter is not used with the window callback mechanism. 

fdwOpen 
Flags for opening the device. The following values are defined.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
Use the waveOutGetNumDevs function to determine the number of waveform-audio output devices present in the system. If the value specified by the uDeviceID parameter is a device identifier, it can vary from zero to one less than the number of devices present.   
  
The WAVE_MAPPER constant can also be used as a device identifier.  
  
If you choose to have a function receive callback information, the following messages are sent to the function to indicate the progress of waveform-audio output: WOM_OPEN, WOM_CLOSE, and WOM_DONE.   
  
***  

