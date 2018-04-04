[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetScheduleJobEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Lists the jobs queued on a specified computer. 
***  


## Code examples:
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetScheduleJobEnum(
	LPCWSTR Servername,
	LPBYTE* PointerToBuffer,
	DWORD PreferredMaximumLength,
	LPDWORD EntriesRead,
	LPDWORD TotalEntries,
	LPDWORD ResumeHandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT NetScheduleJobEnum IN netapi32;
	STRING    Servername,;
	INTEGER @ PointerToBuffer,;
	INTEGER   PreferredMaximumLength,;
	INTEGER @ EntriesRead,;
	INTEGER @ TotalEntries,;
	INTEGER   ResumeHandle
  
```  
***  


## Parameters:
Servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

PointerToBuffer 
[out] Pointer to the buffer that receives the data. The return information is an array of AT_ENUM structures. 

PreferredMaximumLength 
[in] Specifies a value that indicates the preferred maximum length of the returned data, in bytes.

EntriesRead 
[out] Pointer to a value that receives the count of elements actually enumerated. 

TotalEntries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. 

ResumeHandle 
[in, out] Pointer to a value that contains a resume handle which is used to continue a job enumeration.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
This function requires that the schedule service be started.  
  
The <Em>PointerToBuffer</Em> is allocated by the system and must be freed using a single call to the NetApiBufferFree function.   
  
Only members of the Administrators local group can successfully execute the NetScheduleJobEnum function on a remote server.  
  
***  

