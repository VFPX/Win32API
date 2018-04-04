[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeSeekDatabase
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function seeks the specified record in an open database.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
CEOID CeSeekDatabase(
  HANDLE hDatabase,
  DWORD dwSeekType,
  DWORD dwValue,
  LPDWORD lpdwIndex
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeSeekDatabase IN rapi;
	INTEGER   hDatabase,;
	INTEGER   dwSeekType,;
	INTEGER   dwValue,;
	INTEGER @ lpdwIndex
  
```  
***  


## Parameters:
hDatabase 
[in] Handle to the open database in which to seek. 

dwSeekType 
[in] Specifies the type of seek operation to perform.

dwValue 
[in] Specifies the value to use for the seek operation. The meaning of this parameter depends on the value of dwSeekType. 

lpdwIndex 
[out] Pointer to a variable that receives the index from the start of the database to the beginning of the record that was found.
  
***  


## Return value:
The object identifier of the record on which the seek ends indicates success.  
***  


## Comments:
The CeSeekDatabase (RAPI) function always uses the current sort order as specified in the call to the CeOpenDatabase (RAPI) function.   
  
If the CEDB_AUTOINCREMENT flag was specified, an automatic seek of one from the current position is done with each read operation that occurs on the database.  
  
***  

