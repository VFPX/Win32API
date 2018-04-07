[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserGeoID
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about the geographical location of the user.
***  


## Declaration:
```foxpro  
GEOID GetUserGeoID(
  _In_  GEOCLASS GeoClass
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserGeoID IN kernel32;
	INTEGER GeoClass  
```  
***  


## Parameters:
GeoClass [in]
Geographical location class to return. Possible values are defined by the SYSGEOCLASS enumeration.  
***  


## Return value:
Returns the geographical location identifier of the user if SetUserGeoID has been called before to set the identifier.  
***  


## Comments:
See also: [SetUserGeoID](../kernel32/SetUserGeoID.md).  
  
<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd374073(v=vs.85).aspx">Table of Geographical Locations</a>  
  
***  

