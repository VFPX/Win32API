[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving statistics for the TCP protocol running on the local computer

## Code:
```foxpro  
DO decl

*| typedef struct _MIB_TCPSTATS {
*|   DWORD   dwRtoAlgorithm;    // time-out algorithm       0:4
*|   DWORD   dwRtoMin;          // minimum time-out         4:4
*|   DWORD   dwRtoMax;          // maximum time-out         8:4
*|   DWORD   dwMaxConn;         // maximum connections     12:4
*|   DWORD   dwActiveOpens;     // active opens            16:4
*|   DWORD   dwPassiveOpens;    // passive opens           20:4
*|   DWORD   dwAttemptFails;    // failed attempts         24:4
*|   DWORD   dwEstabResets;     // established conn.reset  28:4
*|   DWORD   dwCurrEstab;       // established connections 32:4
*|   DWORD   dwInSegs;          // segments received       36:4
*|   DWORD   dwOutSegs;         // segment sent            40:4
*|   DWORD   dwRetransSegs;     // segments retransm.      44:4
*|   DWORD   dwInErrs;          // incoming errors         48:4
*|   DWORD   dwOutRsts;         // outgoing resets         52:4
*|   DWORD   dwNumConns;        // cumulative connections  56:4
*| } MIB_TCPSTATS, *PMIB_TCPSTATS; total bytes = 60

#DEFINE MIB_TCPSTATS_SIZE  60
#DEFINE NO_ERROR            0

PRIVATE lcBuffer
lcBuffer = Repli(Chr(0), MIB_TCPSTATS_SIZE)

IF GetTcpStatistics (@lcBuffer) = NO_ERROR
	DO DisplayTcpStat
ENDIF

PROCEDURE  DisplayTcpStat
	CREATE CURSOR cs (name C(80), prm N(12))
	= AddParam ( 1, "Retransmission time-out (RTO) algorithm in use:")
	= AddParam ( 5, "Minimum retransmission time-out value, msec:")
	= AddParam ( 9, "Maximum retransmission time-out value, msec:")
	= AddParam (13, "Maximum number of connections:")
	= AddParam (17, "Number of active opens:")
	= AddParam (21, "Number of passive opens:")
	= AddParam (25, "Number of failed connection attempts:")
	= AddParam (29, "Number of established connections that have been reset:")
	= AddParam (33, "Number of currently established connections:")
	= AddParam (37, "Number of segments received:")
	= AddParam (41, "Number of segments transmitted:")
	= AddParam (45, "Number of segments retransmitted:")
	= AddParam (49, "Number of errors received")
	= AddParam (53, "Number of segments transmitted with the reset flag set")
	= AddParam (57, "Specifies the cumulative number of connections:")
	GO TOP
	BROWSE NORMAL NOWAIT
RETURN

PROCEDURE  AddParam (lnOffs, lcMsg)
	INSERT INTO cs VALUES (lcMsg, buf2dword(SUBSTR(lcBuffer, lnOffs,4)))
RETURN

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER GetTcpStatistics IN iphlpapi STRING @pStats  
```  
***  


## Listed functions:
[GetTcpStatistics](../libraries/iphlpapi/GetTcpStatistics.md)  
