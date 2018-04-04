[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetAce
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Obtains a pointer to an access control entry (ACE) in an access control list (ACL).

***  


## Code examples:
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
BOOL GetAce(
	PACL pAcl,
	DWORD dwAceIndex,
	LPVOID* pAce
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAce IN advapi32;
	INTEGER pAcl,;
	INTEGER dwAceIndex,;
	INTEGER @pAce  
```  
***  


## Parameters:
pAcl 
[in] A pointer to an ACL that contains the ACE to be retrieved. 

dwAceIndex 
[in] The index of the ACE to be retrieved. A value of zero corresponds to the first ACE in the ACL, a value of one to the second ACE, and so on. 

pAce 
[out] A pointer to a pointer that the function sets to the address of the ACE.   
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  

