[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving IP statistics for the computer

## Code:
```foxpro  
#DEFINE NO_ERROR  0
DECLARE INTEGER GetIpStatistics IN iphlpapi STRING @pStats

*| typedef struct _MIB_IPSTATS {
*|   DWORD   dwForwarding;       //  0:IP forwarding enabled or disabled
*|   DWORD   dwDefaultTTL;       //  1:default time-to-live
*|   DWORD   dwInReceives;       //  2:datagrams received
*|   DWORD   dwInHdrErrors;      //  3:received header errors
*|   DWORD   dwInAddrErrors;     //  4:received address errors
*|   DWORD   dwForwDatagrams;    //  5:datagrams forwarded
*|   DWORD   dwInUnknownProtos;  //  6:datagrams with unknown protocol
*|   DWORD   dwInDiscards;       //  7:received datagrams discarded
*|   DWORD   dwInDelivers;       //  8:received datagrams delivered
*|   DWORD   dwOutRequests;      //  9:
*|   DWORD   dwRoutingDiscards;  // 10:
*|   DWORD   dwOutDiscards;      // 11:sent datagrams discarded
*|   DWORD   dwOutNoRoutes;      // 12:datagrams for which no route exists
*|   DWORD   dwReasmTimeout;     // 13:datagrams for which all
*|                               //   frags did not arrive
*|   DWORD   dwReasmReqds;       // 14:datagrams requiring re-assembly
*|   DWORD   dwReasmOks;         // 15:successful re-assemblies
*|   DWORD   dwReasmFails;       // 16:failed re-assemblies
*|   DWORD   dwFragOks;          // 17:successful fragmentations
*|   DWORD   dwFragFails;        // 18:failed fragmentations
*|   DWORD   dwFragCreates;      // 19:datagrams fragmented
*|   DWORD   dwNumIf;            // 20:number of interfaces on computer
*|   DWORD   dwNumAddr;          // 21:number of IP address on computer
*|   DWORD   dwNumRoutes;        // 22:number of routes in routing table
*| } MIB_IPSTATS, *PMIB_IPSTATS; total bytes = 23 x 4 = 92
#DEFINE MIB_IPSTATS_SIZE  92

PRIVATE lcBuffer
lcBuffer = Repli(Chr(0), MIB_IPSTATS_SIZE)

LOCAL lnResult
lnResult = GetIpStatistics (@lcBuffer)

IF lnResult <> NO_ERROR
	? "Error code:", lnResult
	RETURN
ENDIF

CREATE CURSOR csResult (paramname C(50), paramvalue N(16))
= SaveParam ("IP forwarding enabled or disabled", 0)
= SaveParam ("Default time to live", 1)
= SaveParam ("Datagrams received", 2)
= SaveParam ("Received header errors", 3)
= SaveParam ("Received address errors", 4)
= SaveParam ("Datagrams forwarded", 5)
= SaveParam ("Datagrams with unknown protocol", 6)
= SaveParam ("Received datagrams discarded", 7)
= SaveParam ("Received datagrams delivered", 8)
= SaveParam ("Outgoing datagrams that IP is requested to transmit", 9)
= SaveParam ("Outgoing datagrams discarded", 10)
= SaveParam ("Sent datagrams discarded", 11)
= SaveParam ("Datagrams for which no route exists", 12)
= SaveParam ("Datagrams for which all frags did not arrive", 13)
= SaveParam ("Datagrams requiring re-assembly", 14)
= SaveParam ("Successful re-assemblies", 15)
= SaveParam ("Failed re-assemblies", 16)
= SaveParam ("Successful fragmentations", 17)
= SaveParam ("Failed fragmentations", 18)
= SaveParam ("Datagrams fragmented", 19)
= SaveParam ("Number of interfaces", 20)
= SaveParam ("Number of IP addresses", 21)
= SaveParam ("Number of routes in routing table", 22)

GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE  SaveParam (lcName, lnDwordOffs)
	INSERT INTO csResult VALUES (lcName,;
		buf2dword(SUBSTR(lcBuffer, lnDwordOffs*4+1,4)))

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetIpStatistics](../libraries/iphlpapi/GetIpStatistics.md)  
