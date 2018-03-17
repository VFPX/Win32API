/*++ BUILD Version: 0000     Increment this if a change has global effects

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    esent.h

Abstract:

    This module defines the types and constants that are
    exposed through the ESE API.

--*/

#if _MSC_VER > 1000
#pragma once
#endif

#if !defined(_JET_INCLUDED)
#define _JET_INCLUDED

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef WINVER
#  if ( WINVER >= 0x0501 )
#    define JET_VERSION_XP
#  endif // WINVER >= 0x0502
#  if ( WINVER >= 0x0502 )
#    define JET_VERSION_SERVER2003
#  endif // WINVER >= 0x0502
#else // !WINVER
// WINVER has not been specified. Assume all functions are available.
#    define JET_VERSION_XP
#    define JET_VERSION_SERVER2003
#endif // !WINVER


#if defined(_M_AMD64) || defined(_M_IA64)
#include <pshpack8.h>
#else
#include <pshpack4.h>
#endif


#pragma warning(push)
#pragma warning(disable: 4201)		//	nonstandard extension used : nameless struct/union


#define JET_API     __stdcall
#define JET_NODSAPI __stdcall

#ifdef _WIN64
    typedef unsigned __int64 JET_API_PTR;
#else
    typedef unsigned long JET_API_PTR;
#endif


typedef long JET_ERR;

typedef JET_API_PTR JET_HANDLE;	/* backup file handle */
typedef JET_API_PTR JET_INSTANCE;	/* Instance Identifier */
typedef JET_API_PTR JET_SESID;  	/* Session Identifier */
typedef JET_API_PTR JET_TABLEID;	/* Table Identifier */
#ifdef JET_VERSION_XP
typedef JET_API_PTR JET_LS;		/* Local Storage */
#endif // JET_VERSION_XP

typedef unsigned long JET_COLUMNID;	/* Column Identifier */

typedef struct tagJET_INDEXID
	{
	unsigned long	cbStruct;
	unsigned char	rgbIndexId[sizeof(JET_API_PTR)+sizeof(unsigned long)+sizeof(unsigned long)];
	} JET_INDEXID;

typedef unsigned long JET_DBID;   	/* Database Identifier */
typedef unsigned long JET_OBJTYP;	/* Object Type */
typedef unsigned long JET_COLTYP;	/* Column Type */
typedef unsigned long JET_GRBIT;  	/* Group of Bits */

typedef unsigned long JET_SNP;		/* Status Notification Process */
typedef unsigned long JET_SNT;		/* Status Notification Type */
typedef double JET_DATESERIAL;		/* JET_coltypDateTime format */
#ifdef JET_VERSION_XP
typedef unsigned long JET_CBTYP;	/* Callback Types */
#endif // JET_VERSION_XP

typedef JET_ERR (__stdcall *JET_PFNSTATUS)(JET_SESID sesid, JET_SNP snp, JET_SNT snt, void *pv);

/*	required to make RSTMAP RPC capable
/**/
#ifdef	MIDL_PASS
#define	xRPC_STRING [string]
#else
#define	xRPC_STRING
#if !defined(_NATIVE_WCHAR_T_DEFINED)
typedef unsigned short WCHAR;
#else
typedef wchar_t WCHAR;
#endif
#endif

typedef struct
	{
	xRPC_STRING char		*szDatabaseName;
	xRPC_STRING char		*szNewDatabaseName;
	} JET_RSTMAP;			/* restore map */


typedef struct tagCONVERT
	{
	char					*szOldDll;
	union
		{
		unsigned long		fFlags;
		struct
			{
			unsigned long	fSchemaChangesOnly:1;
			};
		};
	} JET_CONVERT;


//	Online defragmentation options
#define JET_bitDefragmentBatchStart				0x00000001
#define JET_bitDefragmentBatchStop				0x00000002
#ifdef JET_VERSION_XP
#define JET_bitDefragmentAvailSpaceTreesOnly	0x00000040	/* only defrag AvailExt trees */
#endif // JET_VERSION_XP

#ifdef JET_VERSION_XP
	/* Callback-function types */

#define JET_cbtypNull							0x00000000
#define JET_cbtypFinalize						0x00000001	/* a finalizable column has gone to zero */
#define JET_cbtypBeforeInsert					0x00000002	/* about to insert a record */
#define JET_cbtypAfterInsert					0x00000004	/* finished inserting a record */
#define JET_cbtypBeforeReplace					0x00000008	/* about to modify a record */
#define JET_cbtypAfterReplace					0x00000010	/* finished modifying a record */
#define JET_cbtypBeforeDelete					0x00000020	/* about to delete a record */
#define JET_cbtypAfterDelete					0x00000040	/* finished deleting the record */
#define JET_cbtypUserDefinedDefaultValue		0x00000080	/* calculating a user-defined default */
#define JET_cbtypOnlineDefragCompleted			0x00000100	/* a call to JetDefragment2 has completed */
#define JET_cbtypFreeCursorLS					0x00000200	/* the Local Storage associated with a cursor must be freed */
#define JET_cbtypFreeTableLS					0x00000400	/* the Local Storage associated with a table must be freed */

	/* Callback-function prototype */

typedef JET_ERR (__stdcall *JET_CALLBACK)(
	JET_SESID 		sesid,
	JET_DBID 		dbid,
	JET_TABLEID 	tableid,
	JET_CBTYP 		cbtyp,
	void *			pvArg1,
	void *			pvArg2,
	void *			pvContext,
	JET_API_PTR		ulUnused );
#endif // JET_VERSION_XP

	/* Status Notification Structures */

typedef struct				/* Status Notification Progress */
	{
	unsigned long	cbStruct;	/* Size of this structure */
	unsigned long	cunitDone;	/* Number of units of work completed */
	unsigned long	cunitTotal;	/* Total number of units of work */
	} JET_SNPROG;


typedef struct
	{
	unsigned long			cbStruct;

	unsigned long			cbFilesizeLow;			//	file's current size (low DWORD)
	unsigned long			cbFilesizeHigh;			//	file's current size (high DWORD)

	unsigned long			cbFreeSpaceRequiredLow;	//	estimate of free disk space required for in-place upgrade (low DWORD)
	unsigned long			cbFreeSpaceRequiredHigh;//	estimate of free disk space required for in-place upgrade (high DWORD)

	unsigned long			csecToUpgrade;			//	estimate of time required, in seconds, for upgrade

	union
		{
		unsigned long		ulFlags;
		struct
			{
			unsigned long	fUpgradable:1;
			unsigned long	fAlreadyUpgraded:1;
			};
		};
	} JET_DBINFOUPGRADE;

typedef struct
	{
	unsigned long		cbStruct;
	JET_OBJTYP			objtyp;
	JET_DATESERIAL		dtCreate;	//  Deprecated.
	JET_DATESERIAL		dtUpdate;	//  Deprecated.
	JET_GRBIT			grbit;
	unsigned long		flags;
	unsigned long		cRecord;
	unsigned long		cPage;
	} JET_OBJECTINFO;

	/* The following flags appear in the grbit field above */

#define JET_bitTableInfoUpdatable	0x00000001
#define JET_bitTableInfoBookmark	0x00000002
#define JET_bitTableInfoRollback	0x00000004
#define JET_bitTableSequential		0x00008000

	/* The following flags occur in the flags field above */

#define JET_bitObjectSystem			0x80000000	// Internal use only
#define JET_bitObjectTableFixedDDL	0x40000000	// Table's DDL is fixed
#define JET_bitObjectTableTemplate	0x20000000	// Table's DDL is inheritable (implies FixedDDL)
#define JET_bitObjectTableDerived	0x10000000	// Table's DDL is inherited from a template table
#ifdef JET_VERSION_XP
#define JET_bitObjectTableNoFixedVarColumnsInDerivedTables	0x04000000	//	used in conjunction with JET_bitObjectTableTemplate
																		//	to disallow fixed/var columns in derived tables (so that
																		//	fixed/var columns may be added to the template in the future)
#endif // JET_VERSION_XP


typedef struct
	{
	unsigned long	cbStruct;
	JET_TABLEID		tableid;
	unsigned long	cRecord;
	JET_COLUMNID	columnidcontainername;
	JET_COLUMNID	columnidobjectname;
	JET_COLUMNID	columnidobjtyp;
	JET_COLUMNID	columniddtCreate;	//  XXX -- to be deleted
	JET_COLUMNID	columniddtUpdate;	//  XXX -- to be deleted
	JET_COLUMNID	columnidgrbit;
	JET_COLUMNID	columnidflags;
	JET_COLUMNID	columnidcRecord;	/* Level 2 info */
	JET_COLUMNID	columnidcPage;		/* Level 2 info */
	} JET_OBJECTLIST;

#define cObjectInfoCols 9

typedef struct
	{
	unsigned long	cbStruct;
	JET_TABLEID		tableid;
	unsigned long	cRecord;
	JET_COLUMNID	columnidPresentationOrder;
	JET_COLUMNID	columnidcolumnname;
	JET_COLUMNID	columnidcolumnid;
	JET_COLUMNID	columnidcoltyp;
	JET_COLUMNID	columnidCountry;
	JET_COLUMNID	columnidLangid;
	JET_COLUMNID	columnidCp;
	JET_COLUMNID	columnidCollate;
	JET_COLUMNID	columnidcbMax;
	JET_COLUMNID	columnidgrbit;
	JET_COLUMNID	columnidDefault;
	JET_COLUMNID	columnidBaseTableName;
	JET_COLUMNID	columnidBaseColumnName;
	JET_COLUMNID	columnidDefinitionName;
	} JET_COLUMNLIST;

#define cColumnInfoCols 14

typedef struct
	{
	unsigned long	cbStruct;
	JET_COLUMNID	columnid;
	JET_COLTYP		coltyp;
	unsigned short	wCountry;
	unsigned short	langid;
	unsigned short	cp;
	unsigned short	wCollate;       /* Must be 0 */
	unsigned long	cbMax;
	JET_GRBIT		grbit;
	} JET_COLUMNDEF;


typedef struct
	{
	unsigned long	cbStruct;
	JET_COLUMNID	columnid;
	JET_COLTYP		coltyp;
	unsigned short	wCountry;
	unsigned short	langid;
	unsigned short	cp;
	unsigned short	wFiller;       /* Must be 0 */
	unsigned long	cbMax;
	JET_GRBIT		grbit;
	char			szBaseTableName[256];
	char			szBaseColumnName[256];
	} JET_COLUMNBASE;

typedef struct
	{
	unsigned long	cbStruct;
	JET_TABLEID		tableid;
	unsigned long	cRecord;
	JET_COLUMNID	columnidindexname;
	JET_COLUMNID	columnidgrbitIndex;
	JET_COLUMNID	columnidcKey;
	JET_COLUMNID	columnidcEntry;
	JET_COLUMNID	columnidcPage;
	JET_COLUMNID	columnidcColumn;
	JET_COLUMNID	columnidiColumn;
	JET_COLUMNID	columnidcolumnid;
	JET_COLUMNID	columnidcoltyp;
	JET_COLUMNID	columnidCountry;
	JET_COLUMNID	columnidLangid;
	JET_COLUMNID	columnidCp;
	JET_COLUMNID	columnidCollate;
	JET_COLUMNID	columnidgrbitColumn;
	JET_COLUMNID	columnidcolumnname;
	JET_COLUMNID	columnidLCMapFlags;
	} JET_INDEXLIST;


#define cIndexInfoCols 15

typedef struct tag_JET_COLUMNCREATE
	{
	unsigned long	cbStruct;				// size of this structure (for future expansion)
	char			*szColumnName;			// column name
	JET_COLTYP		coltyp;					// column type
	unsigned long	cbMax;					// the maximum length of this column (only relevant for binary and text columns)
	JET_GRBIT		grbit;					// column options
	void			*pvDefault;				// default value (NULL if none)
	unsigned long	cbDefault;				// length of default value
	unsigned long	cp;						// code page (for text columns only)
	JET_COLUMNID	columnid;				// returned column id
	JET_ERR			err;					// returned error code
	} JET_COLUMNCREATE;

#ifdef JET_VERSION_XP
//  This is the information needed to create a column with a user-defined default. It should be passed in using
//  the pvDefault and cbDefault in a JET_COLUMNCREATE structure
typedef struct tag_JET_USERDEFINEDDEFAULT
	{
	char * szCallback;
	unsigned char * pbUserData;
	unsigned long cbUserData;
	char * szDependantColumns;
	} JET_USERDEFINEDDEFAULT;
#endif // JET_VERSION_XP


typedef struct tagJET_CONDITIONALCOLUMN
	{
	unsigned long	cbStruct;				// size of this structure (for future expansion)
	char 			*szColumnName;			// column that we are conditionally indexed on
	JET_GRBIT		grbit;					// conditional column options
	} JET_CONDITIONALCOLUMN;


typedef struct tagJET_UNICODEINDEX
	{
	unsigned long	lcid;
	unsigned long	dwMapFlags;
	} JET_UNICODEINDEX;

#ifdef JET_VERSION_SERVER2003
typedef struct tagJET_TUPLELIMITS
	{
	unsigned long	chLengthMin;
	unsigned long	chLengthMax;
	unsigned long	chToIndexMax;
	} JET_TUPLELIMITS;
#endif // JET_VERSION_SERVER2003

typedef struct tagJET_INDEXCREATE
	{
	unsigned long			cbStruct;				// size of this structure (for future expansion)
	char					*szIndexName;			// index name
	char					*szKey;					// index key
	unsigned long			cbKey;					// length of key
	JET_GRBIT				grbit;					// index options
	unsigned long			ulDensity;				// index density

	union
		{
		unsigned long		lcid;					// lcid for the index (if JET_bitIndexUnicode NOT specified)
		JET_UNICODEINDEX	*pidxunicode;			// pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
		};

	union
		{
		unsigned long		cbVarSegMac;			// maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
#ifdef JET_VERSION_SERVER2003
		JET_TUPLELIMITS		*ptuplelimits;			// pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
#endif // ! JET_VERSION_SERVER2003
		};

	JET_CONDITIONALCOLUMN	*rgconditionalcolumn;	// pointer to conditional column structure
	unsigned long			cConditionalColumn;		// number of conditional columns
	JET_ERR					err;					// returned error code
	} JET_INDEXCREATE;


typedef struct tagJET_TABLECREATE
	{
	unsigned long		cbStruct;				// size of this structure (for future expansion)
	char				*szTableName;			// name of table to create.
	char				*szTemplateTableName;	// name of table from which to inherit base DDL
	unsigned long		ulPages;				// initial pages to allocate for table.
	unsigned long		ulDensity;				// table density.
	JET_COLUMNCREATE	*rgcolumncreate;		// array of column creation info
	unsigned long		cColumns;				// number of columns to create
	JET_INDEXCREATE		*rgindexcreate;			// array of index creation info
	unsigned long		cIndexes;				// number of indexes to create
	JET_GRBIT			grbit;
	JET_TABLEID			tableid;				// returned tableid.
	unsigned long		cCreated;				// count of objects created (columns+table+indexes).
	} JET_TABLECREATE;

#ifdef JET_VERSION_XP
typedef struct tagJET_TABLECREATE2
	{
	unsigned long		cbStruct;				// size of this structure (for future expansion)
	char				*szTableName;			// name of table to create.
	char				*szTemplateTableName;	// name of table from which to inherit base DDL
	unsigned long		ulPages;				// initial pages to allocate for table.
	unsigned long		ulDensity;				// table density.
	JET_COLUMNCREATE	*rgcolumncreate;		// array of column creation info
	unsigned long		cColumns;				// number of columns to create
	JET_INDEXCREATE		*rgindexcreate;			// array of index creation info
	unsigned long		cIndexes;				// number of indexes to create
	char				*szCallback;			// callback to use for this table
	JET_CBTYP			cbtyp;					// when the callback should be called
	JET_GRBIT			grbit;
	JET_TABLEID			tableid;				// returned tableid.
	unsigned long		cCreated;				// count of objects created (columns+table+indexes+callbacks).
	} JET_TABLECREATE2;
#endif // JET_VERSION_XP

typedef struct
	{
	unsigned long	cbStruct;
	unsigned long	ibLongValue;
	unsigned long	itagSequence;
	JET_COLUMNID	columnidNextTagged;
	} JET_RETINFO;

typedef struct
	{
	unsigned long	cbStruct;
	unsigned long	ibLongValue;
	unsigned long	itagSequence;
	} JET_SETINFO;

typedef struct
	{
	unsigned long	cbStruct;
	unsigned long	centriesLT;
	unsigned long	centriesInRange;
	unsigned long	centriesTotal;
	} JET_RECPOS;

typedef struct
	{
	unsigned long	cbStruct;
	JET_TABLEID		tableid;
	unsigned long	cRecord;
	JET_COLUMNID	columnidBookmark;
	} JET_RECORDLIST;

typedef struct
	{
	unsigned long	cbStruct;
	JET_TABLEID		tableid;
	JET_GRBIT		grbit;
	} JET_INDEXRANGE;



#include <pshpack1.h>
#define JET_MAX_COMPUTERNAME_LENGTH 15

typedef struct	{
	char		bSeconds;				//	0 - 60
	char		bMinutes;				//	0 - 60
	char		bHours;					//	0 - 24
	char		bDay;					//	1 - 31
	char		bMonth;					//	0 - 11
	char		bYear;					//	current year - 1900
	char		bFiller1;
	char		bFiller2;
	} JET_LOGTIME;

typedef struct
	{
	unsigned short	ib;				// must be the last so that lgpos can
	unsigned short	isec;			// index of disksec starting logsec
	long 			lGeneration;	// generation of logsec
	} JET_LGPOS;					// be casted to TIME.

typedef struct
	{
	unsigned long	ulRandom;			//	a random number
	JET_LOGTIME		logtimeCreate;		//	time db created, in logtime format
	char			szComputerName[ JET_MAX_COMPUTERNAME_LENGTH + 1 ];	// where db is created
	} JET_SIGNATURE;

typedef struct
	{
	JET_LGPOS		lgposMark;			//	id for this backup
	JET_LOGTIME		logtimeMark;
	unsigned long	genLow;
	unsigned long	genHigh;
	} JET_BKINFO;

#include <poppack.h>

typedef struct {
	unsigned long	ulVersion;		//	version of DAE the db created (see ulDAEVersion)
	unsigned long	ulUpdate;			//	used to track incremental database format updates that
										//	are backward-compatible (see ulDAEUpdate)
	JET_SIGNATURE	signDb;			//	(28 bytes) signature of the db (incl. creation time).
	unsigned long	dbstate;		//	consistent/inconsistent state

	JET_LGPOS		lgposConsistent;	//	null if in inconsistent state
	JET_LOGTIME		logtimeConsistent;	// null if in inconsistent state

	JET_LOGTIME		logtimeAttach;	//	Last attach time.
	JET_LGPOS		lgposAttach;

	JET_LOGTIME		logtimeDetach;	//	Last detach time.
 	JET_LGPOS		lgposDetach;

	JET_SIGNATURE	signLog;		//	(28 bytes) log signature for this attachments

	JET_BKINFO		bkinfoFullPrev;	//	Last successful full backup.

	JET_BKINFO		bkinfoIncPrev;	//	Last successful Incremental backup.
									//	Reset when bkinfoFullPrev is set
	JET_BKINFO		bkinfoFullCur;	//	current backup. Succeed if a
									//	corresponding pat file generated.
	unsigned long	fShadowingDisabled;
	unsigned long	fUpgradeDb;

	//	NT version information. This is needed to decide if an index need
	//	be recreated due to sort table changes.

	unsigned long	dwMajorVersion;		/*	OS version info								*/
	unsigned long	dwMinorVersion;
	unsigned long	dwBuildNumber;
	long			lSPNumber;

	unsigned long	cbPageSize;			//	database page size (0 = 4k pages)

	} JET_DBINFOMISC;


/************************************************************************/
/*************************     JET CONSTANTS	 ************************/
/************************************************************************/

#ifdef JET_VERSION_XP
#define JET_instanceNil				(~(JET_INSTANCE)0)
#endif // JET_VERSION_XP
#define JET_sesidNil				(~(JET_SESID)0)
#define JET_tableidNil				(~(JET_TABLEID)0)
#define JET_bitNil					((JET_GRBIT)0)

	/* Max size of a bookmark */

#define JET_cbBookmarkMost			256

	/* Max length of a object/column/index/property name */

#define JET_cbNameMost				64

	/* Max length of a "name.name.name..." construct */

#define JET_cbFullNameMost			255

	/* Max size of long-value (LongBinary or LongText) column chunk */

//	#define JET_cbColumnLVChunkMost		( JET_cbPage - 82 ) to the following:
//	Get cbPage from GetSystemParameter.
// 	changed JET_cbColumnLVChunkMost reference to cbPage - JET_cbColumnLVPageOverhead

#define JET_cbColumnLVPageOverhead	82

	/* Max size of long-value (LongBinary or LongText) column default value */

#define JET_cbLVDefaultValueMost	255

	/* Max size of non-long-value column data */

#define JET_cbColumnMost			255

	/* Max size of a sort/index key */

#define JET_cbKeyMost				255
#define JET_cbLimitKeyMost			256				//	maximum key size when key is formed using a Limit grbit (eg. JET_bitStrLimit)
#define JET_cbPrimaryKeyMost		255
#define JET_cbSecondaryKeyMost		255

	/* Max number of components in a sort/index key */

#define JET_ccolKeyMost				12

//	maximum number of columns
#ifdef JET_VERSION_XP
#define JET_ccolMost				0x0000fee0
#else // !JET_VERSION_XP
#define JET_ccolMost				0x00007ffe
#endif // !JET_VERSION_XP
#define JET_ccolFixedMost			0x0000007f
#define JET_ccolVarMost				0x00000080
#define JET_ccolTaggedMost			( JET_ccolMost - 0x000000ff )

#ifdef JET_VERSION_XP
//  event logging level (only on and off for now - will add more in the future)
#define JET_EventLoggingDisable		0
#define JET_EventLoggingLevelMax	100

#endif // JET_VERSION_XP

//	system paramters
//
//	location parameters
//
#define JET_paramSystemPath						0	//	path to check point file [".\\"]
#define JET_paramTempPath						1	//	path to the temporary database [".\\"]
#define JET_paramLogFilePath 					2	//	path to the log file directory [".\\"]
#define JET_paramBaseName						3	//	base name for all DBMS object names ["edb"]
#define JET_paramEventSource					4	//	language independent process descriptor string [""]

//	performance parameters
//
#define JET_paramMaxSessions					5	//	maximum number of sessions [16]
#define JET_paramMaxOpenTables  				6	//	maximum number of open directories [300]
													//  	need 1 for each open table index,
													//  	plus 1 for each open table with no indexes,
													//  	plus 1 for each table with long column data,
													//  	plus a few more.
													//		for 4.1, 1/3 for regular table, 2/3 for index
#define JET_paramPreferredMaxOpenTables			7	//	preferred maximum number of open directories [300]
#define JET_paramMaxCursors						8	//	maximum number of open cursors [1024]
#define JET_paramMaxVerPages					9	//	maximum version store size in 16kByte units [64]
#define JET_paramPreferredVerPages				63	//	preferred version store size in 16kByte units [64 * 0.9]
#ifdef JET_VERSION_XP
#define JET_paramGlobalMinVerPages				81	//	minimum version store size for all instances in 16kByte units [64]
#define JET_paramVersionStoreTaskQueueMax		105	//	maximum number of tasks in the task queue before start dropping the tasks [32]
#endif // JET_VERSION_XP
#define JET_paramMaxTemporaryTables				10	//	maximum concurrent open temporary table/index creation [20]
#define JET_paramLogFileSize					11	//	log file size in kBytes [5120]
#define JET_paramLogBuffers						12	//	log buffers in 512 bytes [80]
#define JET_paramWaitLogFlush					13	//	log flush wait time in milliseconds [0] DEFUNCT
#define JET_paramLogCheckpointPeriod			14	//	checkpoint period in 512 bytes [1024] DEFUNCT
#define JET_paramLogWaitingUserMax				15	//	maximum sessions waiting log flush [3] DEFUNCT
#define JET_paramCommitDefault					16	//	default grbit for JetCommitTransaction [0]
#define JET_paramCircularLog					17	//	boolean flag for circular logging [0]
#define JET_paramDbExtensionSize				18	//	database extension size in pages [256] DEFUNCT
#define JET_paramPageTempDBMin					19  //	minimum size temporary database in pages [0] DEFUNCT
#define JET_paramPageFragment					20	//	maximum disk extent considered fragment in pages [8] DEFUNCT

//  cache performance parameters
//
#define JET_paramBatchIOBufferMax				22	//	maximum batch I/O buffers in pages [64] DEFUNCT
#define JET_paramCacheSize						41	//	current cache size in pages [512]
#define JET_paramCacheSizeMin					60	//	minimum cache size in pages [64]
#define JET_paramCacheSizeMax					23	//	maximum cache size in pages [512]
#define JET_paramCheckpointDepthMax				24	//	maximum checkpoint depth in bytes [20MB]
#define JET_paramLRUKCorrInterval				25  //	time (usec) under which page accesses are correlated [128000], it was 10000
#define JET_paramLRUKHistoryMax					26  //	maximum LRUK history records [1024] (proportional to cache size max) DEFUNCT
#define JET_paramLRUKPolicy						27  //	K-ness of LRUK page eviction algorithm (1...2) [2]
#define JET_paramLRUKTimeout					28  //	time (sec) after which cached pages are always evictable [100]
#define JET_paramLRUKTrxCorrInterval			29  //	Not Used: time (usec) under which page accesses by the same transaction are correlated [5000000] DEFUNCT
#define JET_paramOutstandingIOMax				30	//	maximum outstanding I/Os [64] DEFUNCT
#define JET_paramStartFlushThreshold			31	//	evictable pages at which to start a flush [100] (proportional to CacheSizeMax)
#define JET_paramStopFlushThreshold				32	//	evictable pages at which to stop a flush [400] (proportional to CacheSizeMax)

//	debug only parameters
//
#define JET_paramRecovery						34	//	enable recovery [-1]
#define JET_paramEnableOnlineDefrag				35	//	enable online defrag [TRUE by default]

//	Application specific parameter
//
#define JET_paramCheckFormatWhenOpenFail		44	//	JetInit may return JET_errDatabaseXXXformat instead of database corrupt when it is set
#define JET_paramEnableTempTableVersioning		46	//	Enable versioning of temp tables (TRUE by default)
#define JET_paramIgnoreLogVersion				47	//	Do not check the log version
#define JET_paramDeleteOldLogs					48	//	Delete the log files if the version is old, after deleting may make database non-recoverable
#define JET_paramEventSourceKey					49	//	Event source registration key value
#define JET_paramNoInformationEvent				50	//	Disable logging information event [ FALSE by default ]
#ifdef JET_VERSION_XP
#define JET_paramEventLoggingLevel				51	//	Set the type of information that goes to event log [ eventLoggingLevelMax by default ]
#define JET_paramDeleteOutOfRangeLogs			52	//	Delete the log files that are not matching (generation wise) during soft recovery [false]
#define JET_paramAccessDeniedRetryPeriod		53	//	Number of milliseconds to retry when about to fail with AccessDenied [10000 milliseconds]
#endif // JET_VERSION_XP

//	Index-checking parameters
//
//	Different versions of windows normalize unicode text in different ways. That means indexes built under one version of Windows may
//	not work on other versions. Windows Server 2003 Beta 3 introduced GetNLSVersion() which can be used to determine the version of unicode normalization
//	that the OS currently provides. Indexes built in server 2003 are flagged with the version of unicode normalization that they were
//	built with (older indexes have no version information). Most unicode normalization changes consist of adding new characters -- codepoints
//	which were previously undefined are defined and normalize differently. Thus, if binary data is stored in a unicode column it will normalize
//	differently as new codepoints are defined.
//
//	As of Windows Server 2003 RC1 ESENT tracks unicode index entries that contain undefined codepoints. These can be used to fixup an index when the
//	set of defined unicode characters changes.
//
//	These parameters control what happens when ESENT attaches to a database that was last used under a different build of the OS (the OS version
//	is stamped in the database header).
//
//	If JET_paramEnableIndexChecking is TRUE JetAttachDatabase() will delete indexes if JET_bitDbDeleteCorruptIndexes or return an error if
//	the grbit was not specified and there are indexes which need deletion. If it is set to FALSE then JetAttachDatabase() will succeed, even
//	if there are potentially corrupt indexes.
//
//	If JET_paramEnableIndexCleanup is set, the internal fixup table will be used to fixup index entries. This may not fixup all index corruptions
//	but will be transparent to the application.
//

#define JET_paramEnableIndexChecking			45  //	Enable checking OS version for indexes (FALSE by default)
#ifdef JET_VERSION_SERVER2003
#define JET_paramEnableIndexCleanup				54  //	Enable cleanup of out-of-date index entries (TRUE by default)
#endif // JET_VERSION_SERVER2003

//												60	//	JET_paramCacheSizeMin defined above
//												63	//	JET_paramPreferredVerPages defined above
#define JET_paramDatabasePageSize				64	//	set database page size
#ifdef JET_VERSION_XP
#define JET_paramDisableCallbacks				65	//	turn off callback resolution (for defrag/repair)
#define JET_paramLogFileCreateAsynch			69	//	prepares next log file while logging to the current one to smooth response time [true]
#endif // JET_VERSION_XP
#define JET_paramErrorToString					70  //	turns a JET_err into a string (taken from the comment in jet.h)
#ifdef JET_VERSION_XP
#define JET_paramZeroDatabaseDuringBackup		71	//	Overwrite deleted records/LVs during backup [false]
#endif // JET_VERSION_XP
#define JET_paramUnicodeIndexDefault			72	//	default LCMapString() lcid and flags to use for CreateIndex() and unique multi-values check
													//		(pass JET_UNICODEINDEX structure for lParam)
#ifdef JET_VERSION_XP
#define JET_paramRuntimeCallback				73	//	pointer to runtime-only callback function
#endif // JET_VERSION_XP
#define JET_paramCleanupMismatchedLogFiles		77	//	instead of erroring out after a successful recovery with JET_errLogFileSizeMismatchDatabasesConsistent, ESE will silently delete the old log files and checkpoint file and continue operations
#ifdef JET_VERSION_XP
#define JET_paramRecordUpgradeDirtyLevel		78	//	how aggresively should pages with their record format converted be flushed (0-3) [1]
//												81	//	JET_paramGlobalMinVerPages defined above
#define JET_paramOSSnapshotTimeout				82	//	timeout for the freeze period in msec [1000 * 20]
#endif // JET_VERSION_XP

#define JET_paramExceptionAction				98	//	what to do with exceptions generated within JET
#define JET_paramEventLogCache					99  //	number of bytes of eventlog records to cache if service is not available [0]
#ifdef JET_VERSION_XP
#define JET_paramCreatePathIfNotExist			100	//	create system/temp/log/log-failover paths if they do not exist
#define JET_paramPageHintCacheSize				101 //	maximum size of the fast page latch hint cache in bytes [256kb]
#define JET_paramOneDatabasePerSession			102	//	allow just one open user database per session [false]
#define JET_paramMaxInstances					104	//	maximum number of instances per process [1 for ESENT, 16 for Exchange]
//												105	//	JET_paramVersionStoreTaskQueueMax
//												106 //	JET_paramIdleFlushTime
//												107	//	JET_paramDisablePerfmon
//												108	//	JET_paramAbortRetryFailCallback
//												109	//	JET_paramVAReserve

#define JET_paramIndexTuplesLengthMin			110	//	for tuple indexes, minimum length of a tuple [3]
#define JET_paramIndexTuplesLengthMax			111	//	for tuple indexes, maximum length of a tuple [10]
#define JET_paramIndexTuplesToIndexMax			112	//	for tuple indexes, maximum number of characters in a given string to index [32767]
#endif // JET_VERSION_XP

#ifdef JET_VERSION_SERVER2003
#define JET_paramAlternateDatabaseRecoveryPath	113	//	recovery-only - search for dirty-shutdown databases in specified location only
#endif // JET_VERSION_SERVER2003



	/* Flags for JetInit2 */


#ifdef JET_VERSION_XP
// IGNORE_MISSING_ATTACH, ignoring hanging asserts for missing databases during recovery
#define JET_bitReplayIgnoreMissingDB		0x00000004 /* ignore missing databases */
#endif // JET_VERSION_XP

	/* Flags for JetTerm2 */

#define JET_bitTermComplete				0x00000001
#define JET_bitTermAbrupt				0x00000002
#define JET_bitTermStopBackup			0x00000004

	/* Flags for JetIdle */

#define JET_bitIdleFlushBuffers			0x00000001
#define JET_bitIdleCompact				0x00000002
#define JET_bitIdleStatus				0x00000004

	/* Flags for JetEndSession */


	/* Flags for JetAttach/OpenDatabase */

#define JET_bitDbReadOnly				0x00000001
#define JET_bitDbExclusive				0x00000002 /* multiple opens allowed */
#define JET_bitDbDeleteCorruptIndexes	0x00000010 /* delete indexes possibly corrupted by NT version upgrade */
#ifdef JET_VERSION_SERVER2003
#define JET_bitDbDeleteUnicodeIndexes	0x00000400 /* delete all indexes with unicode columns */
#endif // JET_VERSION_SERVER2003
#ifdef JET_VERSION_XP
#define JET_bitDbUpgrade				0x00000200 /* */
#endif // JET_VERSION_XP

	/* Flags for JetDetachDatabase2 */

#ifdef JET_VERSION_XP
#define JET_bitForceDetach			  		0x00000001
#define JET_bitForceCloseAndDetach			(0x00000002 | JET_bitForceDetach)
#endif // JET_VERSION_XP

	/* Flags for JetCreateDatabase */

#define JET_bitDbRecoveryOff 			0x00000008 /* disable logging/recovery for this database */
#define JET_bitDbShadowingOff			0x00000080 /* disable catalog shadowing */
#ifdef JET_VERSION_XP
#define JET_bitDbOverwriteExisting		0x00000200 /* overwrite existing database with same name */
#endif // JET_VERSION_XP

	/* Flags for JetBackup */

#define JET_bitBackupIncremental		0x00000001
#define JET_bitBackupAtomic				0x00000004
#ifdef JET_VERSION_XP
#define JET_bitBackupSnapshot			0x00000010
#endif // JET_VERSION_XP

	/* Database types */

#define JET_dbidNil			((JET_DBID) 0xFFFFFFFF)


	/* Flags for JetCreateTableColumnIndex */
#define JET_bitTableCreateFixedDDL			0x00000001	/* DDL is fixed */
#define JET_bitTableCreateTemplateTable		0x00000002	/* DDL is inheritable (implies FixedDDL) */
#ifdef JET_VERSION_XP
#define JET_bitTableCreateNoFixedVarColumnsInDerivedTables	0x00000004
														//	used in conjunction with JET_bitTableCreateTemplateTable
														//	to disallow fixed/var columns in derived tables (so that
														//	fixed/var columns may be added to the template in the future)
#endif // JET_VERSION_XP


	/* Flags for JetAddColumn, JetGetColumnInfo, JetOpenTempTable */

#define JET_bitColumnFixed				0x00000001
#define JET_bitColumnTagged				0x00000002
#define JET_bitColumnNotNULL			0x00000004
#define JET_bitColumnVersion			0x00000008
#define JET_bitColumnAutoincrement		0x00000010
#define JET_bitColumnUpdatable			0x00000020 /* JetGetColumnInfo only */
#define JET_bitColumnTTKey				0x00000040 /* JetOpenTempTable only */
#define JET_bitColumnTTDescending		0x00000080 /* JetOpenTempTable only */
#define JET_bitColumnMultiValued		0x00000400
#define JET_bitColumnEscrowUpdate		0x00000800 /* escrow updated */
#define JET_bitColumnUnversioned		0x00001000 /* for add column only - add column unversioned */
#ifdef JET_VERSION_XP
#define JET_bitColumnMaybeNull			0x00002000 /* for retrieve column info of outer join where no match from the inner table */
#define JET_bitColumnFinalize			0x00004000 /* this is a finalizable column (issue callback if escrow value equals 0) */
#define JET_bitColumnUserDefinedDefault	0x00008000 /* default value from a user-provided callback */
#endif // JET_VERSION_XP
#ifdef JET_VERSION_SERVER2003
#define JET_bitColumnDeleteOnZero		0x00020000 /* this is a finalizable column (delete record if escrow value equals 0) */
#endif // JET_VERSION_SERVER2003

#ifdef JET_VERSION_XP
//	flags for JetDeleteColumn
#define JET_bitDeleteColumnIgnoreTemplateColumns	0x00000001	//	for derived tables, don't bother looking in template columns
#endif // JET_VERSION_XP


	/* Flags for JetSetCurrentIndex */

#define JET_bitMoveFirst				0x00000000
#define JET_bitNoMove					0x00000002

	/* Flags for JetMakeKey */

#define JET_bitNewKey					0x00000001
#define JET_bitStrLimit 				0x00000002
#define JET_bitSubStrLimit				0x00000004
#define JET_bitNormalizedKey 			0x00000008
#define JET_bitKeyDataZeroLength		0x00000010
#ifdef JET_VERSION_XP
#define JET_bitFullColumnStartLimit		0x00000100
#define JET_bitFullColumnEndLimit		0x00000200
#define JET_bitPartialColumnStartLimit	0x00000400
#define JET_bitPartialColumnEndLimit	0x00000800
#endif // JET_VERSION_XP

	/* Flags for JetSetIndexRange */

#define JET_bitRangeInclusive			0x00000001
#define JET_bitRangeUpperLimit			0x00000002
#define JET_bitRangeInstantDuration		0x00000004
#define JET_bitRangeRemove				0x00000008

	/* Flags for JetGetLock */

#define JET_bitReadLock					0x00000001
#define JET_bitWriteLock				0x00000002

	/* Constants for JetMove */

#define JET_MoveFirst					(0x80000000)
#define JET_MovePrevious				(-1)
#define JET_MoveNext					(+1)
#define JET_MoveLast					(0x7fffffff)

	/* Flags for JetMove */

#define JET_bitMoveKeyNE				0x00000001

	/* Flags for JetSeek */

#define JET_bitSeekEQ					0x00000001
#define JET_bitSeekLT					0x00000002
#define JET_bitSeekLE					0x00000004
#define JET_bitSeekGE					0x00000008
#define JET_bitSeekGT		 			0x00000010
#define JET_bitSetIndexRange			0x00000020
#ifdef JET_VERSION_SERVER2003
#define JET_bitCheckUniqueness			0x00000040	//	to be used with JET_bitSeekEQ only, returns JET_wrnUniqueKey if seek lands on a key which has no dupes
#endif // JET_VERSION_SERVER2003

#ifdef JET_VERSION_XP
	//	Flags for JetGotoSecondaryIndexBookmark
#define JET_bitBookmarkPermitVirtualCurrency	0x00000001	//	place cursor on relative position in index if specified bookmark no longer exists
#endif // JET_VERSION_XP

	/* Flags for JET_CONDITIONALCOLUMN */
#define JET_bitIndexColumnMustBeNull	0x00000001
#define JET_bitIndexColumnMustBeNonNull	0x00000002

	/* Flags for JET_INDEXRANGE */
#define JET_bitRecordInIndex			0x00000001
#define JET_bitRecordNotInIndex			0x00000002

	/* Flags for JetCreateIndex */

#define JET_bitIndexUnique				0x00000001
#define JET_bitIndexPrimary				0x00000002
#define JET_bitIndexDisallowNull		0x00000004
#define JET_bitIndexIgnoreNull			0x00000008
#define JET_bitIndexIgnoreAnyNull		0x00000020
#define JET_bitIndexIgnoreFirstNull		0x00000040
#define JET_bitIndexLazyFlush			0x00000080
#define JET_bitIndexEmpty				0x00000100	// don't attempt to build index, because all entries would evaluate to NULL (MUST also specify JET_bitIgnoreAnyNull)
#define JET_bitIndexUnversioned			0x00000200
#define JET_bitIndexSortNullsHigh		0x00000400	// NULL sorts after data for all columns in the index
#define JET_bitIndexUnicode				0x00000800	// LCID field of JET_INDEXCREATE actually points to a JET_UNICODEINDEX struct to allow user-defined LCMapString() flags
#ifdef JET_VERSION_XP
#define JET_bitIndexTuples				0x00001000	// index on substring tuples (text columns only)
#endif // JET_VERSION_XP
#ifdef JET_VERSION_SERVER2003
#define JET_bitIndexTupleLimits			0x00002000	// cbVarSegMac field of JET_INDEXCREATE actually points to a JET_TUPLELIMITS struct to allow custom tuple index limits (implies JET_bitIndexTuples)
#endif // JET_VERSION_SERVER2003

	/* Flags for index key definition */

#define JET_bitKeyAscending				0x00000000
#define JET_bitKeyDescending			0x00000001

	/* Flags for JetOpenTable */

#define JET_bitTableDenyWrite		0x00000001
#define JET_bitTableDenyRead		0x00000002
#define JET_bitTableReadOnly		0x00000004
#define JET_bitTableUpdatable		0x00000008
#define JET_bitTablePermitDDL		0x00000010	/*  override table flagged as FixedDDL (must be used with DenyRead) */
#define JET_bitTableNoCache			0x00000020	/*	don't cache the pages for this table */
#define JET_bitTablePreread			0x00000040	/*	assume the table is probably not in the buffer cache */

#define JET_bitTableClassMask		0x000F0000	/*  table stats class mask  */
#define JET_bitTableClassNone		0x00000000  /*  table belongs to no stats class (default)  */
#define JET_bitTableClass1			0x00010000  /*  table belongs to stats class 1  */
#define JET_bitTableClass2			0x00020000  /*  table belongs to stats class 2  */
#define JET_bitTableClass3			0x00030000  /*  table belongs to stats class 3  */
#define JET_bitTableClass4			0x00040000  /*  table belongs to stats class 4  */
#define JET_bitTableClass5			0x00050000  /*  table belongs to stats class 5  */
#define JET_bitTableClass6			0x00060000  /*  table belongs to stats class 6  */
#define JET_bitTableClass7			0x00070000  /*  table belongs to stats class 7  */
#define JET_bitTableClass8			0x00080000  /*  table belongs to stats class 8  */
#define JET_bitTableClass9			0x00090000  /*  table belongs to stats class 9  */
#define JET_bitTableClass10			0x000A0000  /*  table belongs to stats class 10  */
#define JET_bitTableClass11			0x000B0000  /*  table belongs to stats class 11  */
#define JET_bitTableClass12			0x000C0000  /*  table belongs to stats class 12  */
#define JET_bitTableClass13			0x000D0000  /*  table belongs to stats class 13  */
#define JET_bitTableClass14			0x000E0000  /*  table belongs to stats class 14  */
#define JET_bitTableClass15			0x000F0000  /*  table belongs to stats class 15  */

#ifdef JET_VERSION_XP
#define JET_bitLSReset				0x00000001	/*	reset LS value */
#define JET_bitLSCursor				0x00000002	/*	set/retrieve LS of table cursor */
#define JET_bitLSTable				0x00000004	/*	set/retrieve LS of table */

#define JET_LSNil					(~(JET_LS)0)
#endif // JET_VERSION_XP

	/* Flags for JetOpenTempTable */

#define JET_bitTTIndexed			0x00000001	/* Allow seek */
#define JET_bitTTUnique 			0x00000002	/* Remove duplicates */
#define JET_bitTTUpdatable			0x00000004	/* Allow updates */
#define JET_bitTTScrollable			0x00000008	/* Allow backwards scrolling */
#define JET_bitTTSortNullsHigh		0x00000010	/* NULL sorts after data for all columns in the index */
#define JET_bitTTForceMaterialization		0x00000020						/* Forces temp. table to be materialized into a btree (allows for duplicate detection) */
#ifdef JET_VERSION_XP
#define JET_bitTTErrorOnDuplicateInsertion	JET_bitTTForceMaterialization	/* Error always returned when duplicate is inserted (instead of dupe being silently removed) */
#endif // JET_VERSION_XP
#ifdef JET_VERSION_SERVER2003
#define JET_bitTTForwardOnly		0x00000040	/* Prevents temp. table from being materialized into a btree (and enables duplicate keys) */
#endif // JET_VERSION_SERVER2003

	/* Flags for JetSetColumn */

#define JET_bitSetAppendLV					0x00000001
#define JET_bitSetOverwriteLV				0x00000004 /* overwrite JET_coltypLong* byte range */
#define JET_bitSetSizeLV					0x00000008 /* set JET_coltypLong* size */
#define JET_bitSetZeroLength				0x00000020
#define JET_bitSetSeparateLV 				0x00000040 /* force LV separation */
#define JET_bitSetUniqueMultiValues			0x00000080 /* prevent duplicate multi-values */
#define JET_bitSetUniqueNormalizedMultiValues	0x00000100 /* prevent duplicate multi-values, normalizing all data before performing comparisons */
#ifdef JET_VERSION_XP
#define JET_bitSetRevertToDefaultValue		0x00000200 /* if setting last tagged instance to NULL, revert to default value instead if one exists */
#endif // JET_VERSION_XP


	/*	Set column parameter structure for JetSetColumns */

typedef struct {
	JET_COLUMNID			columnid;
	const void 				*pvData;
	unsigned long 			cbData;
	JET_GRBIT				grbit;
	unsigned long			ibLongValue;
	unsigned long			itagSequence;
	JET_ERR					err;
} JET_SETCOLUMN;

#ifdef JET_VERSION_XP
typedef struct {
	unsigned long	paramid;
	JET_API_PTR		lParam;
	const char		*sz;
	JET_ERR			err;
} JET_SETSYSPARAM;
#endif // JET_VERSION_XP

	/* Options for JetPrepareUpdate */

#define JET_prepInsert						0
#define JET_prepReplace 					2
#define JET_prepCancel						3
#define JET_prepReplaceNoLock				4
#define JET_prepInsertCopy					5
#ifdef JET_VERSION_XP
#define JET_prepInsertCopyDeleteOriginal	7	//	used for updating a record in the primary key; avoids the delete/insert process */
#endif // JET_VERSION_XP

	//	Flags for JetUpdate
#ifdef JET_VERSION_SERVER2003
#define JET_bitUpdateCheckESE97Compatibility	0x00000001	//	check whether record fits if represented in ESE97 database format
#endif // JET_VERSION_SERVER2003

	/* Flags for JetEscrowUpdate */
#define JET_bitEscrowNoRollback				0x0001

	/* Flags for JetRetrieveColumn */

#define JET_bitRetrieveCopy					0x00000001
#define JET_bitRetrieveFromIndex			0x00000002
#define JET_bitRetrieveFromPrimaryBookmark	0x00000004
#define JET_bitRetrieveTag					0x00000008
#define JET_bitRetrieveNull					0x00000010	/*	for columnid 0 only */
#define JET_bitRetrieveIgnoreDefault		0x00000020	/*	for columnid 0 only */
#define JET_bitRetrieveLongId				0x00000040
#define JET_bitRetrieveLongValueRefCount	0x00000080	/*  for testing use only */

	/* Retrieve column parameter structure for JetRetrieveColumns */

typedef struct {
	JET_COLUMNID		columnid;
	void 				*pvData;
	unsigned long 		cbData;
	unsigned long 		cbActual;
	JET_GRBIT			grbit;
	unsigned long		ibLongValue;
	unsigned long		itagSequence;
	JET_COLUMNID		columnidNextTagged;
	JET_ERR				err;
} JET_RETRIEVECOLUMN;




#ifdef JET_VERSION_XP
	/* Flags for JetEnumerateColumns */

#define JET_bitEnumerateCopy						JET_bitRetrieveCopy
#define JET_bitEnumerateIgnoreDefault				JET_bitRetrieveIgnoreDefault
#define JET_bitEnumeratePresenceOnly				0x00020000
#define JET_bitEnumerateTaggedOnly					0x00040000
#define JET_bitEnumerateCompressOutput				0x00080000
#ifdef JET_VERSION_SERVER2003
// Available on Server 2003 SP1
#define JET_bitEnumerateIgnoreUserDefinedDefault	0x00100000
#endif // JET_VERSION_SERVER2003

	/* Parameter structures for JetEnumerateColumns */

typedef struct {
	JET_COLUMNID			columnid;
	unsigned long			ctagSequence;
	unsigned long*			rgtagSequence;
} JET_ENUMCOLUMNID;

typedef struct {
	unsigned long			itagSequence;
	JET_ERR					err;
	unsigned long			cbData;
	void*					pvData;
} JET_ENUMCOLUMNVALUE;

typedef struct {
	JET_COLUMNID			columnid;
	JET_ERR					err;
	union {
		struct { /* err != JET_wrnColumnSingleValue */
			unsigned long			cEnumColumnValue;
			JET_ENUMCOLUMNVALUE*	rgEnumColumnValue;
		};
		struct { /* err == JET_wrnColumnSingleValue */
			unsigned long			cbData;
			void*					pvData;
		};
	};
} JET_ENUMCOLUMN;

	/* Realloc callback for JetEnumerateColumns */

typedef void* (JET_API *JET_PFNREALLOC)( void* pvContext, void* pv, unsigned long cb );
#endif // JET_VERSION_XP


#pragma warning(pop)		//	nonstandard extension used : nameless struct/union


	/* Flags for JetBeginTransaction2 */

#ifdef JET_VERSION_XP
#define JET_bitTransactionReadOnly		0x00000001	/* transaction will not modify the database */
#endif // JET_VERSION_XP

	/* Flags for JetCommitTransaction */

#define JET_bitCommitLazyFlush		0x00000001	/* lazy flush log buffers. */
#define JET_bitWaitLastLevel0Commit	0x00000002	/* wait for last level 0 commit record flushed */
#ifdef JET_VERSION_SERVER2003
#define JET_bitWaitAllLevel0Commit	0x00000008	/* wait for all level 0 commits to be flushed */
#endif // JET_VERSION_SERVER2003

	/* Flags for JetRollback */

#define JET_bitRollbackAll			0x00000001

	/* Info parameter for JetGetDatabaseInfo */

#define JET_DbInfoFilename			0
#define JET_DbInfoConnect			1
#define JET_DbInfoCountry			2
#ifdef JET_VERSION_XP
#define JET_DbInfoLCID				3
#endif // JET_VERSION_XP
#define JET_DbInfoLangid			3		// OBSOLETE: use JET_DbInfoLCID instead
#define JET_DbInfoCp				4
#define JET_DbInfoCollate			5
#define JET_DbInfoOptions			6
#define JET_DbInfoTransactions		7
#define JET_DbInfoVersion			8
#define JET_DbInfoIsam				9
#define JET_DbInfoFilesize			10
#define JET_DbInfoSpaceOwned		11
#define JET_DbInfoSpaceAvailable	12
#define JET_DbInfoUpgrade			13
#define JET_DbInfoMisc				14
#ifdef JET_VERSION_XP
#define JET_DbInfoDBInUse			15
#define JET_DbInfoPageSize			17
#endif // JET_VERSION_XP

	/* Dbstates from JetGetDatabaseFileInfo */

#define JET_dbstateJustCreated		1
#define JET_dbstateDirtyShutdown	2
#define JET_dbstateCleanShutdown	3
#define JET_dbstateBeingConverted	4
#ifdef JET_VERSION_XP
#define JET_dbstateForceDetach		5
#endif // JET_VERSION_XP

	/* Column data types */

#define JET_coltypNil				0
#define JET_coltypBit				1      /* True or False, Never NULL */
#define JET_coltypUnsignedByte		2      /* 1-byte integer, unsigned */
#define JET_coltypShort 			3      /* 2-byte integer, signed */
#define JET_coltypLong				4      /* 4-byte integer, signed */
#define JET_coltypCurrency			5      /* 8 byte integer, signed */
#define JET_coltypIEEESingle		6      /* 4-byte IEEE single precision */
#define JET_coltypIEEEDouble		7      /* 8-byte IEEE double precision */
#define JET_coltypDateTime			8      /* Integral date, fractional time */
#define JET_coltypBinary			9      /* Binary data, < 255 bytes */
#define JET_coltypText				10     /* ANSI text, case insensitive, < 255 bytes */
#define JET_coltypLongBinary		11     /* Binary data, long value */
#define JET_coltypLongText			12     /* ANSI text, long value */
#ifdef JET_VERSION_XP
#define JET_coltypSLV				13     /* SLV's. Reserved. */
#define JET_coltypMax				14		/* the number of column types  */
											/* used for validity tests and */
											/* array declarations.		   */
#else // !JET_VERSION_XP
#define JET_coltypMax				13		/* the number of column types  */
											/* used for validity tests and */
											/* array declarations.		   */
#endif // !JET_VERSION_XP

	/* Info levels for JetGetObjectInfo */

#define JET_ObjInfo					0U
#define JET_ObjInfoListNoStats		1U
#define JET_ObjInfoList 			2U
#define JET_ObjInfoSysTabCursor 	3U
#define JET_ObjInfoListACM			4U /* Blocked by JetGetObjectInfo */
#define JET_ObjInfoNoStats			5U
#define JET_ObjInfoSysTabReadOnly	6U
#define JET_ObjInfoRulesLoaded		7U
#define JET_ObjInfoMax				8U

	/* Info levels for JetGetTableInfo */

#define JET_TblInfo				0U
#define JET_TblInfoName			1U
#define JET_TblInfoDbid			2U
#define JET_TblInfoMostMany  	3U
#define JET_TblInfoRvt			4U
#define JET_TblInfoOLC			5U
#define JET_TblInfoResetOLC 	6U
#define JET_TblInfoSpaceUsage	7U
#define JET_TblInfoDumpTable	8U
#define JET_TblInfoSpaceAlloc	9U
#define JET_TblInfoSpaceOwned	10U					// OwnExt
#define JET_TblInfoSpaceAvailable		11U			// AvailExt
#define JET_TblInfoTemplateTableName	12U

	/* Info levels for JetGetIndexInfo and JetGetTableIndexInfo */

#define JET_IdxInfo					0U
#define JET_IdxInfoList 			1U
#define JET_IdxInfoSysTabCursor 	2U
#define JET_IdxInfoOLC				3U
#define JET_IdxInfoResetOLC			4U
#define JET_IdxInfoSpaceAlloc		5U
#ifdef JET_VERSION_XP
#define JET_IdxInfoLCID				6U
#endif // JET_VERSION_XP
#define JET_IdxInfoLangid			6U		//	OBSOLETE: use JET_IdxInfoLCID instead
#define JET_IdxInfoCount			7U
#define JET_IdxInfoVarSegMac		8U
#define JET_IdxInfoIndexId			9U

	/* Info levels for JetGetColumnInfo and JetGetTableColumnInfo */

#define JET_ColInfo					0U
#define JET_ColInfoList 			1U
#define JET_ColInfoSysTabCursor 	3U
#define JET_ColInfoBase 			4U
#define JET_ColInfoListCompact 		5U
#ifdef JET_VERSION_XP
#define JET_ColInfoByColid			6U
#define JET_ColInfoListSortColumnid 7U		//	same as JET_ColInfoList except PresentationOrder is set to columnid
											//	to force sorting by columnid
#endif // JET_VERSION_XP


	/* Engine Object Types */

#define JET_objtypNil				0
#define JET_objtypTable 			1

	/* Compact Options */

#define JET_bitCompactStats				0x00000020	/* Dump off-line compaction stats (only when progress meter also specified) */
#define JET_bitCompactRepair			0x00000040	/* Don't preread and ignore duplicate keys */

	/* Status Notification Processes */

#define JET_snpRepair					2
#define JET_snpCompact					4
#define JET_snpRestore					8
#define JET_snpBackup					9
#define JET_snpUpgrade					10
#ifdef JET_VERSION_XP
#define JET_snpScrub					11
#define JET_snpUpgradeRecordFormat		12
#endif // JET_VERSION_XP


	/* Status Notification Types */

#define JET_sntBegin			5	/* callback for beginning of operation */
#define JET_sntRequirements		7	/* callback for returning operation requirements */
#define JET_sntProgress 		0	/* callback for progress */
#define JET_sntComplete 		6	/* callback for completion of operation */
#define JET_sntFail				3	/* callback for failure during progress */

	/* Exception action */

#define JET_ExceptionMsgBox		0x0001		/* Display message box on exception */
#define JET_ExceptionNone		0x0002		/* Do nothing on exceptions */


#ifdef JET_VERSION_XP
	//	Online defragmentation options
#define JET_OnlineDefragDisable			0x0000		//	disable online defrag
#define JET_OnlineDefragAllOBSOLETE		0x0001		//	enable online defrag for everything (must be 1 for backward compatibility)
#define JET_OnlineDefragDatabases		0x0002		//	enable online defrag of databases
#define JET_OnlineDefragSpaceTrees		0x0004		//	enable online defrag of space trees
#define JET_OnlineDefragAll				0xffff		//	enable online defrag for everything

#endif // JET_VERSION_XP



/**********************************************************************/
/***********************     ERROR CODES     **************************/
/**********************************************************************/

/* The Error codes are not versioned with WINVER. */

/* SUCCESS */

#define JET_errSuccess						 0    /* Successful Operation */

/* ERRORS */

#define JET_wrnNyi							-1    /* Function Not Yet Implemented */

/*	SYSTEM errors
/**/
#define JET_errRfsFailure			   		-100  /* Resource Failure Simulator failure */
#define JET_errRfsNotArmed					-101  /* Resource Failure Simulator not initialized */
#define JET_errFileClose					-102  /* Could not close file */
#define JET_errOutOfThreads					-103  /* Could not start thread */
#define JET_errTooManyIO		  			-105  /* System busy due to too many IOs */
#define JET_errTaskDropped					-106  /* A requested async task could not be executed */
#define JET_errInternalError				-107  /* Fatal internal error */

//	BUFFER MANAGER errors
//
#define JET_errDatabaseBufferDependenciesCorrupted	-255	/* Buffer dependencies improperly set. Recovery failure */

/*	DIRECTORY MANAGER errors
/**/
#define JET_wrnRemainingVersions 			 321  /* The version store is still active */
#define JET_errPreviousVersion				-322  /* Version already existed. Recovery failure */
#define JET_errPageBoundary					-323  /* Reached Page Boundary */
#define JET_errKeyBoundary		  			-324  /* Reached Key Boundary */
#define JET_errBadPageLink					-327  /* Database corrupted */
#define JET_errBadBookmark					-328  /* Bookmark has no corresponding address in database */
#define JET_errNTSystemCallFailed 			-334  /* A call to the operating system failed */
#define JET_errBadParentPageLink			-338  /* Database corrupted */
#define JET_errSPAvailExtCacheOutOfSync		-340  // AvailExt cache doesn't match btree
#define JET_errSPAvailExtCorrupted			-341  // AvailExt space tree is corrupt
#define JET_errSPAvailExtCacheOutOfMemory	-342  // Out of memory allocating an AvailExt cache node
#define JET_errSPOwnExtCorrupted			-343  // OwnExt space tree is corrupt
#define JET_errDbTimeCorrupted				-344  // Dbtime on current page is greater than global database dbtime
#define JET_wrnUniqueKey					 345  // seek on non-unique index yielded a unique key

/*	RECORD MANAGER errors
/**/
#define JET_wrnSeparateLongValue			 406  /* Column is a separated long-value */
#define JET_wrnRecordFoundGreater			JET_wrnSeekNotEqual
#define JET_wrnRecordFoundLess    			JET_wrnSeekNotEqual
#define JET_errColumnIllegalNull  			JET_errNullInvalid
#define JET_errKeyTooBig					-408  /* Key is too large */

/*	LOGGING/RECOVERY errors
/**/
#define JET_errInvalidLoggedOperation		-500  /* Logged operation cannot be redone */
#define JET_errLogFileCorrupt		  		-501  /* Log file is corrupt */
#define JET_errNoBackupDirectory 			-503  /* No backup directory given */
#define JET_errBackupDirectoryNotEmpty 		-504  /* The backup directory is not emtpy */
#define JET_errBackupInProgress 			-505  /* Backup is active already */
#define JET_errRestoreInProgress			-506  /* Restore in progress */
#define JET_errMissingPreviousLogFile		-509  /* Missing the log file for check point */
#define JET_errLogWriteFail					-510  /* Failure writing to log file */
#define JET_errLogDisabledDueToRecoveryFailure	-511 /* Try to log something after recovery faild */
#define JET_errCannotLogDuringRecoveryRedo	-512	/* Try to log something during recovery redo */
#define JET_errLogGenerationMismatch		-513  /* Name of logfile does not match internal generation number */
#define JET_errBadLogVersion  	  			-514  /* Version of log file is not compatible with Jet version */
#define JET_errInvalidLogSequence  			-515  /* Timestamp in next log does not match expected */
#define JET_errLoggingDisabled 				-516  /* Log is not active */
#define JET_errLogBufferTooSmall			-517  /* Log buffer is too small for recovery */
#define JET_errLogSequenceEnd				-519  /* Maximum log file number exceeded */
#define JET_errNoBackup						-520  /* No backup in progress */
#define JET_errInvalidBackupSequence		-521  /* Backup call out of sequence */
#define JET_errBackupNotAllowedYet			-523  /* Cannot do backup now */
#define JET_errDeleteBackupFileFail	   		-524  /* Could not delete backup file */
#define JET_errMakeBackupDirectoryFail 		-525  /* Could not make backup temp directory */
#define JET_errInvalidBackup		 		-526  /* Cannot perform incremental backup when circular logging enabled */
#define JET_errRecoveredWithErrors			-527  /* Restored with errors */
#define JET_errMissingLogFile				-528  /* Current log file missing */
#define JET_errLogDiskFull					-529  /* Log disk full */
#define JET_errBadLogSignature				-530  /* Bad signature for a log file */
#define JET_errBadDbSignature				-531  /* Bad signature for a db file */
#define JET_errBadCheckpointSignature		-532  /* Bad signature for a checkpoint file */
#define JET_errCheckpointCorrupt			-533  /* Checkpoint file not found or corrupt */
#define JET_errMissingPatchPage				-534  /* Patch file page not found during recovery */
#define JET_errBadPatchPage					-535  /* Patch file page is not valid */
#define JET_errRedoAbruptEnded				-536  /* Redo abruptly ended due to sudden failure in reading logs from log file */
#define JET_errBadSLVSignature				-537  /* Signature in SLV file does not agree with database */
#define JET_errPatchFileMissing				-538  /* Hard restore detected that patch file is missing from backup set */
#define JET_errDatabaseLogSetMismatch		-539  /* Database does not belong with the current set of log files */
#define JET_errDatabaseStreamingFileMismatch	-540 /* Database and streaming file do not match each other */
#define JET_errLogFileSizeMismatch			-541  /* actual log file size does not match JET_paramLogFileSize */
#define JET_errCheckpointFileNotFound		-542  /* Could not locate checkpoint file */
#define JET_errRequiredLogFilesMissing		-543  /* The required log files for recovery is missing. */
#define JET_errSoftRecoveryOnBackupDatabase	-544  /* Soft recovery is intended on a backup database. Restore should be used instead */
#define JET_errLogFileSizeMismatchDatabasesConsistent	-545  /* databases have been recovered, but the log file size used during recovery does not match JET_paramLogFileSize */
#define JET_errLogSectorSizeMismatch		-546  /* the log file sector size does not match the current volume's sector size */
#define JET_errLogSectorSizeMismatchDatabasesConsistent	-547  /* databases have been recovered, but the log file sector size (used during recovery) does not match the current volume's sector size */
#define JET_errLogSequenceEndDatabasesConsistent		-548 /* databases have been recovered, but all possible log generations in the current sequence are used; delete all log files and the checkpoint file and backup the databases before continuing */

#define JET_errStreamingDataNotLogged		-549  /* Illegal attempt to replay a streaming file operation where the data wasn't logged. Probably caused by an attempt to roll-forward with circular logging enabled */

#define JET_errDatabaseDirtyShutdown		-550  /* Database was not shutdown cleanly. Recovery must first be run to properly complete database operations for the previous shutdown. */
#define JET_errDatabaseInconsistent			JET_errDatabaseDirtyShutdown	/* OBSOLETE */
#define JET_errConsistentTimeMismatch		-551  /* Database last consistent time unmatched */
#define JET_errDatabasePatchFileMismatch	-552  /* Patch file is not generated from this backup */
#define JET_errEndingRestoreLogTooLow		-553  /* The starting log number too low for the restore */
#define JET_errStartingRestoreLogTooHigh	-554  /* The starting log number too high for the restore */
#define JET_errGivenLogFileHasBadSignature	-555  /* Restore log file has bad signature */
#define JET_errGivenLogFileIsNotContiguous	-556  /* Restore log file is not contiguous */
#define JET_errMissingRestoreLogFiles		-557  /* Some restore log files are missing */
#define JET_wrnExistingLogFileHasBadSignature	558  /* Existing log file has bad signature */
#define JET_wrnExistingLogFileIsNotContiguous	559  /* Existing log file is not contiguous */
#define JET_errMissingFullBackup			-560  /* The database miss a previous full backup befor incremental backup */
#define JET_errBadBackupDatabaseSize		-561  /* The backup database size is not in 4k */
#define JET_errDatabaseAlreadyUpgraded		-562  /* Attempted to upgrade a database that is already current */
#define JET_errDatabaseIncompleteUpgrade	-563  /* Attempted to use a database which was only partially converted to the current format -- must restore from backup */
#define JET_wrnSkipThisRecord				 564  /* INTERNAL ERROR */
#define JET_errMissingCurrentLogFiles		-565  /* Some current log files are missing for continous restore */

#define JET_errDbTimeTooOld						-566  /* dbtime on page smaller than dbtimeBefore in record */
#define JET_errDbTimeTooNew						-567  /* dbtime on page in advance of the dbtimeBefore in record */
#define JET_errMissingFileToBackup				-569  /* Some log or patch files are missing during backup */

#define JET_errLogTornWriteDuringHardRestore	-570	/* torn-write was detected in a backup set during hard restore */
#define JET_errLogTornWriteDuringHardRecovery	-571	/* torn-write was detected during hard recovery (log was not part of a backup set) */
#define JET_errLogCorruptDuringHardRestore		-573	/* corruption was detected in a backup set during hard restore */
#define JET_errLogCorruptDuringHardRecovery	 	-574	/* corruption was detected during hard recovery (log was not part of a backup set) */

#define JET_errMustDisableLoggingForDbUpgrade	-575	/* Cannot have logging enabled while attempting to upgrade db */

#define JET_errBadRestoreTargetInstance			-577	/* TargetInstance specified for restore is not found or log files don't match */
#define JET_wrnTargetInstanceRunning			 578	/* TargetInstance specified for restore is running */

#define JET_errDatabasesNotFromSameSnapshot		-580	/* Databases to be restored are not from the same shadow copy backup */
#define JET_errSoftRecoveryOnSnapshot			-581	/* Soft recovery on a database from a shadow copy backup set */

#define JET_wrnDatabaseRepaired					 595	/* Database corruption has been repaired */

#define JET_errUnicodeTranslationBufferTooSmall	-601	/* Unicode translation buffer too small */
#define JET_errUnicodeTranslationFail			-602	/* Unicode normalization failed */
#define JET_errUnicodeNormalizationNotSupported	-603	/* OS does not provide support for Unicode normalisation (and no normalisation callback was specified) */

#define JET_errExistingLogFileHasBadSignature	-610	/* Existing log file has bad signature */
#define JET_errExistingLogFileIsNotContiguous	-611	/* Existing log file is not contiguous */

#define JET_errLogReadVerifyFailure			-612  /* Checksum error in log file during backup */
#define JET_errSLVReadVerifyFailure			-613  /* Checksum error in SLV file during backup */

#define JET_errCheckpointDepthTooDeep		-614	//	too many outstanding generations between checkpoint and current generation

#define JET_errRestoreOfNonBackupDatabase	-615	//	hard recovery attempted on a database that wasn't a backup database


#define JET_errInvalidGrbit					-900  /* Invalid parameter */

#define JET_errTermInProgress		  		-1000 /* Termination in progress */
#define JET_errFeatureNotAvailable			-1001 /* API not supported */
#define JET_errInvalidName					-1002 /* Invalid name */
#define JET_errInvalidParameter 			-1003 /* Invalid API parameter */
#define JET_wrnColumnNull					 1004 /* Column is NULL-valued */
#define JET_wrnBufferTruncated				 1006 /* Buffer too small for data */
#define JET_wrnDatabaseAttached 			 1007 /* Database is already attached */
#define JET_errDatabaseFileReadOnly			-1008 /* Tried to attach a read-only database file for read/write operations */
#define JET_wrnSortOverflow					 1009 /* Sort does not fit in memory */
#define JET_errInvalidDatabaseId			-1010 /* Invalid database id */
#define JET_errOutOfMemory					-1011 /* Out of Memory */
#define JET_errOutOfDatabaseSpace 			-1012 /* Maximum database size reached */
#define JET_errOutOfCursors					-1013 /* Out of table cursors */
#define JET_errOutOfBuffers					-1014 /* Out of database page buffers */
#define JET_errTooManyIndexes				-1015 /* Too many indexes */
#define JET_errTooManyKeys					-1016 /* Too many columns in an index */
#define JET_errRecordDeleted				-1017 /* Record has been deleted */
#define JET_errReadVerifyFailure			-1018 /* Checksum error on a database page */
#define JET_errPageNotInitialized			-1019 /* Blank database page */
#define JET_errOutOfFileHandles	 			-1020 /* Out of file handles */
#define JET_errDiskIO						-1022 /* Disk IO error */
#define JET_errInvalidPath					-1023 /* Invalid file path */
#define JET_errInvalidSystemPath			-1024 /* Invalid system path */
#define JET_errInvalidLogDirectory			-1025 /* Invalid log directory */
#define JET_errRecordTooBig					-1026 /* Record larger than maximum size */
#define JET_errTooManyOpenDatabases			-1027 /* Too many open databases */
#define JET_errInvalidDatabase				-1028 /* Not a database file */
#define JET_errNotInitialized				-1029 /* Database engine not initialized */
#define JET_errAlreadyInitialized			-1030 /* Database engine already initialized */
#define JET_errInitInProgress				-1031 /* Database engine is being initialized */
#define JET_errFileAccessDenied 			-1032 /* Cannot access file, the file is locked or in use */
#define JET_errBufferTooSmall				-1038 /* Buffer is too small */
#define JET_wrnSeekNotEqual					 1039 /* Exact match not found during seek */
#define JET_errTooManyColumns				-1040 /* Too many columns defined */
#define JET_errContainerNotEmpty			-1043 /* Container is not empty */
#define JET_errInvalidFilename				-1044 /* Filename is invalid */
#define JET_errInvalidBookmark				-1045 /* Invalid bookmark */
#define JET_errColumnInUse					-1046 /* Column used in an index */
#define JET_errInvalidBufferSize			-1047 /* Data buffer doesn't match column size */
#define JET_errColumnNotUpdatable			-1048 /* Cannot set column value */
#define JET_errIndexInUse					-1051 /* Index is in use */
#define JET_errLinkNotSupported 			-1052 /* Link support unavailable */
#define JET_errNullKeyDisallowed			-1053 /* Null keys are disallowed on index */
#define JET_errNotInTransaction 			-1054 /* Operation must be within a transaction */
#define JET_wrnNoErrorInfo					 1055 /* No extended error information */
#define JET_wrnNoIdleActivity		 		 1058 /* No idle activity occured */
#define JET_errTooManyActiveUsers			-1059 /* Too many active database users */
#define JET_errInvalidCountry				-1061 /* Invalid or unknown country code */
#define JET_errInvalidLanguageId			-1062 /* Invalid or unknown language id */
#define JET_errInvalidCodePage				-1063 /* Invalid or unknown code page */
#define JET_errInvalidLCMapStringFlags		-1064 /* Invalid flags for LCMapString() */
#define JET_errVersionStoreEntryTooBig		-1065 /* Attempted to create a version store entry (RCE) larger than a version bucket */
#define JET_errVersionStoreOutOfMemoryAndCleanupTimedOut	-1066 /* Version store out of memory (and cleanup attempt failed to complete) */
#define JET_wrnNoWriteLock					 1067 /* No write lock at transaction level 0 */
#define JET_wrnColumnSetNull		   		 1068 /* Column set to NULL-value */
#define JET_errVersionStoreOutOfMemory		-1069 /* Version store out of memory (cleanup already attempted) */
#define JET_errCannotIndex		 	  		-1071 /* Cannot index escrow column or SLV column */
#define JET_errRecordNotDeleted				-1072 /* Record has not been deleted */
#define JET_errTooManyMempoolEntries		-1073 /* Too many mempool entries requested */
#define JET_errOutOfObjectIDs				-1074 /* Out of btree ObjectIDs (perform offline defrag to reclaim freed/unused ObjectIds) */
#define JET_errOutOfLongValueIDs			-1075 /* Long-value ID counter has reached maximum value. (perform offline defrag to reclaim free/unused LongValueIDs) */
#define JET_errOutOfAutoincrementValues		-1076 /* Auto-increment counter has reached maximum value (offline defrag WILL NOT be able to reclaim free/unused Auto-increment values). */
#define JET_errOutOfDbtimeValues			-1077 /* Dbtime counter has reached maximum value (perform offline defrag to reclaim free/unused Dbtime values) */
#define JET_errOutOfSequentialIndexValues	-1078 /* Sequential index counter has reached maximum value (perform offline defrag to reclaim free/unused SequentialIndex values) */

#define JET_errRunningInOneInstanceMode		-1080 /* Multi-instance call with single-instance mode enabled */
#define JET_errRunningInMultiInstanceMode	-1081 /* Single-instance call with multi-instance mode enabled */
#define JET_errSystemParamsAlreadySet		-1082 /* Global system parameters have already been set */

#define JET_errSystemPathInUse				-1083 /* System path already used by another database instance */
#define JET_errLogFilePathInUse				-1084 /* Logfile path already used by another database instance */
#define JET_errTempPathInUse				-1085 /* Temp path already used by another database instance */
#define JET_errInstanceNameInUse			-1086 /* Instance Name already in use */

#define JET_errInstanceUnavailable			-1090 /* This instance cannot be used because it encountered a fatal error */
#define JET_errDatabaseUnavailable			-1091 /* This database cannot be used because it encountered a fatal error */
#define JET_errInstanceUnavailableDueToFatalLogDiskFull	-1092 /* This instance cannot be used because it encountered a log-disk-full error performing an operation (likely transaction rollback) that could not tolerate failure */

#define JET_errOutOfSessions  				-1101 /* Out of sessions */
#define JET_errWriteConflict				-1102 /* Write lock failed due to outstanding write lock */
#define JET_errTransTooDeep					-1103 /* Transactions nested too deeply */
#define JET_errInvalidSesid					-1104 /* Invalid session handle */
#define JET_errWriteConflictPrimaryIndex	-1105 /* Update attempted on uncommitted primary index */
#define JET_errInTransaction				-1108 /* Operation not allowed within a transaction */
#define JET_errRollbackRequired				-1109 /* Must rollback current transaction -- cannot commit or begin a new one */
#define JET_errTransReadOnly				-1110 /* Read-only transaction tried to modify the database */
#define JET_errSessionWriteConflict			-1111 /* Attempt to replace the same record by two diffrerent cursors in the same session */

#define JET_errRecordTooBigForBackwardCompatibility				-1112 /* record would be too big if represented in a database format from a previous version of Jet */
#define JET_errCannotMaterializeForwardOnlySort					-1113 /* The temp table could not be created due to parameters that conflict with JET_bitTTForwardOnly */


#define JET_errDatabaseDuplicate			-1201 /* Database already exists */
#define JET_errDatabaseInUse				-1202 /* Database in use */
#define JET_errDatabaseNotFound 			-1203 /* No such database */
#define JET_errDatabaseInvalidName			-1204 /* Invalid database name */
#define JET_errDatabaseInvalidPages			-1205 /* Invalid number of pages */
#define JET_errDatabaseCorrupted			-1206 /* Non database file or corrupted db */
#define JET_errDatabaseLocked				-1207 /* Database exclusively locked */
#define JET_errCannotDisableVersioning		-1208 /* Cannot disable versioning for this database */
#define JET_errInvalidDatabaseVersion		-1209 /* Database engine is incompatible with database */

/*	The following error code are for NT clients only. It will return such error during
 *	JetInit if JET_paramCheckFormatWhenOpenFail is set.
 */
#define JET_errDatabase200Format			-1210 /* The database is in an older (200) format */
#define JET_errDatabase400Format			-1211 /* The database is in an older (400) format */
#define JET_errDatabase500Format			-1212 /* The database is in an older (500) format */

#define JET_errPageSizeMismatch				-1213 /* The database page size does not match the engine */
#define JET_errTooManyInstances				-1214 /* Cannot start any more database instances */
#define JET_errDatabaseSharingViolation		-1215 /* A different database instance is using this database */
#define JET_errAttachedDatabaseMismatch		-1216 /* An outstanding database attachment has been detected at the start or end of recovery, but database is missing or does not match attachment info */
#define JET_errDatabaseInvalidPath			-1217 /* Specified path to database file is illegal */
#define JET_errDatabaseIdInUse				-1218 /* A database is being assigned an id already in use */
#define JET_errForceDetachNotAllowed 		-1219 /* Force Detach allowed only after normal detach errored out */
#define JET_errCatalogCorrupted				-1220 /* Corruption detected in catalog */
#define JET_errPartiallyAttachedDB			-1221 /* Database is partially attached. Cannot complete attach operation */
#define JET_errDatabaseSignInUse			-1222 /* Database with same signature in use */

#define JET_errDatabaseCorruptedNoRepair	-1224 /* Corrupted db but repair not allowed */

#define JET_wrnTableEmpty			 		 1301 /* Opened an empty table */
#define JET_errTableLocked					-1302 /* Table is exclusively locked */
#define JET_errTableDuplicate				-1303 /* Table already exists */
#define JET_errTableInUse					-1304 /* Table is in use, cannot lock */
#define JET_errObjectNotFound				-1305 /* No such table or object */
#define JET_errDensityInvalid				-1307 /* Bad file/index density */
#define JET_errTableNotEmpty				-1308 /* Table is not empty */
#define JET_errInvalidTableId				-1310 /* Invalid table id */
#define JET_errTooManyOpenTables			-1311 /* Cannot open any more tables (cleanup already attempted) */
#define JET_errIllegalOperation 			-1312 /* Oper. not supported on table */
#define JET_errTooManyOpenTablesAndCleanupTimedOut	-1313 /* Cannot open any more tables (cleanup attempt failed to complete) */
#define JET_errObjectDuplicate				-1314 /* Table or object name in use */
#define JET_errInvalidObject				-1316 /* Object is invalid for operation */
#define JET_errCannotDeleteTempTable		-1317 /* Use CloseTable instead of DeleteTable to delete temp table */
#define JET_errCannotDeleteSystemTable		-1318 /* Illegal attempt to delete a system table */
#define JET_errCannotDeleteTemplateTable	-1319 /* Illegal attempt to delete a template table */
#define JET_errExclusiveTableLockRequired	-1322 /* Must have exclusive lock on table. */
#define JET_errFixedDDL						-1323 /* DDL operations prohibited on this table */
#define JET_errFixedInheritedDDL			-1324 /* On a derived table, DDL operations are prohibited on inherited portion of DDL */
#define JET_errCannotNestDDL				-1325 /* Nesting of hierarchical DDL is not currently supported. */
#define JET_errDDLNotInheritable			-1326 /* Tried to inherit DDL from a table not marked as a template table. */
#define JET_wrnTableInUseBySystem			 1327 /* System cleanup has a cursor open on the table */
#define JET_errInvalidSettings				-1328 /* System parameters were set improperly */
#define JET_errClientRequestToStopJetService			-1329	/* Client has requested stop service */
#define JET_errCannotAddFixedVarColumnToDerivedTable	-1330	/* Template table was created with NoFixedVarColumnsInDerivedTables */

#define JET_errIndexCantBuild				-1401 /* Index build failed */
#define JET_errIndexHasPrimary				-1402 /* Primary index already defined */
#define JET_errIndexDuplicate				-1403 /* Index is already defined */
#define JET_errIndexNotFound				-1404 /* No such index */
#define JET_errIndexMustStay				-1405 /* Cannot delete clustered index */
#define JET_errIndexInvalidDef				-1406 /* Illegal index definition */
#define JET_errInvalidCreateIndex	 		-1409 /* Invalid create index description */
#define JET_errTooManyOpenIndexes			-1410 /* Out of index description blocks */
#define JET_errMultiValuedIndexViolation	-1411 /* Non-unique inter-record index keys generated for a multivalued index */
#define JET_errIndexBuildCorrupted			-1412 /* Failed to build a secondary index that properly reflects primary index */
#define JET_errPrimaryIndexCorrupted		-1413 /* Primary index is corrupt. The database must be defragmented */
#define JET_errSecondaryIndexCorrupted		-1414 /* Secondary index is corrupt. The database must be defragmented */
#define JET_wrnCorruptIndexDeleted			 1415 /* Out of date index removed */
#define JET_errInvalidIndexId				-1416 /* Illegal index id */

#define JET_errIndexTuplesSecondaryIndexOnly		-1430	//	tuple index can only be on a secondary index
#define JET_errIndexTuplesOneColumnOnly				-1431	//	tuple index may only have one column in the index
#define JET_errIndexTuplesNonUniqueOnly				-1432	//	tuple index must be a non-unique index
#define JET_errIndexTuplesTextColumnsOnly			-1433	//	tuple index must be on a text column
#define JET_errIndexTuplesVarSegMacNotAllowed		-1434	//	tuple index does not allow setting cbVarSegMac
#define JET_errIndexTuplesInvalidLimits				-1435	//	invalid min/max tuple length or max characters to index specified
#define JET_errIndexTuplesCannotRetrieveFromIndex	-1436	//	cannot call RetrieveColumn() with RetrieveFromIndex on a tuple index
#define JET_errIndexTuplesKeyTooSmall				-1437	//	specified key does not meet minimum tuple length

#define JET_errColumnLong					-1501 /* Column value is long */
#define JET_errColumnNoChunk				-1502 /* No such chunk in long value */
#define JET_errColumnDoesNotFit 			-1503 /* Field will not fit in record */
#define JET_errNullInvalid					-1504 /* Null not valid */
#define JET_errColumnIndexed				-1505 /* Column indexed, cannot delete */
#define JET_errColumnTooBig					-1506 /* Field length is greater than maximum */
#define JET_errColumnNotFound				-1507 /* No such column */
#define JET_errColumnDuplicate				-1508 /* Field is already defined */
#define JET_errMultiValuedColumnMustBeTagged	-1509 /* Attempted to create a multi-valued column, but column was not Tagged */
#define JET_errColumnRedundant				-1510 /* Second autoincrement or version column */
#define JET_errInvalidColumnType			-1511 /* Invalid column data type */
#define JET_wrnColumnMaxTruncated	 		 1512 /* Max length too big, truncated */
#define JET_errTaggedNotNULL				-1514 /* No non-NULL tagged columns */
#define JET_errNoCurrentIndex				-1515 /* Invalid w/o a current index */
#define JET_errKeyIsMade					-1516 /* The key is completely made */
#define JET_errBadColumnId					-1517 /* Column Id Incorrect */
#define JET_errBadItagSequence				-1518 /* Bad itagSequence for tagged column */
#define JET_errColumnInRelationship			-1519 /* Cannot delete, column participates in relationship */
#define JET_wrnCopyLongValue				 1520 /* Single instance column bursted */
#define JET_errCannotBeTagged				-1521 /* AutoIncrement and Version cannot be tagged */
#define JET_errDefaultValueTooBig			-1524 /* Default value exceeds maximum size */
#define JET_errMultiValuedDuplicate			-1525 /* Duplicate detected on a unique multi-valued column */
#define JET_errLVCorrupted					-1526 /* Corruption encountered in long-value tree */
#define JET_errMultiValuedDuplicateAfterTruncation	-1528 /* Duplicate detected on a unique multi-valued column after data was normalized, and normalizing truncated the data before comparison */
#define JET_errDerivedColumnCorruption		-1529 /* Invalid column in derived table */
#define JET_errInvalidPlaceholderColumn		-1530 /* Tried to convert column to a primary index placeholder, but column doesn't meet necessary criteria */
#define JET_wrnColumnSkipped				 1531 /* Column value(s) not returned because the corresponding column id or itagSequence requested for enumeration was null */
#define JET_wrnColumnNotLocal				 1532 /* Column value(s) not returned because they could not be reconstructed from the data at hand */
#define JET_wrnColumnMoreTags				 1533 /* Column values exist that were not requested for enumeration */
#define JET_wrnColumnTruncated				 1534 /* Column value truncated at the requested size limit during enumeration */
#define JET_wrnColumnPresent				 1535 /* Column values exist but were not returned by request */
#define JET_wrnColumnSingleValue			 1536 /* Column value returned in JET_COLUMNENUM as a result of JET_bitEnumerateCompressOutput */

#define JET_errRecordNotFound				-1601 /* The key was not found */
#define JET_errRecordNoCopy					-1602 /* No working buffer */
#define JET_errNoCurrentRecord				-1603 /* Currency not on a record */
#define JET_errRecordPrimaryChanged			-1604 /* Primary key may not change */
#define JET_errKeyDuplicate					-1605 /* Illegal duplicate key */
#define JET_errAlreadyPrepared				-1607 /* Attempted to update record when record update was already in progress */
#define JET_errKeyNotMade					-1608 /* No call to JetMakeKey */
#define JET_errUpdateNotPrepared			-1609 /* No call to JetPrepareUpdate */
#define JET_wrnDataHasChanged		 		 1610 /* Data has changed */
#define JET_errDataHasChanged				-1611 /* Data has changed, operation aborted */
#define JET_wrnKeyChanged			 		 1618 /* Moved to new key */
#define JET_errLanguageNotSupported			-1619 /* Windows installation does not support language */

#define JET_errTooManySorts					-1701 /* Too many sort processes */
#define JET_errInvalidOnSort				-1702 /* Invalid operation on Sort */
#define JET_errTempFileOpenError			-1803 /* Temp file could not be opened */
#define JET_errTooManyAttachedDatabases 	-1805 /* Too many open databases */
#define JET_errDiskFull 					-1808 /* No space left on disk */
#define JET_errPermissionDenied 			-1809 /* Permission denied */
#define JET_errFileNotFound					-1811 /* File not found */
#define JET_errFileInvalidType				-1812 /* Invalid file type */
#define JET_wrnFileOpenReadOnly				 1813 /* Database file is read only */
#define JET_errAfterInitialization			-1850 /* Cannot Restore after init. */
#define JET_errLogCorrupted					-1852 /* Logs could not be interpreted */
#define JET_errInvalidOperation 			-1906 /* Invalid operation */
#define JET_errAccessDenied					-1907 /* Access denied */
#define JET_wrnIdleFull						 1908 /* Idle registry full */
#define JET_errTooManySplits				-1909 /* Infinite split */
#define JET_errSessionSharingViolation		-1910 /* Multiple threads are using the same session */
#define JET_errEntryPointNotFound			-1911 /* An entry point in a DLL we require could not be found */
#define JET_errSessionContextAlreadySet		-1912 /* Specified session already has a session context set */
#define JET_errSessionContextNotSetByThisThread	-1913 /* Tried to reset session context, but current thread did not orignally set the session context */
#define JET_errSessionInUse					-1914 /* Tried to terminate session in use */

#define JET_errRecordFormatConversionFailed	-1915 /* Internal error during dynamic record format conversion */
#define JET_errOneDatabasePerSession		-1916 /* Just one open user database per session is allowed (JET_paramOneDatabasePerSession) */
#define JET_errRollbackError				-1917 /* error during rollback */

#define JET_wrnDefragAlreadyRunning			 2000 /* Online defrag already running on specified database */
#define JET_wrnDefragNotRunning				 2001 /* Online defrag not running on specified database */

#define JET_wrnCallbackNotRegistered         2100 /* Unregistered a non-existant callback function */
#define JET_errCallbackFailed				-2101 /* A callback failed */
#define JET_errCallbackNotResolved			-2102 /* A callback function could not be found */


#define JET_errOSSnapshotInvalidSequence	-2401 /* OS Shadow copy API used in an invalid sequence */
#define JET_errOSSnapshotTimeOut			-2402 /* OS Shadow copy ended with time-out */
#define JET_errOSSnapshotNotAllowed			-2403 /* OS Shadow copy not allowed (backup or recovery in progress) */

#define JET_errLSCallbackNotSpecified		-3000 /* Attempted to use Local Storage without a callback function being specified */
#define JET_errLSAlreadySet					-3001 /* Attempted to set Local Storage for an object which already had it set */
#define JET_errLSNotSet						-3002 /* Attempted to retrieve Local Storage from an object which didn't have it set */

/** FILE ERRORS
 **/
//JET_errFileAccessDenied					-1032
//JET_errFileNotFound						-1811
//JET_errInvalidFilename					-1044
#define JET_errFileIOBeyondEOF				-4001 /* a read was issued to a location beyond EOF (writes will expand the file) */
#define JET_errFileIOAbort					-4002 /* instructs the JET_ABORTRETRYFAILCALLBACK caller to abort the specified I/O */
#define JET_errFileIORetry					-4003 /* instructs the JET_ABORTRETRYFAILCALLBACK caller to retry the specified I/O */
#define JET_errFileIOFail					-4004 /* instructs the JET_ABORTRETRYFAILCALLBACK caller to fail the specified I/O */
#define JET_errFileCompressed				-4005 /* read/write access is not supported on compressed files */

/**********************************************************************/
/***********************     PROTOTYPES      **************************/
/**********************************************************************/

#if !defined(_JET_NOPROTOTYPES)

#ifdef __cplusplus
extern "C" {
#endif


JET_ERR JET_API JetInit( JET_INSTANCE *pinstance);
#ifdef JET_VERSION_XP
JET_ERR JET_API JetInit2( JET_INSTANCE *pinstance, JET_GRBIT grbit );
#endif // JET_VERSION_XP

#ifdef JET_VERSION_XP
JET_ERR JET_API JetCreateInstance( JET_INSTANCE *pinstance, const char * szInstanceName );
JET_ERR JET_API JetCreateInstance2(
	JET_INSTANCE *pinstance,
	const char * szInstanceName,
	const char * szDisplayName,
	JET_GRBIT grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetTerm( JET_INSTANCE instance );
JET_ERR JET_API JetTerm2( JET_INSTANCE instance, JET_GRBIT grbit );

JET_ERR JET_API JetStopService();
#ifdef JET_VERSION_XP
JET_ERR JET_API JetStopServiceInstance( JET_INSTANCE instance );
#endif // JET_VERSION_XP

JET_ERR JET_API JetStopBackup();
#ifdef JET_VERSION_XP
JET_ERR JET_API JetStopBackupInstance( JET_INSTANCE instance );
#endif // JET_VERSION_XP

JET_ERR JET_API JetSetSystemParameter(
	JET_INSTANCE	*pinstance,
	JET_SESID		sesid,
	unsigned long	paramid,
	JET_API_PTR		lParam,
	const char		*sz );

JET_ERR JET_API JetGetSystemParameter(
	JET_INSTANCE	instance,
	JET_SESID		sesid,
	unsigned long	paramid,
	JET_API_PTR		*plParam,
	char			*sz,
	unsigned long	cbMax );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetEnableMultiInstance( 	JET_SETSYSPARAM *	psetsysparam,
											unsigned long 		csetsysparam,
											unsigned long *		pcsetsucceed);
#endif // JET_VERSION_XP


JET_ERR JET_API JetBeginSession(
	JET_INSTANCE	instance,
	JET_SESID		*psesid,
	const char		*szUserName,
	const char		*szPassword );

JET_ERR JET_API JetDupSession( JET_SESID sesid, JET_SESID *psesid );

JET_ERR JET_API JetEndSession( JET_SESID sesid, JET_GRBIT grbit );

JET_ERR JET_API JetGetVersion( JET_SESID sesid, unsigned long *pwVersion );

JET_ERR JET_API JetIdle( JET_SESID sesid, JET_GRBIT grbit );

JET_ERR JET_API JetCreateDatabase(
	JET_SESID		sesid,
	const char		*szFilename,
	const char		*szConnect,
	JET_DBID		*pdbid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetCreateDatabase2(
	JET_SESID		sesid,
	const char		*szFilename,
	const unsigned long	cpgDatabaseSizeMax,
	JET_DBID		*pdbid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetAttachDatabase(
	JET_SESID		sesid,
	const char		*szFilename,
	JET_GRBIT		grbit );

JET_ERR JET_API JetAttachDatabase2(
	JET_SESID		sesid,
	const char		*szFilename,
	const unsigned long	cpgDatabaseSizeMax,
	JET_GRBIT		grbit );

JET_ERR JET_API JetDetachDatabase(
	JET_SESID		sesid,
	const char		*szFilename );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetDetachDatabase2(
	JET_SESID		sesid,
	const char		*szFilename,
	JET_GRBIT 		grbit);
#endif // JET_VERSION_XP

JET_ERR JET_API JetGetObjectInfo(
	JET_SESID		sesid,
	JET_DBID		dbid,
	JET_OBJTYP		objtyp,
	const char		*szContainerName,
	const char		*szObjectName,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetGetTableInfo(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetCreateTable(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	unsigned long	lPages,
	unsigned long	lDensity,
	JET_TABLEID		*ptableid );

JET_ERR JET_API JetCreateTableColumnIndex(
	JET_SESID		sesid,
	JET_DBID		dbid,
	JET_TABLECREATE	*ptablecreate );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetCreateTableColumnIndex2(
	JET_SESID		sesid,
	JET_DBID		dbid,
	JET_TABLECREATE2	*ptablecreate );
#endif // JET_VERSION_XP

JET_ERR JET_API JetDeleteTable(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName );

JET_ERR JET_API JetRenameTable(
	JET_SESID sesid,
	JET_DBID dbid,
	const char *szName,
	const char *szNameNew );

JET_ERR JET_API JetGetTableColumnInfo(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szColumnName,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetGetColumnInfo(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	const char		*szColumnName,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetAddColumn(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szColumnName,
	const JET_COLUMNDEF	*pcolumndef,
	const void		*pvDefault,
	unsigned long	cbDefault,
	JET_COLUMNID	*pcolumnid );

JET_ERR JET_API JetDeleteColumn(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szColumnName );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetDeleteColumn2(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szColumnName,
	const JET_GRBIT	grbit );

JET_ERR JET_API JetRenameColumn(
	JET_SESID 		sesid,
	JET_TABLEID		tableid,
	const char 		*szName,
	const char 		*szNameNew,
	JET_GRBIT		grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetSetColumnDefaultValue(
	JET_SESID			sesid,
	JET_DBID			dbid,
	const char			*szTableName,
	const char			*szColumnName,
	const void			*pvData,
	const unsigned long	cbData,
	const JET_GRBIT		grbit );

JET_ERR JET_API JetGetTableIndexInfo(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName,
	void			*pvResult,
	unsigned long	cbResult,
	unsigned long	InfoLevel );

JET_ERR JET_API JetGetIndexInfo(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	const char		*szIndexName,
	void			*pvResult,
	unsigned long	cbResult,
	unsigned long	InfoLevel );

JET_ERR JET_API JetCreateIndex(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName,
	JET_GRBIT		grbit,
	const char		*szKey,
	unsigned long	cbKey,
	unsigned long	lDensity );

JET_ERR JET_API JetCreateIndex2(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_INDEXCREATE	*pindexcreate,
	unsigned long	cIndexCreate );

JET_ERR JET_API JetDeleteIndex(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName );

JET_ERR JET_API JetBeginTransaction( JET_SESID sesid );
JET_ERR JET_API JetBeginTransaction2( JET_SESID sesid, JET_GRBIT grbit );

JET_ERR JET_API JetCommitTransaction( JET_SESID sesid, JET_GRBIT grbit );

JET_ERR JET_API JetRollback( JET_SESID sesid, JET_GRBIT grbit );

JET_ERR JET_API JetGetDatabaseInfo(
	JET_SESID		sesid,
	JET_DBID		dbid,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetGetDatabaseFileInfo(
	const char		*szDatabaseName,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetOpenDatabase(
	JET_SESID		sesid,
	const char		*szFilename,
	const char		*szConnect,
	JET_DBID		*pdbid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetCloseDatabase(
	JET_SESID		sesid,
	JET_DBID		dbid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetOpenTable(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	const void		*pvParameters,
	unsigned long	cbParameters,
	JET_GRBIT		grbit,
	JET_TABLEID		*ptableid );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetSetTableSequential(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetResetTableSequential(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_GRBIT		grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetCloseTable( JET_SESID sesid, JET_TABLEID tableid );

JET_ERR JET_API JetDelete( JET_SESID sesid, JET_TABLEID tableid );

JET_ERR JET_API JetUpdate(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void			*pvBookmark,
	unsigned long	cbBookmark,
	unsigned long	*pcbActual);

#ifdef JET_VERSION_SERVER2003
JET_ERR JET_API JetUpdate2(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void			*pvBookmark,
	unsigned long	cbBookmark,
	unsigned long	*pcbActual,
	const JET_GRBIT	grbit );
#endif // JET_VERSION_SERVER2003

JET_ERR JET_API JetEscrowUpdate(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_COLUMNID	columnid,
	void			*pv,
	unsigned long	cbMax,
	void			*pvOld,
	unsigned long	cbOldMax,
	unsigned long	*pcbOldActual,
	JET_GRBIT		grbit );

JET_ERR JET_API JetRetrieveColumn(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_COLUMNID	columnid,
	void			*pvData,
	unsigned long	cbData,
	unsigned long	*pcbActual,
	JET_GRBIT		grbit,
	JET_RETINFO		*pretinfo );

JET_ERR JET_API JetRetrieveColumns(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_RETRIEVECOLUMN	*pretrievecolumn,
	unsigned long	cretrievecolumn );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetEnumerateColumns(
	JET_SESID				sesid,
	JET_TABLEID				tableid,
	unsigned long			cEnumColumnId,
	JET_ENUMCOLUMNID*		rgEnumColumnId,
	unsigned long*			pcEnumColumn,
	JET_ENUMCOLUMN**		prgEnumColumn,
	JET_PFNREALLOC			pfnRealloc,
	void*					pvReallocContext,
	unsigned long			cbDataMost,
	JET_GRBIT				grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetSetColumn(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_COLUMNID	columnid,
	const void		*pvData,
	unsigned long	cbData,
	JET_GRBIT		grbit,
	JET_SETINFO		*psetinfo );

JET_ERR JET_API JetSetColumns(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_SETCOLUMN	*psetcolumn,
	unsigned long	csetcolumn );

JET_ERR JET_API JetPrepareUpdate(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	unsigned long	prep );

JET_ERR JET_API JetGetRecordPosition(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_RECPOS		*precpos,
	unsigned long	cbRecpos );

JET_ERR JET_API JetGotoPosition(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_RECPOS		*precpos );

JET_ERR JET_API JetGetCursorInfo(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void			*pvResult,
	unsigned long	cbMax,
	unsigned long	InfoLevel );

JET_ERR JET_API JetDupCursor(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_TABLEID		*ptableid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetGetCurrentIndex(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	char			*szIndexName,
	unsigned long	cchIndexName );

JET_ERR JET_API JetSetCurrentIndex(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName );

JET_ERR JET_API JetSetCurrentIndex2(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName,
	JET_GRBIT		grbit );

JET_ERR JET_API JetSetCurrentIndex3(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName,
	JET_GRBIT		grbit,
	unsigned long	itagSequence );

JET_ERR JET_API JetSetCurrentIndex4(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const char		*szIndexName,
	JET_INDEXID		*pindexid,
	JET_GRBIT		grbit,
	unsigned long	itagSequence );

JET_ERR JET_API JetMove(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	long			cRow,
	JET_GRBIT		grbit );

JET_ERR JET_API JetGetLock(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetMakeKey(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	const void		*pvData,
	unsigned long	cbData,
	JET_GRBIT		grbit );

JET_ERR JET_API JetSeek(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	JET_GRBIT		grbit );

JET_ERR JET_API JetGetBookmark(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void *			pvBookmark,
	unsigned long	cbMax,
	unsigned long *	pcbActual );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetGetSecondaryIndexBookmark(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void *			pvSecondaryKey,
	unsigned long	cbSecondaryKeyMax,
	unsigned long *	pcbSecondaryKeyActual,
	void *			pvPrimaryBookmark,
	unsigned long	cbPrimaryBookmarkMax,
	unsigned long *	pcbPrimaryKeyActual,
	const JET_GRBIT	grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetCompact(
	JET_SESID		sesid,
	const char		*szDatabaseSrc,
	const char		*szDatabaseDest,
	JET_PFNSTATUS	pfnStatus,
	JET_CONVERT		*pconvert,
	JET_GRBIT		grbit );

JET_ERR JET_API JetDefragment(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	unsigned long	*pcPasses,
	unsigned long	*pcSeconds,
	JET_GRBIT		grbit );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetDefragment2(
	JET_SESID		sesid,
	JET_DBID		dbid,
	const char		*szTableName,
	unsigned long	*pcPasses,
	unsigned long	*pcSeconds,
	JET_CALLBACK	callback,
	JET_GRBIT		grbit );

JET_ERR JET_API JetDefragment3(
	JET_SESID		vsesid,
	const char		*szDatabaseName,
	const char		*szTableName,
	unsigned long	*pcPasses,
	unsigned long	*pcSeconds,
	JET_CALLBACK	callback,
	void			*pvContext,
	JET_GRBIT		grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetSetDatabaseSize(
	JET_SESID		sesid,
	const char		*szDatabaseName,
	unsigned long	cpg,
	unsigned long	*pcpgReal );

JET_ERR JET_API JetGrowDatabase(
	JET_SESID		sesid,
	JET_DBID		dbid,
	unsigned long	cpg,
	unsigned long	*pcpgReal );

JET_ERR JET_API JetSetSessionContext(
	JET_SESID		sesid,
	JET_API_PTR		ulContext );

JET_ERR JET_API JetResetSessionContext(
	JET_SESID		sesid );

JET_ERR JET_API JetGotoBookmark(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void *			pvBookmark,
	unsigned long	cbBookmark );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetGotoSecondaryIndexBookmark(
	JET_SESID		sesid,
	JET_TABLEID		tableid,
	void *			pvSecondaryKey,
	unsigned long	cbSecondaryKey,
	void *			pvPrimaryBookmark,
	unsigned long	cbPrimaryBookmark,
	const JET_GRBIT	grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetIntersectIndexes(
	JET_SESID sesid,
	JET_INDEXRANGE * rgindexrange,
	unsigned long cindexrange,
	JET_RECORDLIST * precordlist,
	JET_GRBIT grbit );

JET_ERR JET_API JetComputeStats( JET_SESID sesid, JET_TABLEID tableid );

JET_ERR JET_API JetOpenTempTable(JET_SESID sesid,
	const JET_COLUMNDEF *prgcolumndef, unsigned long ccolumn,
	JET_GRBIT grbit, JET_TABLEID *ptableid,
	JET_COLUMNID *prgcolumnid);

JET_ERR JET_API JetOpenTempTable2(
	JET_SESID			sesid,
	const JET_COLUMNDEF	*prgcolumndef,
	unsigned long		ccolumn,
	unsigned long		lcid,
	JET_GRBIT			grbit,
	JET_TABLEID			*ptableid,
	JET_COLUMNID		*prgcolumnid );

JET_ERR JET_API JetOpenTempTable3(
	JET_SESID			sesid,
	const JET_COLUMNDEF	*prgcolumndef,
	unsigned long		ccolumn,
	JET_UNICODEINDEX	*pidxunicode,
	JET_GRBIT			grbit,
	JET_TABLEID			*ptableid,
	JET_COLUMNID		*prgcolumnid );

JET_ERR JET_API JetBackup( const char *szBackupPath, JET_GRBIT grbit, JET_PFNSTATUS pfnStatus );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetBackupInstance(	JET_INSTANCE 	instance,
									const char		*szBackupPath,
									JET_GRBIT		grbit,
									JET_PFNSTATUS	pfnStatus );
#endif // JET_VERSION_XP

JET_ERR JET_API JetRestore(const char *sz, JET_PFNSTATUS pfn );
JET_ERR JET_API JetRestore2(const char *sz, const char *szDest, JET_PFNSTATUS pfn );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetRestoreInstance( 	JET_INSTANCE instance,
										const char *sz,
										const char *szDest,
										JET_PFNSTATUS pfn );
#endif // JET_VERSION_XP

JET_ERR JET_API JetSetIndexRange(JET_SESID sesid,
	JET_TABLEID tableidSrc, JET_GRBIT grbit);

JET_ERR JET_API JetIndexRecordCount(JET_SESID sesid,
	JET_TABLEID tableid, unsigned long *pcrec, unsigned long crecMax );

JET_ERR JET_API JetRetrieveKey(JET_SESID sesid,
	JET_TABLEID tableid, void *pvData, unsigned long cbMax,
	unsigned long *pcbActual, JET_GRBIT grbit );

JET_ERR JET_API JetBeginExternalBackup( JET_GRBIT grbit );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetBeginExternalBackupInstance( JET_INSTANCE instance, JET_GRBIT grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetGetAttachInfo( void *pv,
	unsigned long cbMax,
	unsigned long *pcbActual );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetGetAttachInfoInstance(	JET_INSTANCE	instance,
											void			*pv,
											unsigned long	cbMax,
											unsigned long	*pcbActual );
#endif // JET_VERSION_XP

JET_ERR JET_API JetOpenFile( const char *szFileName,
	JET_HANDLE	*phfFile,
	unsigned long *pulFileSizeLow,
	unsigned long *pulFileSizeHigh );

#ifdef JET_VERSION_XP
JET_ERR JET_API JetOpenFileInstance( 	JET_INSTANCE instance,
										const char *szFileName,
										JET_HANDLE	*phfFile,
										unsigned long *pulFileSizeLow,
										unsigned long *pulFileSizeHigh );
#endif // JET_VERSION_XP

JET_ERR JET_API JetReadFile( JET_HANDLE hfFile,
	void *pv,
	unsigned long cb,
	unsigned long *pcb );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetReadFileInstance(	JET_INSTANCE instance,
										JET_HANDLE hfFile,
										void *pv,
										unsigned long cb,
										unsigned long *pcb );
#endif // JET_VERSION_XP

JET_ERR JET_API JetCloseFile( JET_HANDLE hfFile );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetCloseFileInstance( JET_INSTANCE instance, JET_HANDLE hfFile );
#endif // JET_VERSION_XP

JET_ERR JET_API JetGetLogInfo( void *pv,
	unsigned long cbMax,
	unsigned long *pcbActual );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetGetLogInfoInstance(	JET_INSTANCE instance,
										void *pv,
										unsigned long cbMax,
										unsigned long *pcbActual );

#define JET_BASE_NAME_LENGTH 	3
typedef struct
	{
	unsigned long 	cbSize;
	unsigned long	ulGenLow;
	unsigned long	ulGenHigh;
	char			szBaseName[ JET_BASE_NAME_LENGTH + 1 ];
	} JET_LOGINFO;

JET_ERR JET_API JetGetLogInfoInstance2(	JET_INSTANCE instance,
										void *pv,
										unsigned long cbMax,
										unsigned long *pcbActual,
										JET_LOGINFO * pLogInfo);

JET_ERR JET_API JetGetTruncateLogInfoInstance(	JET_INSTANCE instance,
												void *pv,
												unsigned long cbMax,
												unsigned long *pcbActual );
#endif // JET_VERSION_XP

JET_ERR JET_API JetTruncateLog( void );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetTruncateLogInstance( JET_INSTANCE instance );
#endif // JET_VERSION_XP

JET_ERR JET_API JetEndExternalBackup( void );
#ifdef JET_VERSION_XP
JET_ERR JET_API JetEndExternalBackupInstance( JET_INSTANCE instance );

/* Flags for JetEndExternalBackupInstance2 */
#define JET_bitBackupEndNormal				0x0001
#define JET_bitBackupEndAbort				0x0002

JET_ERR JET_API JetEndExternalBackupInstance2( JET_INSTANCE instance, JET_GRBIT grbit );
#endif // JET_VERSION_XP

JET_ERR JET_API JetExternalRestore( 	char *szCheckpointFilePath,
										char *szLogPath,
										JET_RSTMAP *rgstmap,
										long crstfilemap,
										char *szBackupLogPath,
										long genLow,
										long genHigh,
										JET_PFNSTATUS pfn );


#ifdef JET_VERSION_XP
JET_ERR JET_API JetExternalRestore2( 	char *szCheckpointFilePath,
										char *szLogPath,
										JET_RSTMAP *rgstmap,
										long crstfilemap,
										char *szBackupLogPath,
										JET_LOGINFO * pLogInfo,
										char *szTargetInstanceName,
										char *szTargetInstanceLogPath,
										char *szTargetInstanceCheckpointPath,
										JET_PFNSTATUS pfn );


JET_ERR JET_API JetRegisterCallback(
	JET_SESID               sesid,
	JET_TABLEID             tableid,
	JET_CBTYP               cbtyp,
	JET_CALLBACK    		pCallback,
	void *              	pvContext,
	JET_HANDLE              *phCallbackId );


JET_ERR JET_API JetUnregisterCallback(
	JET_SESID               sesid,
	JET_TABLEID             tableid,
	JET_CBTYP               cbtyp,
	JET_HANDLE              hCallbackId );

typedef struct _JET_INSTANCE_INFO
	{
	JET_INSTANCE		hInstanceId;
	char * 				szInstanceName;

	JET_API_PTR	 		cDatabases;
	char ** 			szDatabaseFileName;
	char ** 			szDatabaseDisplayName;
	char ** 			szDatabaseSLVFileName;
	} JET_INSTANCE_INFO;

JET_ERR JET_API JetGetInstanceInfo( unsigned long *pcInstanceInfo, JET_INSTANCE_INFO ** paInstanceInfo );


JET_ERR JET_API JetFreeBuffer( char *pbBuf );

JET_ERR JET_API JetSetLS(
	JET_SESID 		sesid,
	JET_TABLEID		tableid,
	JET_LS			ls,
	JET_GRBIT		grbit );

JET_ERR JET_API JetGetLS(
	JET_SESID 		sesid,
	JET_TABLEID		tableid,
	JET_LS			*pls,
	JET_GRBIT		grbit );

typedef JET_API_PTR JET_OSSNAPID;  	/* Snapshot Session Identifier */

JET_ERR JET_API JetOSSnapshotPrepare( JET_OSSNAPID * psnapId, const JET_GRBIT grbit );
JET_ERR JET_API JetOSSnapshotFreeze( const JET_OSSNAPID snapId, unsigned long *pcInstanceInfo, JET_INSTANCE_INFO ** paInstanceInfo, const JET_GRBIT grbit );
JET_ERR JET_API JetOSSnapshotThaw( const JET_OSSNAPID snapId, const JET_GRBIT grbit );
#endif // JET_VERSION_XP

#ifdef JET_VERSION_SERVER2003
JET_ERR JET_API JetOSSnapshotAbort( const JET_OSSNAPID snapId, const JET_GRBIT grbit );
#endif // JET_VERSION_SERVER2003


#ifdef	__cplusplus
}
#endif

#endif	/* _JET_NOPROTOTYPES */

#include <poppack.h>

#ifdef	__cplusplus
}
#endif

#endif	/* _JET_INCLUDED */

