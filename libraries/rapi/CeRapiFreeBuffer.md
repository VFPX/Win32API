[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRapiFreeBuffer
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function frees the memory on the desktop computer allocated by a call to CeFindAllDatabases, CeFindAllFiles, or CeReadRecordProps. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
HRESULT CeRapiFreeBuffer(
  LPVOID Buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRapiFreeBuffer IN rapi;
	INTEGER Buffer  
```  
***  


## Parameters:
Buffer 
[in] Pointer to the buffer to be freed.   
***  


## Return value:
S_OK (0) indicates success.  
***  


## Comments:
Any RAPI function that allocates memory on the desktop computer on the behalf of the user must be freed by calling the CeRapiFreeBuffer function.  
  
***  

