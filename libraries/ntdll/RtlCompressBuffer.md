[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RtlCompressBuffer
Group: [Data Decompression Library](../../functions_group.md#Data_Decompression_Library)  -  Library: [ntdll](../../Libraries.md#ntdll)  
***  


#### Compresses a buffer and can be used by a file system driver to facilitate the implementation of file compression.
***  


## Code examples:
[Compressing and decompressing files with Windows API Runtime Library routines](../../samples/sample_568.md)  

## Declaration:
```foxpro  
NTSTATUS RtlCompressBuffer(
  __in   USHORT CompressionFormatAndEngine,
  __in   PUCHAR UncompressedBuffer,
  __in   ULONG UncompressedBufferSize,
  __out  PUCHAR CompressedBuffer,
  __in   ULONG CompressedBufferSize,
  __in   ULONG UncompressedChunkSize,
  __out  PULONG FinalCompressedSize,
  __in   PVOID WorkSpace
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RtlCompressBuffer IN ntdll;
	SHORT CompressionFormatAndEngine,;
	INTEGER UncompressedBuffer,;
	LONG UncompressedBufferSize,;
	INTEGER CompressedBuffer,;
	LONG CompressedBufferSize,;
	LONG UncompressedChunkSize,;
	LONG @FinalCompressedSize,;
	INTEGER WorkSpace  
```  
***  


## Parameters:
CompressionFormatAndEngine [in]
A bitmask specifying the compression format and engine type.

UncompressedBuffer [in]
A pointer to a caller-allocated buffer (allocated from paged or non-paged pool) containing the data to be compressed. This parameter is required and cannot be NULL.

UncompressedBufferSize [in]
Size, in bytes, of the UncompressedBuffer buffer.

CompressedBuffer [out]
A pointer to a caller-allocated buffer (allocated from paged or non-paged pool) receiving the compressed data. This parameter is required and cannot be NULL.

CompressedBufferSize [in]
Size, in bytes, of the CompressedBuffer buffer.

UncompressedChunkSize [in]
The chunk size to use when compressing the UncompressedBuffer buffer. This parameter must be one of the following values: 512, 1024, 2048, or 4096 (system default).

FinalCompressedSize [out]
A pointer to a caller-allocated variable which receives the size, in bytes, of the compressed data stored in CompressedBuffer. This parameter is required and cannot be NULL.

WorkSpace [in]
A pointer to a caller-allocated work space buffer used by the RtlCompressBuffer function during compression.   
***  


## Return value:
Returns STATUS_SUCCESS (0) or an appropriate error code.  
***  


## Comments:
See also: [RtlDecompressBuffer](../ntdll/RtlDecompressBuffer.md), [RtlGetCompressionWorkSpaceSize](../ntdll/RtlGetCompressionWorkSpaceSize.md).  
  
***  

