[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeviceIoControl
Group: [Device Input and Output](../../functions_group.md#Device_Input_and_Output)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sends a control code directly to a specified device driver, causing the corresponding device to perform the corresponding operation.
***  


## Code examples:
[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](../../samples/sample_101.md)  

## Declaration:
```foxpro  
BOOL DeviceIoControl(
  HANDLE hDevice,
  DWORD dwIoControlCode,
  LPVOID lpInBuffer,
  DWORD nInBufferSize,
  LPVOID lpOutBuffer,
  DWORD nOutBufferSize,
  LPDWORD lpBytesReturned,
  LPOVERLAPPED lpOverlapped
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeviceIoControl IN kernel32;
	INTEGER   hDevice,;
	INTEGER   dwIoControlCode,;
	STRING  @ lpInBuffer,;
	INTEGER   nInBufferSize,;
	STRING  @ lpOutBuffer,;
	INTEGER   nOutBufferSize,;
	INTEGER @ lpBytesReturned,;
	INTEGER   lpOverlapped
  
```  
***  


## Parameters:
hDevice 
[in] Handle to the device on which the operation is to be performed.

dwIoControlCode 
[in] Control code for the operation.

lpInBuffer 
[in] Pointer to the input buffer that contains the data required to perform the operation.

nInBufferSize 
[in] Size of the input buffer, in bytes.

lpOutBuffer 
[out] Pointer to the output buffer that is to receive the data returned by the operation.

nOutBufferSize 
[in] Size of the output buffer, in bytes. 

lpBytesReturned 
[out] Pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

lpOverlapped 
[in] Pointer to an OVERLAPPED structure.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
To retrieve a handle to the device, you must call the CreateFile function with either the name of a device or the name of the driver associated with a device.  
  
To specify a device name, use the following format: \\.\DeviceName  
  
Other valid device names:  
\\.\a:  
\\.\PhysicalDrive0  
\\.\PhysicalDrive1  
\\.\vwin32  
  
***  

