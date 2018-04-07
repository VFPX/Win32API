[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateTransaction
Group: [Kernel Transaction Manager](../../functions_group.md#Kernel_Transaction_Manager)  -  Library: [ktmw32](../../Libraries.md#ktmw32)  
***  


#### Creates a new file system transaction object.
***  


## Code examples:
[Copying files as a transacted operation (Vista)](../../samples/sample_540.md)  

## Declaration:
```foxpro  
HANDLE WINAPI CreateTransaction(
  __in_opt  LPSECURITY_ATTRIBUTES lpTransactionAttributes,
  __in_opt  LPGUID UOW,
  __in_opt  DWORD CreateOptions,
  __in_opt  DWORD IsolationLevel,
  __in_opt  DWORD IsolationFlags,
  __in_opt  DWORD Timeout,
  __in_opt  LPWSTR Description
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateTransaction IN KtmW32;
	INTEGER lpTransactionAttributes,;
	INTEGER UOW,;
	INTEGER CreateOptions,;
	INTEGER IsolationLevel,;
	INTEGER IsolationFlags,;
	INTEGER Timeout,;
	STRING @Description  
```  
***  


## Parameters:
lpTransactionAttributes 
A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes.

UOW 
Reserved. Must be zero (0).

CreateOptions 
Any optional transaction instructions.

IsolationLevel 
Reserved; specify zero (0).

IsolationFlags 
Reserved; specify zero (0).

Timeout 
The time, in milliseconds, when the transaction will be aborted if it has not already reached the prepared state.

Description 
A user-readable description of the transaction.  
***  


## Return value:
If fails returns INVALID_HANDLE_VALUE (-1). Otherwise retrurns a handle to the transaction.  
***  


## Comments:
Requires Windows Vista. Allows conducting various file operations protected by transactions: creating, copying, moving, deleting and more.  
  
See also: [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md).  
  
***  

