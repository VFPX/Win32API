[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Adding supplementary data to AVI files

## Short description:
The code explains how supplementary data (copyright, comments etc.) can be stored in AVI files.  
***  


## Before you begin:
The code below shows how to add a string to AVI file. The string may contain, for example, a copyright information, comments etc. AVI or MMIO functions can be used later on to read the string.   

The code sample is simplified, intended to be only a blue-print. So use it on those AVI files you have copies of.  
  
***  


## Code:
```foxpro  
cFile = "findcomp.avi"
? AddInfo_AVI(cFile, "AUTH", SYS(0))
* end of main

PROCEDURE AddInfo_AVI(cAviFile, cChunkId, cValue)
#DEFINE OF_SHARE_DENY_WRITE 0x00000020
#DEFINE OF_READWRITE 0x00000002

	DO declare2
	= AVIFileInit()
	
	LOCAL hFile, nResult, nChunkId
	IF AVIFileOpen(@hFile, cFile,;
		BITOR(OF_SHARE_DENY_WRITE, OF_READWRITE), 0) <> 0
		RETURN .F.
	ENDIF
	
	nChunkId = buf2dword(PADR(cChunkId,4,CHR(0)))
	nResult = AVIFileWriteData(hFile, nChunkId,;
		@cValue, LEN(cValue))

	= AVIFileRelease(hFile)
	= AVIFileExit()
RETURN (nResult=0)

PROCEDURE AddInfo_RIFF(cAviFile, cChunkId, cValue)
#DEFINE MMIO_READWRITE  2
#DEFINE MMIO_ALLOCBUF   0x00010000
#DEFINE MMIO_FINDRIFF   0x0020
#DEFINE MMSYSERR_NOERROR 0

	DO declare1

	LOCAL hFile, cMMIOInfo, cRiffInfo,;
		cChunkInfo, lResult

	cMMIOInfo = Repli(Chr(0), 64)
	hFile = mmioOpen(cAviFile, @cMMIOInfo,;
		MMIO_READWRITE+MMIO_ALLOCBUF)

	IF hFile <= 0
		RETURN .F.
	ENDIF

	cRiffInfo = Repli(Chr(0), 20)
	= mmioDescend(hFile, @cRiffInfo, Null, MMIO_FINDRIFF)
	= mmioAscend(hFile, @cRiffInfo, 0)

	cChunkInfo = PADR(PADR(cChunkId,4,CHR(0)) +;
		num2dword(LEN(m.cValue)), 20)

	IF mmioCreateChunk(hFile, @cChunkInfo, 0)=0;
		And mmioWrite(hFile, cValue, Len(cValue))=0
		= mmioAscend(hFile, @cChunkInfo, 0)
		lResult=.T.
	ENDIF

	= mmioFlush(hFile, 0)
	= mmioClose(hFile, 0)
RETURN m.lResult

PROCEDURE declare1
	DECLARE INTEGER mmioClose IN winmm INTEGER hmmio, INTEGER wFlags
	DECLARE INTEGER mmioFlush IN winmm INTEGER hmmio, INTEGER fuFlush

	DECLARE INTEGER mmioOpen IN winmm;
		STRING szFilename, STRING @lpmmioinfo, INTEGER dwOpenFlags

	DECLARE INTEGER mmioAscend IN winmm;
		INTEGER hmmio, STRING @lpck, INTEGER wFlags

	DECLARE INTEGER mmioDescend IN winmm;
		INTEGER hmmio, STRING @lpck,;
		STRING @lpckParent, INTEGER wFlags

	DECLARE LONG mmioWrite IN winmm;
		INTEGER hmmio, STRING pch, LONG cch

	DECLARE INTEGER mmioCreateChunk IN winmm;
		INTEGER hmmio, STRING @lpck, INTEGER wFlags

PROCEDURE declare2
	DECLARE AVIFileInit IN avifil32
	DECLARE AVIFileExit IN avifil32
	DECLARE INTEGER AVIFileRelease IN avifil32 INTEGER pfile

	DECLARE INTEGER AVIFileOpen IN avifil32;
		INTEGER @ppfile, STRING szFile,;
		INTEGER mode, INTEGER pclsidHandler

	DECLARE INTEGER AVIFileWriteData IN avifil32;
		INTEGER pfile, LONG ckid,;
		STRING @lpData, LONG cbData

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[AVIFileExit](../libraries/avifil32/AVIFileExit.md)  
[AVIFileInit](../libraries/avifil32/AVIFileInit.md)  
[AVIFileOpen](../libraries/avifil32/AVIFileOpen.md)  
[AVIFileRelease](../libraries/avifil32/AVIFileRelease.md)  
[AVIFileWriteData](../libraries/avifil32/AVIFileWriteData.md)  
[mmioAscend](../libraries/winmm/mmioAscend.md)  
[mmioClose](../libraries/winmm/mmioClose.md)  
[mmioCreateChunk](../libraries/winmm/mmioCreateChunk.md)  
[mmioDescend](../libraries/winmm/mmioDescend.md)  
[mmioFlush](../libraries/winmm/mmioFlush.md)  
[mmioOpen](../libraries/winmm/mmioOpen.md)  
[mmioWrite](../libraries/winmm/mmioWrite.md)  

## Comment:
AVI formats support adding supplementary data (other than normal header, format, and stream data) to AVI files.   
  
The Microsoft AVI file format is a RIFF file specification, so any supplementary data can be added in the chunk format. A chunk consists from ID (4 bytes), data size (4 bytes) and the data itself (up to 0xffffffff bytes).  
  
Here is an example of chunk with supplementary data:  
<font color=#a00000>CPRT</font><font color=#00a000>*000</font><font color=#0000a0>Copyright (c) 2001-2005. Such-n-such, Inc.</font>  
  
Where <font color=#a00000>CRPT</font> is 4-byte ID. <font color=#00a000>*000</font> is the binary presentation (DWORD) of number 42, which is the length of the data. And <font color=#0000a0>Copyright (c) 2001-2005. Such-n-such, Inc.</font> is the data.  
  
In less sophisticated way, FoxPro low-level file functions most liekly can be used to open AVI file and attach some data to the end of it.  
  
If you prefer playing by rules, use either AVI or MMIO API functions. Two procedures in the code above present both ways. Well, neither AVIFileWriteData nor mmioCreateChunk works smart enough.   
  
The *AddInfo_AVI* adds new chunk to the AVI file regardless of whether a chunk with this ID already exists. If you decide to read the supplementary information using the AVIFileReadData, it will read only the first chunk found.  
  
The *AddInfo_RIFF* always adds a chunk immediately after the main part of the file. Although, you may modify the code, making it search through existing chunks. In my opinion, MMIO functions have much greater flexibility. With them you can build a real routine for adding, reading and modifying supplementary data in AVI files.  
  
***  

