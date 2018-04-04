[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetJob
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The SetJob function pauses, resumes, cancels, or restarts a print job on a specified printer. You can also use the SetJob function to set print job parameters, such as the print job priority and the document name. 
***  


## Code examples:
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  

## Declaration:
```foxpro  
BOOL SetJob(
  HANDLE hPrinter,  // handle to printer object
  DWORD JobId,      // print job identifier
  DWORD Level,      // information level
  LPBYTE  pJob,     // job information buffer
  DWORD Command     // job command value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetJob IN winspool.drv;
	INTEGER hPrinter,;
	INTEGER JobId,;
	INTEGER lvl,;
	INTEGER pJob,;
	INTEGER cmd
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer object of interest. Use the OpenPrinter or AddPrinter function to retrieve a printer handle.

JobId 
[in] Identifier that specifies the print job.

Level 
[in] Specifies the type of job information structure pointed to by the pJob parameter: 0, 1, 2

pJob 
[in] Pointer to a JOB_INFO_1 or JOB_INFO_2 or JOB_INFO_3 structure. 

Command 
[in] Specifies the print job operation to perform.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
You must have PRINTER_ACCESS_ADMINISTER access permission for a printer in order to change a print job"s position in the print queue.   
  
To remove or delete all of the print jobs for a particular printer, call the SetPrinter function with its Command parameter set to PRINTER_CONTROL_PURGE.   
  
***  

