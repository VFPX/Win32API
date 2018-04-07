[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetCreateInstance
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Allocates a new instance of the database engine for use in a single process.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCreateInstance(
  __out         JET_INSTANCE* pinstance,
  __in_opt      const tchar* szInstanceName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCreateInstance IN esent;
	INTEGER @pinstance,;
	STRING szInstanceName  
```  
***  


## Parameters:
pinstance 
The output buffer that receives the newly-created instance.

szInstanceName 
A unique string identifier for the instance to be created. This string must be unique within a given process hosting the database engine.
  
***  


## Return value:
This function returns the JET_ERR datatype with one of predefined return codes (e.g. JET_errSuccess=0).  
***  


## Comments:
W2K: not supported.  
  
See also: [JetInit](../esent/JetInit.md), [JetTerm](../esent/JetTerm.md).  
  
***  

