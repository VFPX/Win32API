<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# StrDup returns a pointer to the duplicate of a source VFP string

## Code:
```foxpro  
DO decl

LOCAL lcSource, lcTarget, hMemory
lcSource = "Jack and Jill went up a hill"
hMemory = StrDup(lcSource)
	
IF hMemory <> 0
	? "Pointer to a new string:", hMemory

	* copying from a pointer to a VFP string
	lcTarget = SPACE(250)
	= StrCpy (@lcTarget, hMemory)
	? "Transferred string:", LEFT(lcTarget, AT(Chr(0), lcTarget)-1)

	* MSDN: The calling application must free this memory
	* by calling the LocalFree function on the pointer
	* returned by the call to StrDup.
	= LocalFree (hMemory)
ELSE
* error
ENDIF

PROCEDURE  decl
	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER StrDup IN shlwapi STRING lpsz
	DECLARE INTEGER StrCpyW IN shlwapi AS StrCpy;
		STRING @psz1, INTEGER psz2  
```  
***  


## Listed functions:
[LocalFree](../libraries/kernel32/LocalFree.md)  
[StrCpy](../libraries/shlwapi/StrCpy.md)  
[StrDup](../libraries/shlwapi/StrDup.md)  

## Comment:
For sure in many situations you can pass pointers to strings to external procedures just using **STRING @**.   
  
But not when you need to fill a structure, which contains 4-byte pointers to strings. StrDup solves this problem easily, though you have an additional burden to free the allocated memory block.  
  
***  

