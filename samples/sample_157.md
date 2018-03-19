[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Dynamic strings implemented through VFP Custom class

## Code:
```foxpro  
LOCAL obj
obj = CreateObject ("DynaString")

obj.setValue ("Test String")
? obj.getAddr(), "|", obj.getAllocSize(), "|", obj.getValue()

obj.setValue (Repli("*", 50))
? obj.getAddr(), "|", obj.getAllocSize(), "|", obj.getValue()

obj.setValue (Repli(Chr(0), 16384))
? obj.getAddr(), "|", obj.getAllocSize()

RELEASE obj

DEFINE CLASS DynaString As Custom
	PROTECTED hMem, strValue

PROCEDURE  Init (lcString)
	THIS.hMem = 0
	THIS.strValue = ""
	THIS.setValue (lcString)

PROCEDURE  Destroy
	THIS.ReleaseString

FUNCTION   getAddr
RETURN  THIS.hMem

FUNCTION   getValue
RETURN  THIS.strValue

FUNCTION  getAllocSize
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE  setValue (lcString)
	IF TYPE("lcString")<>"C"
		RETURN
	ENDIF
#DEFINE GMEM_FIXED   0
	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	THIS.ReleaseString
	THIS.strValue = lcString
	THIS.hMem = GlobalAlloc (GMEM_FIXED, Len(THIS.strValue))
ENDPROC

PROCEDURE  ReleaseString
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
		THIS.strValue = ""
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  

## Comment:
Instances of this class are similar to long strings. There is one more parameter -- a pointer to the string -- which is useful in some interactions with Win32 structures.  
  
To have this code compatible with VFP3, I do not use read-only properties.  
  
***  

