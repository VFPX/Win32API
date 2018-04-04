[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumJobs
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumJobs function retrieves information about a specified set of print jobs for a specified printer. 
***  


## Code examples:
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  

## Declaration:
```foxpro  
BOOL EnumJobs(
  HANDLE hPrinter,    // handle to printer object
  DWORD FirstJob,     // index of first job
  DWORD NoJobs,       // number of jobs to enumerate
  DWORD Level,        // information level
  LPBYTE pJob,        // job information buffer
  DWORD cbBuf,        // size of job information buffer
  LPDWORD pcbNeeded,  // bytes received or required
  LPDWORD pcReturned  // number of jobs received
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumJobs IN winspool.drv;
	INTEGER   hPrinter,;
	INTEGER   FirstJob,;
	INTEGER   NoJobs,;
	INTEGER   Lvl,;
	INTEGER   pJob,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer object whose print jobs the function enumerates. Use the OpenPrinter or AddPrinter function to retrieve a printer handle. 

FirstJob 
[in] Specifies the zero-based position within the print queue of the first print job to enumerate. 

NoJobs 
[in] Specifies the total number of print jobs to enumerate. 

Level 
[in] Specifies the type of information returned in the pJob buffer. 

pJob 
[out] Pointer to a buffer that receives an array of JOB_INFO_1, JOB_INFO_2, or JOB_INFO_3 structures, depending on Level value.

cbBuf 
[in] Specifies the size, in bytes, of the pJob buffer. 

pcbNeeded 
[out] Pointer to a variable that receives the number of bytes copied if the function succeeds.

pcReturned 
[out] Pointer to a variable that receives the number of JOB_INFO_1, JOB_INFO_2, or JOB_INFO_3 structures returned in the pJob buffer.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The JOB_INFO_1 structure contains general print-job information; the JOB_INFO_2 structure has much more detailed information. The JOB_INFO_3 structure contains information about how jobs are linked.  
  
To determine the number of print jobs in the printer queue, call the GetPrinter function with the Level parameter set to 2.  
  
***  

