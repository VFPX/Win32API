[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrCmpC
Group: [String](../../functions_group.md#String)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Compares strings using C run-time (ASCII) collation rules. The comparison is case-sensitive.
***  


## Declaration:
```foxpro  
int StrCmpC(
	__out  LPCTSTR lpStr1,
	__out  LPCTSTR lpStr2
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrCmpC IN Shlwapi;
	STRING @cStr1,;
	STRING @cStr2  
```  
***  


## Parameters:
lpStr1 [out]
LPCTSTR
A pointer to the first null-terminated string to be compared.

lpStr2 [out]
LPCTSTR
A pointer to the second null-terminated string to be compared.  
***  


## Return value:
Returns zero if the strings are identical. 

Returns a positive value if the string pointed to by lpStr1 is alphabetically greater than that pointed to by lpStr2. 

Returns a negative value if the string pointed to by lpStr1 is alphabetically less than that pointed to by lpStr2.  
***  

