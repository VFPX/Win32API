<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetInit
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
pinstance
The instance to use for this call.
  
```  
***  


## Return value:
This function returns the JET_ERR datatype with one of predefined return codes (e.g. JET_errSuccess=0).  
***  


## Comments:
For Windows 2000, <Em>pinstance</Em> parameter is ignored and should always be NULL.   
  
See also: JetTerm, JetCreateInstance   
  
***  

