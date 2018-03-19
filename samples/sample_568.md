[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Compressing and decompressing files with Windows API Runtime Library routines

## Before you begin:
LZNT1Compression class in the code sample below implements compression and decompression of strings and files. It provides a moderate level of compression.  

The class is built on several functions from Windows API Runtime library. Tested and found operational under VFP9 SP2 on Windows XP and on Windows 7.  
  
***  


## Code:
```foxpro  
LOCAL oCompression As LZNT1Compression
oCompression = CREATEOBJECT("LZNT1Compression")

LOCAL cSourceFile, cCompressedFile, cRestoredFile

* Set cSourceFile to a valid path.
* Test on a smaller file first.
cSourceFile = "c:\temp\somefile.txt"

cCompressedFile = JUSTPATH(cSourceFile) + "\" +;
	STRTRAN(JUSTFNAME(cSourceFile), ".", "_") +;
	".cmp"

cRestoredFile = JUSTPATH(cSourceFile) + "\" +;
	JUSTSTEM(cSourceFile) + "_restored." +;
	JUSTEXT(m.cSourceFile)
	
? "Source file:", cSourceFile
? "Compressed file:", cCompressedFile
? "Restored file:", cRestoredFile

IF oCompression.CompressFile(cSourceFile,;
	cCompressedFile)

	? oCompression.DecompressFile(cCompressedFile,;
		cRestoredFile)
ENDIF
* end of main

DEFINE CLASS LZNT1Compression As Custom

#DEFINE COMPRESSION_FORMAT_LZNT1 2
#DEFINE COMPRESSION_ENGINE_STANDARD 0
#DEFINE COMPRESSION_ENGINE_MAXIMUM 0x0100
#DEFINE UNCOMPRESSED_CHUNK_SIZE 4096  && system default

#DEFINE STATUS_SUCCESS 0
#DEFINE STATUS_BUFFER_ALL_ZEROS        0x00000117
#DEFINE STATUS_INVALID_PARAMETER       0xc000000d
#DEFINE STATUS_UNSUPPORTED_COMPRESSION 0xc000025f
#DEFINE STATUS_NOT_SUPPORTED           0xc00000bb
#DEFINE STATUS_BUFFER_TOO_SMALL        0xc0000023
#DEFINE STATUS_BAD_COMPRESSION_BUFFER  0xc0000242
* error code = 35 -- 0x23

PROTECTED WorkSpaceCompress, WorkSpaceDecompress,;
	CompressionFormat, CompressionEngine

	WorkSpaceCompress = 0x8000
	WorkSpaceDecompress = 0x1000
	CompressionFormat = COMPRESSION_FORMAT_LZNT1
	
	* choose either STANDARD or MAXIMUM
	* lesser time vs. better compression
	CompressionEngine = COMPRESSION_ENGINE_STANDARD && _MAXIMUM

PROCEDURE Init
	WITH THIS
		.declare
		.ReadInternalSettings
	ENDWITH

FUNCTION CompressFile(cOriginalFile As String,;
	cCompressedFile As String) As Boolean

	LOCAL cSourceBuffer, cTargetBuffer,;
		ex As Exception, lResult
	
	TRY
		lResult = .F.
		cSourceBuffer = FILETOSTR(m.cOriginalFile)

		IF LEN(m.cSourceBuffer) > 0
			cTargetBuffer = ""

			IF THIS.CompressString(@cSourceBuffer,;
				@cTargetBuffer) > 0

				STRTOFILE(cTargetBuffer, m.cCompressedFile)
				lResult = .T.
			ENDIF
		ENDIF

	CATCH TO ex
		= MESSAGEBOX(TRANSFORM(ex.ErrorNo) + ". " +;
			ex.Message, 48, "Compression Error!")
	ENDTRY
RETURN m.lResult

FUNCTION DecompressFile(cCompressedFile As String,;
	cDecompressedFile As String) As Boolean

	LOCAL cSourceBuffer, cTargetBuffer,;
		ex As Exception, lResult
	
	TRY
		lResult = .F.
		cSourceBuffer = FILETOSTR(m.cCompressedFile)

		IF LEN(m.cSourceBuffer) > 0
			cTargetBuffer = ""

			IF THIS.DecompressString(@cSourceBuffer,;
				@cTargetBuffer) > 0

				STRTOFILE(cTargetBuffer, m.cDecompressedFile)
				lResult = .T.
			ENDIF
		ENDIF

	CATCH TO ex
		= MESSAGEBOX(TRANSFORM(ex.ErrorNo) + ". " +;
			ex.Message, 48, "Decompression Error!")
	ENDTRY
RETURN m.lResult

FUNCTION CompressString(cOriginalString As String,;
	cCompressedString As String) As Number

	LOCAL oInputBuffer As PChar, oOutputBuffer As PChar,;
		oWorkSpace As PChar, nCompressedSize,;
		nFinalCompressedSize, nStatus

	oInputBuffer = CREATEOBJECT("PChar", m.cOriginalString)

	oWorkSpace = CREATEOBJECT("PChar",;
		REPLICATE(CHR(0), THIS.WorkSpaceCompress))

	* as a precaution, set the size of the output buffer
	* some larger than the original string
	
	nCompressedSize = MAX(4096, LEN(m.cOriginalString) * 1.3)
	
	DO WHILE .T.

		nFinalCompressedSize = 0

		oOutputBuffer = CREATEOBJECT("PChar",;
			REPLICATE(CHR(0), m.nCompressedSize))

		nStatus = RtlCompressBuffer(;
			BITOR(THIS.CompressionFormat, THIS.CompressionEngine),;
			oInputBuffer.GetAddr(),;
			oInputBuffer.GetAllocSize(),;
			oOutputBuffer.GetAddr(),;
			oOutputBuffer.GetAllocSize(),;
			UNCOMPRESSED_CHUNK_SIZE,;
			@nFinalCompressedSize,;
			oWorkSpace.GetAddr();
			)

		DO CASE
		CASE m.nStatus = STATUS_SUCCESS
			EXIT

		CASE BITAND(m.nStatus, 0xffff) =;
			BITAND(STATUS_BUFFER_TOO_SMALL, 0xffff)

		* This may happen with a file to be compressed
		* being already in compressed format (JPEG, PDF, ZIP).
		* Increase buffer size and loop.
			oOutputBuffer = NULL
			nCompressedSize = nCompressedSize +;
				LEN(m.cOriginalString)
			
		OTHERWISE
			= MESSAGEBOX("API error code: " +;
				TRANSFORM(m.nStatus), 48,;
				"Compression Error!")

			cCompressedString = ""
			RETURN 0

		ENDCASE
	ENDDO

	cCompressedString = SUBSTR(oOutputBuffer.GetValue(),;
		1, nFinalCompressedSize)
	
RETURN nFinalCompressedSize

FUNCTION DecompressString(cCompressedString As String,;
	cDecompressedString As String) As Number

	LOCAL oUncompressedBuffer As PChar, oCompressedBuffer As PChar,;
		nUncompressedSize, nFinalUncompressedSize, nStatus

	oCompressedBuffer = CREATEOBJECT("PChar", m.cCompressedString)

	nUncompressedSize = LEN(m.cCompressedString) * 2

	DO WHILE .T.
		oUncompressedBuffer = CREATEOBJECT("PChar",;
			REPLICATE(CHR(0), nUncompressedSize))

		nFinalUncompressedSize = 0

		nStatus = RtlDecompressBuffer(;
			THIS.CompressionFormat,;
			oUncompressedBuffer.GetAddr(),;
			oUncompressedBuffer.GetAllocSize(),;
			oCompressedBuffer.GetAddr(),;
			oCompressedBuffer.GetAllocSize(),;
			@nFinalUncompressedSize;
			)

		DO CASE
		CASE nStatus = STATUS_SUCCESS
			EXIT

		CASE BITAND(nStatus, 0xffff) =;
			BITAND(STATUS_BAD_COMPRESSION_BUFFER, 0xffff)

		* if a larger buffer required
		* increase buffer size and loop
			oUncompressedBuffer = NULL
			nUncompressedSize = nUncompressedSize +;
				LEN(m.cCompressedString)

		OTHERWISE
			* some other error

			= MESSAGEBOX("API error code: " +;
				TRANSFORM(m.nStatus), 48,;
				"Decompression Error!")

			RETURN 0

		ENDCASE
	ENDDO
	
	cDecompressedString = SUBSTR(oUncompressedBuffer.GetValue(),;
		1, nFinalUncompressedSize)

RETURN m.nFinalUncompressedSize

PROTECTED FUNCTION ReadInternalSettings()

	LOCAL nFlag, nWorkSpaceCompress, nWorkSpaceDecompress

	WITH THIS
		nFlag = BITOR(.CompressionFormat, .CompressionEngine)
		STORE 0 TO nWorkSpaceCompress, nWorkSpaceDecompress

		IF RtlGetCompressionWorkSpaceSize( m.nFlag,;
			@nWorkSpaceCompress,;
			@nWorkSpaceDecompress ) <> STATUS_SUCCESS
			
			RETURN .F.
		ENDIF

		.WorkSpaceCompress = m.nWorkSpaceCompress
		.WorkSpaceDecompress = m.nWorkSpaceDecompress
	ENDWITH

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	
	DECLARE INTEGER RtlGetCompressionWorkSpaceSize IN ntdll;
		SHORT CompressionFormatAndEngine,;
		LONG @CompressBufferWorkSpaceSize,;
		LONG @CompressFragmentWorkSpaceSize

	DECLARE INTEGER RtlCompressBuffer IN ntdll;
		SHORT CompressionFormatAndEngine,;
		INTEGER UncompressedBuffer, LONG UncompressedBufferSize,;
		INTEGER CompressedBuffer, LONG CompressedBufferSize,;
		LONG UncompressedChunkSize,;
		LONG @FinalCompressedSize, INTEGER WorkSpace

	DECLARE INTEGER RtlDecompressBuffer IN ntdll;
		SHORT CompressionFormat,;
		INTEGER UncompressedBuffer, LONG UncompressedBufferSize,;
		INTEGER CompressedBuffer, LONG CompressedBufferSize,;
		LONG @FinalUncompressedSize

ENDDEFINE

DEFINE CLASS PChar As Session
PROTECTED hMem

PROCEDURE Init(cString As String)
	THIS.hMem = 0
	THIS.setValue(cString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr
RETURN THIS.hMem

FUNCTION GetValue
	LOCAL nBufsize, cBuffer
	nBufsize = THIS.GetAllocSize()
	cBuffer = REPLICATE(CHR(0), m.nBufsize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@cBuffer, THIS.hMem, nBufsize)
	ENDIF
RETURN m.cBuffer

FUNCTION GetAllocSize
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue(cString)
#DEFINE GMEM_FIXED 0
#DEFINE GMEM_MOVEABLE 2
#DEFINE GMEM_ZEROINIT 0x0040

	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER, INTEGER

	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL nBufsize
	nBufsize = LEN(cString)
	THIS.hMem = GlobalAlloc(0x0040, nBufsize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @cString, nBufsize)
	ENDIF

PROCEDURE ReleaseString
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF

ENDDEFINE  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[RtlCompressBuffer](../libraries/ntdll/RtlCompressBuffer.md)  
[RtlDecompressBuffer](../libraries/ntdll/RtlDecompressBuffer.md)  
[RtlGetCompressionWorkSpaceSize](../libraries/ntdll/RtlGetCompressionWorkSpaceSize.md)  

## Comment:
Pity, the output of this algorithm does not seem to be compatible with the one of the .NET DeflateStream Class. In other words, a file compressed with this VFP class cannot get decompressed by the .NET class, and vice versa.  
  
***  

