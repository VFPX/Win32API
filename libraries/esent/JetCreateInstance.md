<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetCreateInstance
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
pinstance
The output buffer that receives the newly-created instance.

szInstanceName
A unique string identifier for the instance to be created. This string must be unique within a given process hosting the database engine.
  
```  
***  


## Return value:
This function returns the JET_ERR datatype with one of predefined return codes (e.g. JET_errSuccess=0).  
***  


## Comments:
W2K: not supported.  
  
See also: JetInit, JetTerm   
  
***  

