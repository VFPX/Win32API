[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using FillMemory

## Code:
```foxpro  
DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

DECLARE INTEGER GlobalAlloc IN kernel32;
	INTEGER wFlags, INTEGER dwBytes


*** Part 1
* applying the FillMemory to a FoxPro string

DECLARE RtlFillMemory IN kernel32 AS FillMemory;
	STRING  @ Dest,;
	INTEGER   Length,;
	SHORT     nFill

LOCAL lcBuffer
lcBuffer = SPACE(20)
= FillMemory (@lcBuffer, Len(lcBuffer), Asc("*"))
? lcBuffer


*** Part 2
* applying the FillMemory to a memory block

LOCAL hMem, lnBufsize

* allocating a memory block
#DEFINE GMEM_FIXED  0
lnBufsize = 512
hMem = GlobalAlloc (GMEM_FIXED, lnBufsize)

* note that the FillMemory destination object is different
* not a reference to a string, but a memory pointer
* that is why the function has to be redeclared

DECLARE RtlFillMemory IN kernel32 AS FillMemory;
	INTEGER Dest,;
	INTEGER Length,;
	SHORT   nFill

= FillMemory (hMem, lnBufsize, 42)

* and releasing the memory block in the end
? GlobalFree (hMem)  
```  
***  


## Listed functions:
[FillMemory](../libraries/kernel32/FillMemory.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
