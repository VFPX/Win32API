[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining heap handles and enumerating memory blocks for the current VFP session (WinNT only)

## Code:
```foxpro  
DO decl

*| typedef struct _PROCESS_HEAP_ENTRY {
*|   PVOID lpData;                      1:4
*|   DWORD cbData;                      5:4
*|   BYTE cbOverhead;                   9:1
*|   BYTE iRegionIndex;                10:1
*|   WORD wFlags;                      11:2
*|   union {
*|       struct {
*|           HANDLE hMem;              13:4
*|           DWORD dwReserved[ 3 ];    17:4
*|       } Block;
*|       struct {
*|           DWORD dwCommittedSize;    13:4
*|           DWORD dwUnCommittedSize;  17:4
*|           LPVOID lpFirstBlock;      21:4
*|           LPVOID lpLastBlock;       25:4
*|       } Region;
*|   };                       total: 28 bytes
*| } PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY

#DEFINE STRU_LENGTH                    28

*| Flags -- properties of the heap element
#DEFINE PROCESS_HEAP_REGION             1
#DEFINE PROCESS_HEAP_UNCOMMITTED_RANGE  2
#DEFINE PROCESS_HEAP_ENTRY_BUSY         4
#DEFINE PROCESS_HEAP_ENTRY_MOVEABLE    16
#DEFINE PROCESS_HEAP_ENTRY_DDESHARE    32

	LOCAL ii, lnHeapCount, lcBuffer, hHeap, lcHeapEntry, lnResult,;
		lpData, cbData, cbOverhead, lnRegIndex, lnFlags,;
		lnSzCmt, lnSzUncmt, lnFBlock, lnLBlock

	lnHeapCount = 256
	lcBuffer = Repli (Chr(0), lnHeapCount*4)
	lnHeapCount = GetProcessHeaps (lnHeapCount, @lcBuffer)
	
	* resulting cursor
	CREATE CURSOR csResult (heapno N(5), dataptr N(12),;
		datasize N(12), oversize N(4), regindex N(4), flags N(12),;
		szcomm N(12), szuncomm N(12), fblock N(12), lblock N(12))

	FOR ii = 1 TO lnHeapCount
		hHeap = buf2dword(SUBSTR (lcBuffer, (ii-1)*4+1, 4))

		* The HeapLock function is primarily useful for preventing
		* the allocation and release of heap memory by other threads
		* while the calling thread uses the HeapWalk function.
		IF HeapLock (hHeap) = 0
			? "Failure to lock handle:", hHeap
			LOOP
		ENDIF

		* stuff the buffer with zeroes
		lcHeapEntry = Repli (Chr(0), STRU_LENGTH)

		DO WHILE HeapWalk(hHeap, @lcHeapEntry) <> 0
			lpData     = buf2dword (SUBSTR(lcHeapEntry, 1,4))
			cbData     = buf2dword (SUBSTR(lcHeapEntry, 5,4))
			cbOverhead = Asc(SUBSTR(lcHeapEntry, 9,1))
			lnRegIndex = Asc(SUBSTR(lcHeapEntry, 10,1))
			lnFlags    = buf2word (SUBSTR(lcHeapEntry, 11,2))
			
			IF lnFlags = PROCESS_HEAP_REGION
				lnSzCmt   = buf2dword (SUBSTR(lcHeapEntry, 13,4))
				lnSzUncmt = buf2dword (SUBSTR(lcHeapEntry, 17,4))
				lnFBlock  = buf2dword (SUBSTR(lcHeapEntry, 21,4))
				lnLBlock  = buf2dword (SUBSTR(lcHeapEntry, 25,4))
			ELSE
				STORE 0 TO lnSzCmt, lnSzUncmt, lnFBlock, lnLBlock
			ENDIF
			
			INSERT INTO csResult VALUES (ii, lpData, cbData, cbOverhead,;
				lnRegIndex, lnFlags, lnSzCmt, lnSzUncmt,;
				lnFBlock, lnLBlock)
		ENDDO

		* Each call to HeapLock must be matched by
		* a corresponding call to the HeapUnlock function
		= HeapUnlock (hHeap)
	ENDFOR
	
	SELECT csResult
	GO TOP
	BROWSE NORMAL NOWAIT

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	   Asc(SUBSTR(lcBuffer, 2,1)) * 256

PROCEDURE  decl
	DECLARE INTEGER GetProcessHeaps IN kernel32;
		INTEGER NumberOfHeaps, STRING @ProcessHeaps

	DECLARE INTEGER HeapWalk IN kernel32;
		INTEGER hHeap, STRING @lpEntry

	DECLARE INTEGER HeapLock IN kernel32 INTEGER hHeap
	DECLARE INTEGER HeapUnlock IN kernel32 INTEGER hHeap  
```  
***  


## Listed functions:
[GetProcessHeaps](../libraries/kernel32/GetProcessHeaps.md)  
[HeapLock](../libraries/kernel32/HeapLock.md)  
[HeapUnlock](../libraries/kernel32/HeapUnlock.md)  
[HeapWalk](../libraries/kernel32/HeapWalk.md)  
