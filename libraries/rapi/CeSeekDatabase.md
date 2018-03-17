<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeSeekDatabase
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
hDatabase
[in] Handle to the open database in which to seek.

dwSeekType
[in] Specifies the type of seek operation to perform.

dwValue
[in] Specifies the value to use for the seek operation. The meaning of this parameter depends on the value of dwSeekType.

lpdwIndex
[out] Pointer to a variable that receives the index from the start of the database to the beginning of the record that was found.
  
```  
***  


## Return value:
The object identifier of the record on which the seek ends indicates success.  
***  


## Comments:
The CeSeekDatabase (RAPI) function always uses the current sort order as specified in the call to the CeOpenDatabase (RAPI) function.   
  
If the CEDB_AUTOINCREMENT flag was specified, an automatic seek of one from the current position is done with each read operation that occurs on the database.  
  
***  

