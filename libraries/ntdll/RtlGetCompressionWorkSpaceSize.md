[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RtlGetCompressionWorkSpaceSize
Group: [Data Decompression Library](../../functions_group.md#Data_Decompression_Library)  -  Library: [ntdll](../../Libraries.md#ntdll)  
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
CompressionFormatAndEngine [in]
Bitmask specifying the compression format and engine type.

CompressBufferWorkSpaceSize [out]
A pointer to a caller-allocated buffer receiving the size, in bytes, required to compress a buffer.

CompressFragmentWorkSpaceSize [out]
A pointer to a caller-allocated buffer receiving the size, in bytes, required to decompress a compressed buffer to a fragment.  
***  


## Return value:
Returns STATUS_SUCCESS (0) or an appropriate error code.  
***  

