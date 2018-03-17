<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RollbackTransaction
Group: Kernel Transaction Manager - Library: ktmw32    
***  


#### Requests that the specified transaction be rolled back. This function is synchronous.
***  


## Code examples:
[Copying files as a transacted operation (Vista)](../../samples/sample_540.md)  

## Declaration:
```foxpro  
BOOL WINAPI RollbackTransaction(
  __in  HANDLE TransactionHandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RollbackTransaction IN KtmW32;
	INTEGER TransactionHandle  
```  
***  


## Parameters:
```txt  
TransactionHandle
A handle to the transaction.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Requires Windows Vista.  
  
See also: CreateTransaction, CommitTransaction   
  
***  

