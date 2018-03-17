<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ChrCmpI
Group: Shell Lightweight Utility APIs -- string functions - Library: shlwapi    
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
```txt  
w1
First character to be compared.

w2
Second character to be compared.  
```  
***  


## Return value:
Returns zero if the two characters are the same, or nonzero otherwise.  
***  

