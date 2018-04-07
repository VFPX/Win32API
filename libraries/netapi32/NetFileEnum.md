[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetFileEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetFileEnum function returns information about some or all open files on a server, depending on the parameters specified.
***  


## Code examples:
[Enumerating files opened on the network](../../samples/sample_121.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetFileEnum(
  LPWSTR servername,
  LPWSTR basepath,
  LPWSTR username,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  PDWORD_PTR resume_handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetFileEnum IN netapi32;
	STRING    servername,;
	STRING    basepath,;
	STRING    username,;
	INTEGER   lvl,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER   resume
  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

basepath 
[in] Pointer to a string that specifies a qualifier for the returned information.

username 
[in] Pointer to a string that specifies the name of the user.

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the address of the buffer that receives the information.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position.

resume_handle 
[in, out] Pointer to a value that contains a resume handle which is used to continue an existing file search.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success.  
***  


## Comments:
You can call the NetFileGetInfo function to retrieve information about a particular opening of a server resource.  
  
See also: [ReadDirectoryChangesW](../kernel32/ReadDirectoryChangesW.md).  
  
  
***  

