[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetScheduleJobAdd
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Submits a job to run at a specified future time and date.

***  


## Code examples:
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetScheduleJobAdd(
	LPCWSTR Servername,
	LPBYTE Buffer,
	LPDWORD JobId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT NetScheduleJobAdd IN netapi32;
	STRING    Servername,;
	STRING  @ Buffer,;
	INTEGER @ JobId  
```  
***  


## Parameters:
Servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

Buffer 
[in] Pointer to an AT_INFO structure describing the job to submit. 

JobId 
[out] Pointer that receives a job identifier for the newly submitted job. This entry is valid only if the function returns successfully.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
This function requires that the schedule service be started at the computer to which the job is submitted.  
  
Only members of the Administrators local group can successfully execute the NetScheduleJobAdd function on a remote server.  
  
***  

