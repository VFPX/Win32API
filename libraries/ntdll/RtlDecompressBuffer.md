
## Function name : RtlDecompressBuffer
Group: Data Decompression Library - Library: ntdll    
***  


#### Decompresses an entire compressed buffer.
***  


## Code examples:
[Compressing and decompressing files with Windows API Runtime Library routines](../../samples/sample_568.md)  

## Declaration:
```foxpro  
NTSTATUS RtlDecompressBuffer(
  __in   USHORT CompressionFormat,
  __out  PUCHAR UncompressedBuffer,
  __in   ULONG UncompressedBufferSize,
  __in   PUCHAR CompressedBuffer,
  __in   ULONG CompressedBufferSize,
  __out  PULONG FinalUncompressedSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RtlDecompressBuffer IN ntdll;
	SHORT CompressionFormat,;
	INTEGER UncompressedBuffer,;
	LONG UncompressedBufferSize,;
	INTEGER CompressedBuffer,;
	LONG CompressedBufferSize,;
	LONG @FinalUncompressedSize  
```  
***  


## Parameters:
CompressionFormat [in]
Bitmask specifying the compression format of the compressed buffer. This parameter must be set to COMPRESSION_FORMAT_LZNT1.

UncompressedBuffer [out]
Pointer to a caller-allocated buffer (allocated from paged or non-paged pool) receiving the decompressed data from CompressedBuffer. This parameter is required and cannot be NULL.

UncompressedBufferSize [in]
The size, in bytes, of the UncompressedBuffer buffer.

CompressedBuffer [in]
A pointer to the buffer containing the data to decompress. This parameter is required and cannot be NULL.

CompressedBufferSize [in]
The size, in bytes, of the CompressedBuffer buffer.

FinalUncompressedSize [out]
A pointer to a caller-allocated variable which receives the size, in bytes, of the decompressed data stored in UncompressedBuffer.  
***  


## Return value:
Returns STATUS_SUCCESS (0) or an appropriate error code.  
***  


## Comments:
See also: RtlCompressBuffer, RtlDecompressFragment, RtlGetCompressionWorkSpaceSize   
  
***  

