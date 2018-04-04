[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The LoadResource function loads the specified resource into global memory.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
HGLOBAL LoadResource(
	HMODULE hModule,
	HRSRC hResInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadResource IN kernel32;
	INTEGER hModule,;
	INTEGER hResInfo
  
```  
***  


## Parameters:
hModule
[in] Handle to the module whose executable file contains the resource. 

hResInfo
[in] Handle to the resource to be loaded. This handle is returned by the FindResource or FindResourceEx function.   
***  


## Return value:
If the function succeeds, the return value is a handle to the data associated with the resource.  
***  


## Comments:
If <Em>hModule</Em> is NULL, the system loads resource from the module that was used to create current process.   
  
* * *  
I am thinking about approaches to design of VFP application with auto-updateable executable, the master copy of which is stored on a web server. Definitely I am not the first person doing this -- read Rick Strahl`s article <a href="http://www.west-wind.com/presentations/wwCodeUpdate/codeupdate.asp">Automatic Application Updates over the Web with Visual FoxPro 7.0</a> -- so my thoughts may not be precisely original.  
  
Normally Windows executable can not update itself. That means it needs help from another process; let`s call this one the Updating Process.   
  
Six tasks for UP to get done:  
- connect to the web server and check for updates  
- check and terminate all processes originated from the main executable, ME  
- download new version of ME from the web server  
- overwrite ME  
- restart ME  
- terminate itself  
  
For reasons of mobility UP executable can be stored as a binary resource inside ME. It is doable. ME can use something like LoadResource plus CopyMemory plus STRTOFILE() plus CreateProcess to invoke UP.  
  
***  

