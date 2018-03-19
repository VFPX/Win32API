[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the name of the network resource associated with a local device

## Code:
```foxpro  
#DEFINE NO_ERROR 0

DECLARE INTEGER WNetGetConnection IN mpr;
	STRING lpLocalName, STRING @lpRemoteName,;
	INTEGER @lpnLength

LOCAL cBuffer, nBufsize, nResult
nBufsize = 250
cBuffer = REPLICATE(CHR(0), nBufsize)

nResult = WNetGetConnection(;
	"Z:", @cBuffer, @nBufsize)

IF nResult <> NO_ERROR
* ERROR_MORE_DATA = 234
* ERROR_BAD_DEVICE = 1200
* ERROR_NOT_CONNECTED = 2250
* ERROR_NO_NETWORK = 1222

	? "Error code:", nResult

ELSE
	? "Remote name:",;
		LEFT(cBuffer, AT(CHR(0),cBuffer)-1)
ENDIF  
```  
***  


## Listed functions:
[WNetGetConnection](../libraries/mpr/WNetGetConnection.md)  
