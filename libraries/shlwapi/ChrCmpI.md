[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ChrCmpI
Group: [Shell Lightweight Utility APIs -- string functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_string_functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Performs a comparison between two characters. The comparison is not case sensitive.
***  


## Declaration:
```foxpro  
BOOL ChrCmpIW(
    WCHAR w1,
    WCHAR w2
    );

BOOL ChrCmpIA(
    WORD w1,
    WORD w2
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ChrCmpIA IN Shlwapi;
As ChrCmpI;
	SHORT w1, SHORT w2
  
```  
***  


## Parameters:
w1 
First character to be compared. 

w2 
Second character to be compared.   
***  


## Return value:
Returns zero if the two characters are the same, or nonzero otherwise.  
***  

