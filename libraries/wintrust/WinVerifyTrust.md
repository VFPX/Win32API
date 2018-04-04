[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinVerifyTrust
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [wintrust](../../Libraries.md#wintrust)  
***  


#### Performs a trust verification action on a specified object. The function passes the inquiry to a trust provider that supports the action identifier, if one exists.
***  


## Code examples:
[Verifying a file using the Authenticode policy provider](../../samples/sample_569.md)  

## Declaration:
```foxpro  
LONG WINAPI WinVerifyTrust(
  __in  HWND hWnd,
  __in  GUID *pgActionID,
  __in  LPVOID pWVTData
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG WinVerifyTrustIN wintrust;
	LONG hWnd,
	STRING pgActionID,
	STRING pWVTData  
```  
***  


## Parameters:
hWnd [in]
Optional handle to a caller window.

pgActionID [in]
A pointer to a GUID structure that identifies an action and the trust provider that supports that action. This value indicates the type of verification action to be performed on the structure pointed to by pWinTrustData.

pWVTData [in]
A pointer that, when cast as a WINTRUST_DATA structure, contains information that the trust provider needs to process the specified action identifier. Typically, the structure includes information that identifies the object that the trust provider must evaluate.  
***  


## Return value:
If the trust provider verifies that the subject is trusted for the specified action, the return value is zero.  
***  


## Comments:
The Software Publisher Trust Provider can verify that an executable image file comes from a trusted software publisher and that the file has not been modified since it was published.   
  
In this case, the pWinTrustData parameter specifies the name of the file and the type of file, such as a Microsoft Portable Executable image file or a Java class file.  
  
***  

