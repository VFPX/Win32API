[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetUserGeoID
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the geographical location identifier for the user. This identifier should have one of the values described in Table of Geographical Locations.
***  


## Declaration:
```foxpro  
BOOL SetUserGeoID(
  _In_  GEOID GeoId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetUserGeoID IN kernel32;
	INTEGER GeoId  
```  
***  


## Parameters:
GeoId [in]
Identifier for the geographical location of the user.  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
See also: [GetUserGeoID](../kernel32/GetUserGeoID.md).  
  
<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd374073(v=vs.85).aspx">Table of Geographical Locations</a>  
  
***  

