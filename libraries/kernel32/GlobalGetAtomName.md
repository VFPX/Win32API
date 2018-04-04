[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalGetAtomName
Group: [Atom](../../functions_group.md#Atom)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
nAtom 
[in] Identifies the global atom associated with the character string to be retrieved. 

lpBuffer 
[out] Pointer to the buffer for the character string. 

nSize 
[in] Specifies the size, in TCHARs, of the buffer.  
***  


## Return value:
If the function succeeds, the return value is the length of the string copied to the buffer. If the function fails, the return value is zero. 
  
***  

