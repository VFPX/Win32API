[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetBeginSession
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Starts new ESE session and initializes and returns an ESE session handle 
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetBeginSession(
  __in          JET_INSTANCE instance,
  __out         JET_SESID* psesid,
  __in_opt      JET_PCSTR szUserName,
  __in_opt      JET_PCSTR szPassword
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetBeginSession IN esent;
	INTEGER instance,;
	INTEGER @psesid,;
	INTEGER szUserName,;
	INTEGER szPassword  
```  
***  


## Parameters:
instance 
The database instance to use for this call.

psesid 
Pointer to the variable that the session handle initializes on successful return.

szUserName 
This parameter is reserved.

szPassword 
This parameter is reserved.

  
***  


## Return value:
This function allows for the return of any JET_ERRs that are defined in this API.  
***  


## Comments:
Sessions control all access to the database and are used to control the scope of transactions. The session can be used to begin, commit, or abort transactions.   
  
The session is also used to attach, create, or open a database. To increase concurrency and parallel access to the database, multiple sessions can be begun.  
  
See also: [JetEndSession](../esent/JetEndSession.md).  
  
***  

