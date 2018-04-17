[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GetFileOwner - Get the owner of an NTFS file

## Before you begin:
The first version of this code sample was based on VB-to-VFP translation from VB example posted on DevX.com. For a given file the function returns account and domain names in a string.  
  
***  


## Code:
```foxpro  
#DEFINE ERROR_SUCCESS 0
#DEFINE SE_FILE_OBJECT 1
#DEFINE OWNER_SECURITY_INFORMATION 1
DO decl

LOCAL cFile, cDescriptor
cFile = "c:\io.sys"

* use either GetFileSid or GetFileSid1
* to obtain the security descriptor for the file
cDescriptor = GetFileSid(cFile)

IF EMPTY(cDescriptor)
	? "Could not obtain security information. " +;
		"Error code:", GetLastError()
	RETURN
ENDIF

LOCAL nOwner, nOwnerDef, nType, cSystemName,;
	nAccountLen, nDomainLen

STORE 0 TO nOwner, nOwnerDef, nType
IF GetSecurityDescriptorOwner(@cDescriptor,;
	@nOwner, @nOwnerDef) = 0
	? "GetSecurityDescriptorOwner failed. " +;
		"Error code:", GetLastError()
	RETURN
ENDIF

cSystemName = Chr(0)
STORE 255 TO nAccountLen, nDomainLen
STORE Repli(Chr(0),nDomainLen) TO cAccount, cDomain

nResult = LookupAccountSid(@cSystemName, nOwner,;
	@cAccount, @nAccountLen, @cDomain, @nDomainLen, @nType)

IF nResult = 0
	? "LookupAccountSid failed. " +;
		"Error code:", GetLastError()
	RETURN
ELSE
	cAccount = SUBSTR(cAccount, 1, nAccountLen)
	cDomain = SUBSTR(cDomain, 1, nDomainLen)
	? "Account:", cAccount, " Domain:", cDomain
ENDIF
* end of main

FUNCTION GetFileSid(cFile)
* Security descriptor for a given file is obtained
* through GetFileSecurity function
	LOCAL cDescriptor, nBufsize
	cDescriptor = Repli(Chr(0), 256)
	nBufsize = 0

	IF GetFileSecurity(cFile, OWNER_SECURITY_INFORMATION,;
		@cDescriptor, Len(cDescriptor), @nBufsize) = 0
		RETURN ""
	ENDIF
RETURN SUBSTR(cDescriptor, 1, nBufsize)

FUNCTION GetFileSid1(cFile)
* Security descriptor for a given file is obtained
* through GetNamedSecurityInfo function.
* Note that this function is not limited to just files
* but can return security descriptors for other objects
* like services, printers, registry keys, network shares etc.
	LOCAL hDescriptor, nBufsize, cDescriptor
	hDescriptor=0

	IF GetNamedSecurityInfo(cFile, SE_FILE_OBJECT,;
		OWNER_SECURITY_INFORMATION, 0,0,0,0,;
		@hDescriptor) <> ERROR_SUCCESS
		RETURN ""
	ENDIF
	
	nBufsize = LocalSize(hDescriptor)
	IF nBufsize = 0
		RETURN ""
	ELSE
		cDescriptor = REPLICATE(CHR(0), nBufsize)
		MemToStr(@cDescriptor, hDescriptor, nBufsize)
		= LocalFree(hDescriptor)
		RETURN cDescriptor
	ENDIF

PROCEDURE decl
	DECLARE INTEGER GetFileSecurity IN advapi32;
		STRING lpFileName, INTEGER RequestedInformation,;
		STRING @pSecurityDescriptor, INTEGER nLength,;
		INTEGER @lpnLengthNeeded

	DECLARE INTEGER GetSecurityDescriptorOwner IN advapi32;
		STRING @pSecurityDescriptor, INTEGER @pOwner,;
		INTEGER @lpbOwnerDefaulted

	DECLARE INTEGER LookupAccountSid IN advapi32;
		STRING @lpSystemName, INTEGER lpSid,;
		STRING @lpName, INTEGER @cchName,;
		STRING @lpRefdDomain, INTEGER @cchRefdDomain,;
		INTEGER @peUse

	DECLARE INTEGER GetNamedSecurityInfo IN advapi32;
		STRING pObjectName, INTEGER ObjectType, INTEGER SecurityInfo,;
		INTEGER ppsidOwner, INTEGER ppsidGroup, INTEGER ppDacl,;
		INTEGER ppSacl, INTEGER @ppSecurityDescriptor

	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem
	DECLARE LONG LocalSize IN kernel32 INTEGER hMem
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER  
```  
***  


## Listed functions:
[GetFileSecurity](../libraries/advapi32/GetFileSecurity.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetNamedSecurityInfo](../libraries/advapi32/GetNamedSecurityInfo.md)  
[GetSecurityDescriptorOwner](../libraries/advapi32/GetSecurityDescriptorOwner.md)  
[LocalFree](../libraries/kernel32/LocalFree.md)  
[LocalSize](../libraries/kernel32/LocalSize.md)  
[LookupAccountSid](../libraries/advapi32/LookupAccountSid.md)  

## Comment:
A local computer is assumed. Otherwise change *cSystemName* value in the code from Chr(0) to the target computer name (null-terminated). The owner can be a serial port as well.  
  
***  

