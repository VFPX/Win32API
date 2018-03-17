<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetFileSecurity
Group: Security - Library: advapi32    
***  


#### The GetFileSecurity function obtains specified information about the security of a file or directory. 
***  


## Code examples:
[Creating a folder](../../samples/sample_001.md)  
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
BOOL GetFileSecurity(
  LPCTSTR lpFileName,
  SECURITY_INFORMATION RequestedInformation,
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  DWORD nLength,
  LPDWORD lpnLengthNeeded
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileSecurity IN advapi32;
	STRING    lpFileName,;
	INTEGER   RequestedInformation,;
	STRING  @ pSecurityDescriptor,;
	INTEGER   nLength,;
	INTEGER @ lpnLengthNeeded
  
```  
***  


## Parameters:
```txt  
lpFileName
[in] Pointer to a null-terminated string that specifies the file or directory for which security information is retrieved.

pSecurityDescriptor
[out] Pointer to a buffer that receives a copy of the security descriptor of the object specified by the lpFileName parameter.

nLength
[in] Specifies the size, in bytes, of the buffer pointed to by the pSecurityDescriptor parameter.

lpnLengthNeeded
[out] Pointer to the variable that receives the number of bytes necessary to store the complete security descriptor.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If the function fails, the return value is zero. To get extended error information, call GetLastError.  
  
The GetNamedSecurityInfo function provides functionality similar to GetFileSecurity for files as well as other types of objects.  
  
***  

