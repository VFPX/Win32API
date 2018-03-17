<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CommitTransaction
Group: Kernel Transaction Manager - Library: ktmw32    
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
```txt  
TransactionHandle
A handle to the transaction to be committed.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Requires Windows Vista.  
  
See also: CreateTransaction, RollbackTransaction   
  
***  

