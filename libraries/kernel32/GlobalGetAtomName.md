<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GlobalGetAtomName
Group: Atom - Library: kernel32    
***  


#### Retrieves a copy of the character string associated with the specified global atom.
***  


## Code examples:
[Retrieving list of Global Atom names](../../samples/sample_116.md)  

## Declaration:
```foxpro  
UINT GlobalGetAtomName(
  ATOM nAtom,       // atom identifier
  LPTSTR lpBuffer,  // buffer for atom string
  int nSize         // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalGetAtomName IN kernel32;
	INTEGER  nAtom,;
	STRING @ lpBuffer,;
	INTEGER  nSize  
```  
***  


## Parameters:
```txt  
nAtom
[in] Identifies the global atom associated with the character string to be retrieved.

lpBuffer
[out] Pointer to the buffer for the character string.

nSize
[in] Specifies the size, in TCHARs, of the buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is the length of the string copied to the buffer. If the function fails, the return value is zero. 
  
***  

