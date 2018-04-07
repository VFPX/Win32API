[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsWellKnownSid
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Compares a SID to a well known SID and returns TRUE if they match.

***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
BOOL IsWellKnownSid(
	PSID pSid,
	WELL_KNOWN_SID_TYPE WellKnownSidType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsWellKnownSid IN Advapi32;
	INTEGER pSid,;
	INTEGER WellKnownSidType  
```  
***  


## Parameters:
pSid 
[in] Pointer to the SID to test. 

WellKnownSidType 
[in] Member of the WELL_KNOWN_SID_TYPE enumeration to compare with the SID at pSid.   
***  


## Return value:
Returns TRUE if the SID at pSid matches the well known SID indicated by WellKnownSidType.  
***  


## Comments:
The WELL_KNOWN_SID_TYPE enumeration type is a list of commonly used security identifiers (SIDs).  
Dec.29, 2006: members from 0 to 60.  
  
See also: [CreateWellKnownSid](..//CreateWellKnownSid.md).  
  
***  

