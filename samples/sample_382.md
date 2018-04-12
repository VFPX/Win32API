[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to ping a remote site using IP Helper API calls

## Before you begin:
An article "**A New Way to Ping**" published on <a href="http://www.codeguru.com/internet/NewPing.html">CodeGuru</a> pages by <a href="mailto:billnolde@ieee.org">Bill Nolde</a> is a source for this example, which is a direct C++ to VFP translation.  

Another [example](sample_216.md) shows how to convert a host name (*like "www.myhost.com", "microsoft.com", "aol.com" etc.*) to IP address in dotted format (like 192.168.0.1).  

See also:

* [How to ping a remote site using ICMP API calls](sample_486.md)  
* [How to retrieve adapter information for the local computer (including MAC address)](sample_347.md)  
* [Obtaining addresses for the adapters on the local computer (Win XP/2003/Vista)](sample_506.md)  
* [Using NetWkstaTransportEnum to obtain MAC Address of remote server](sample_435.md)  
  
***  


## Code:
```foxpro  
DO declare

LOCAL nDst, nHop, nRTT
nDst = inet_addr("212.58.244.67")  && bbc news

STORE 0 TO nHop, nRTT

IF GetRTTAndHopCount(nDst, @nHop, 50, @nRTT) <> 0
	? "Hop count to the destination:", nHop
	? "Round-trip time, in milliseconds:", nRTT
ELSE
* on error, GetLastError may still return zero
	? "Error"
ENDIF
* end of main

PROCEDURE declare
	DECLARE INTEGER GetRTTAndHopCount IN Iphlpapi;
		INTEGER DestIpAddress, LONG @HopCount,;
		INTEGER MaxHops, LONG @RTT

	DECLARE INTEGER inet_addr IN ws2_32 STRING cp  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetRTTAndHopCount](../libraries/iphlpapi/GetRTTAndHopCount.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  
