[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CompareFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CompareFileTime function compares two file times.
***  


## Code examples:
[Comparing file times](../../samples/sample_171.md)  
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  

## Declaration:
```foxpro  
LONG CompareFileTime(
  CONST FILETIME *lpFileTime1,  // first file time
  CONST FILETIME *lpFileTime2   // second file time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CompareFileTime IN kernel32;
	STRING lpFileTime1,;
	STRING lpFileTime2  
```  
***  


## Parameters:
lpFileTime1 
[in] Pointer to a FILETIME structure that specifies the first file time. 

lpFileTime2 
[in] Pointer to a FILETIME structure that specifies the second file time.   
***  


## Return value:
The return value is one of the following values. 

<Strong>Value Meaning</Strong>
–1	First file time is less than second file time. 
&nbsp;0	First file time is equal to second file time. 
&nbsp;1	First file time is greater than second file time. 
  
***  

