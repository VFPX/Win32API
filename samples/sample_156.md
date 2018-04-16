[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Copying strings through the global memory block

## Code:
```foxpro  
#DEFINE GMEM_FIXED     0
#DEFINE GMEM_MOVEABLE  2
DO decl

	LOCAL lcTarget, lcSource, lnAllocSize, hMem, lnAddr

	lcSource = "Copying a string through an allocated memory object"
	lnAllocSize = Len(lcSource)
	lcTarget = SPACE(lnAllocSize) && the destination string is empty

	? "*** Before"
	? "Source string:     ", lcSource
	? "Destination string:", lcTarget
	?

	* allocating an amount of memory capable of storing
	* the source string (not Unicode)
	hMem = GlobalAlloc (GMEM_MOVEABLE, lnAllocSize)

	IF hMem <> 0
	
		* lock the memory block to get its address
		* WinNT: both can be identical
		lnAddr = GlobalLock (hMem)
		? "Memory object handle:", hMem
		? "Memory block address:", lnAddr
		?

		DECLARE RtlMoveMemory IN kernel32 As String2Heap;
			INTEGER Destination, STRING @ Source,;
			INTEGER nLength

		* copying source string -> allocated memory object
		= String2Heap (lnAddr, @lcSource, lnAllocSize)

		* every time you must re-declare this function
		* because this time you call with different parameter types
		DECLARE RtlMoveMemory IN kernel32 As Heap2String;
			STRING @ Destination, INTEGER Source,;
			INTEGER nLength

		* copying allocated memory object -> destination string
		= Heap2String (@lcTarget, lnAddr, lnAllocSize)

		* testing the results
		? "*** After"
		? "Source string:     ", lcSource
		? "Destination string:", lcTarget

		* releasing the medium
		= GlobalUnlock (hMem)
		= GlobalFree (hMem)
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE INTEGER GlobalLock IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalUnlock IN kernel32 INTEGER hMem  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalLock](../libraries/kernel32/GlobalLock.md)  
[GlobalUnlock](../libraries/kernel32/GlobalUnlock.md)  

## Comment:
This code demonstrates how to move binary data to and from global memory blocks. The source VFP string is copied into an allocated global memory block. Then content of this block is copied into the destination string. There is no direct usefulness in this code -- just a demonstration.  
  
In some situations you need to pass to a structure *(not to a function, that is easy)* the 4-byte pointer to a string -- LPCSTR, or LPCTSTR.   
  
As an example, to run some printer functions you must supply the DOCINFO structure:  
```cpp
typedef struct {   
    int     cbSize;   
    LPCTSTR lpszDocName;   
    LPCTSTR lpszOutput;   
    LPCTSTR lpszDatatype;  
    DWORD   fwType;   
} DOCINFO, *LPDOCINFO;
```

Within this structure **lpszDocName** is not a string, but a pointer to a string with a defined document name -- e.g. *"My Printer Job"*.   
  
That means, you must allocate this string in memory and pass the pointer to the structure. Using global memory functions makes this task possible. At that time -- to my knowledge -- there is no regular function in VFP to return a pointer to a string.  
  
If GMEM_FIXED being used instead of GMEM_MOVEABLE you can avoid using the GlobalLock and GlobalUnlock couple. With GMEM_FIXED you receive a pointer comparing to a handle to the memory object for the GMEM_MOVEABLE.  
  
***  

