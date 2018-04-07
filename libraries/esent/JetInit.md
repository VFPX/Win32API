[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetInit
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Puts the database engine into a state where it can support application use of database files.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetInit(
  __in_out_opt  JET_INSTANCE* pinstance
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetInit IN esent;
	INTEGER @pinstance  
```  
***  


## Parameters:
pinstance 
The instance to use for this call.
  
***  


## Return value:
This function returns the JET_ERR datatype with one of predefined return codes (e.g. JET_errSuccess=0).  
***  


## Comments:
For Windows 2000, <Em>pinstance</Em> parameter is ignored and should always be NULL.   
  
See also: [JetTerm](../esent/JetTerm.md), [JetCreateInstance](../esent/JetCreateInstance.md).  
  
***  

