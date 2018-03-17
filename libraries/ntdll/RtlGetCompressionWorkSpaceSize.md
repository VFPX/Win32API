<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RtlGetCompressionWorkSpaceSize
Group: Data Decompression Library - Library: ntdll    
***  


#### This function is used to determine the correct size of the WorkSpace buffer for the RtlCompressBuffer and RtlDecompressFragment functions.
***  


## Code examples:
[Compressing and decompressing files with Windows API Runtime Library routines](../../samples/sample_568.md)  

## Declaration:
```foxpro  
NTSTATUS RtlGetCompressionWorkSpaceSize(
  __in   USHORT CompressionFormatAndEngine,
  __out  PULONG CompressBufferWorkSpaceSize,
  __out  PULONG CompressFragmentWorkSpaceSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RtlGetCompressionWorkSpaceSize IN ntdll;
	SHORT CompressionFormatAndEngine,;
	LONG @CompressBufferWorkSpaceSize,;
	LONG @CompressFragmentWorkSpaceSize  
```  
***  


## Parameters:
```txt  
CompressionFormatAndEngine [in]
Bitmask specifying the compression format and engine type.

CompressBufferWorkSpaceSize [out]
A pointer to a caller-allocated buffer receiving the size, in bytes, required to compress a buffer.

CompressFragmentWorkSpaceSize [out]
A pointer to a caller-allocated buffer receiving the size, in bytes, required to decompress a compressed buffer to a fragment.  
```  
***  


## Return value:
Returns STATUS_SUCCESS (0) or an appropriate error code.  
***  

