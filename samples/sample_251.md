[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to play a waveform sound (a WAV file in particular)

## Before you begin:
This is a simple way of playing WAV files, and other waveform sounds from the Windows Registry, or from a memory image of a wavefrom sound.   

See also:


* [WAV file player](sample_417.md)  
* [WAV file recorder](sample_421.md)  
* [Playing WAV sounds simultaneously](sample_523.md)  
* [How to play MIDI notes](sample_537.md)  
* [Playing WAV files on InteractiveChange](sample_594.md)  
  
***  


## Code:
```foxpro  
#DEFINE SND_SYNC 0
#DEFINE SND_ASYNC 1
#DEFINE SND_NODEFAULT 2
#DEFINE SND_MEMORY 4
#DEFINE SND_LOOP 8
#DEFINE SND_NOSTOP 16

DECLARE INTEGER sndPlaySound IN winmm;
	STRING lpszSound, INTEGER fuSound

= sndPlaySound("c:\windows\media\tada.wav",;
	SND_ASYNC + SND_NODEFAULT)

*!*	= sndPlaySound("c:\windows\media\chimes.wav",;
*!*		SND_SYNC + SND_NODEFAULT)

*!*	= sndPlaySound("c:\windows\media\chord.wav",;
*!*		SND_SYNC + SND_NODEFAULT)

*!*	= sndPlaySound("c:\windows\media\notify.wav",;
*!*		SND_SYNC + SND_NODEFAULT + SND_NOSTOP)

*!*	= sndPlaySound("c:\program files\icq\icqgreet.wav",;
*!*		SND_ASYNC)  
```  
***  


## Listed functions:
[sndPlaySound](../libraries/winmm/sndPlaySound.md)  

## Comment:
Different combinations of flags provide some interesting ways, such as playing sounds asynchronously, when the sndPlaySound returns immediately after starting playing the sound. Still note that this function cannot be used for playing multiple sounds simultaneously. The waveOut* functions do that.  
  
***  

