[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving current user for the process

## Before you begin:
See also:

* [Function GetUserName](../libraries/advapi32/GetUserName.md)   
* [Function IsUserAnAdmin](../libraries/shell32/IsUserAnAdmin.md)
* [Finding out if the current user is the Guest account](sample_566.md)  
  
***  


## Code:
```foxpro  
#DEFINE NO_ERROR 0

DECLARE INTEGER IsUserAnAdmin IN shell32

DECLARE INTEGER WNetGetUser IN mpr;
	INTEGER lpName, STRING @lpUserName, INTEGER @lpnLength

LOCAL lcUser, lnBufsize
lnBufsize = 250
lcUser = Repli(Chr(0), lnBufsize)

IF WNetGetUser(0, @lcUser, @lnBufsize) = NO_ERROR
	? "Default user name:", SUBSTR(lcUser, 1, AT(Chr(0),lcUser)-1)
	? "Is user and admin:", Iif(IsUserAnAdmin()=0, "No", "Yes")
ENDIF  
```  
***  


## Listed functions:
[IsUserAnAdmin](../libraries/shell32/IsUserAnAdmin.md)  
[WNetGetUser](../libraries/mpr/WNetGetUser.md)  
