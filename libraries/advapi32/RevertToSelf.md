
## Function name : RevertToSelf
Group: Security - Library: advapi32    
***  


#### The RevertToSelf function terminates the impersonation of a client application.
***  


## Code examples:
[How to run FoxPro application under different user name (impersonating user)](../../samples/sample_470.md)  

## Declaration:
```foxpro  
BOOL RevertToSelf(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RevertToSelf IN advapi32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A process should call the RevertToSelf function after finishing any impersonation begun by using the DdeImpersonateClient, ImpersonateDdeClientWindow, ImpersonateLoggedOnUser, ImpersonateNamedPipeClient, ImpersonateSelf, ImpersonateAnonymousToken or SetThreadToken function.  
  
***  

