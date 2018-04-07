[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CommitTransaction
Group: [Kernel Transaction Manager](../../functions_group.md#Kernel_Transaction_Manager)  -  Library: [ktmw32](../../Libraries.md#ktmw32)  
***  


#### Requests that the specified transaction be committed.
***  


## Code examples:
[Copying files as a transacted operation (Vista)](../../samples/sample_540.md)  

## Declaration:
```foxpro  
BOOL WINAPI CommitTransaction(
  __in  HANDLE TransactionHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CommitTransaction IN KtmW32;
	INTEGER TransactionHandle  
```  
***  


## Parameters:
TransactionHandle 
A handle to the transaction to be committed.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Requires Windows Vista.  
  
See also: [CreateTransaction](../ktmw32/CreateTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md).  
  
***  

