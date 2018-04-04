[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetScheduleJobDel
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetScheduleJobDel function deletes a range of jobs queued to run at a computer.
***  


## Code examples:
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetScheduleJobDel(
  LPCWSTR Servername,
  DWORD MinJobId,
  DWORD MaxJobId
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT NetScheduleJobDel IN netapi32;
	STRING  Servername,;
	INTEGER MinJobId,;
	INTEGER MaxJobId
  
```  
***  


## Parameters:
Servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. 

MinJobId 
[in] Specifies a minimum job identifier. Jobs with a job identifier smaller than MinJobId will not be deleted. 

MaxJobId 
[in] Specifies a maximum job identifier. Jobs with a job identifier larger than MaxJobId will not be deleted.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
This function requires that the schedule service be started at the computer to which the job deletion request is being sent.  
  
Only members of the Administrators local group can successfully execute the NetScheduleJobDel function on a remote server.  
  
The NetScheduleJobDel function deletes all jobs whose job identifiers are in the range MinJobId through MaxJobId.  
  
To delete all scheduled jobs at the server, you can call NetScheduleJobDel specifying MinJobId equal to 0 and MaxJobId equal to – 1. To delete one job, specify the job"s identifier for both the MinJobId parameter and the MaxJobId parameter.  
  
***  

