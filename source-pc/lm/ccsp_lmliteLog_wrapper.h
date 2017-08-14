#ifndef  _CCSP_LMLITELOG_WRPPER_H_ 
#define  _CCSP_LMLITELOG_WRPPER_H_

#include "ccsp_custom_logs.h"

#ifdef MLT_ENABLED
#include "rpl_malloc.h"
#include "mlt_malloc.h"
#endif
extern ANSC_HANDLE bus_handle;
extern char g_Subsystem[32];
extern int consoleDebugEnable;
extern FILE* debugLogFile;

/*
 * Logging wrapper APIs g_Subsystem
 */
#define  CcspTraceBaseStr(arg ...)                                                                  \
            do {                                                                                    \
                snprintf(pTempChar1, 4095, arg);                                                    \
            } while (FALSE)


#define  CcspLMLiteConsoleTrace(msg)                                                             \
{\
		    char pTempChar1[4096]; 							\
                    CcspTraceBaseStr msg;                                                           \
                    if(consoleDebugEnable)                                                          \
                    {\
                        fprintf(debugLogFile, "%s:%d: ", __FILE__, __LINE__);                       \
                        fprintf(debugLogFile, "%s", pTempChar1);                                    \
                        fflush(debugLogFile);                                                       \
                    }\
}

#define  CcspLMLiteTrace(msg)                                                                    \
{\
		    char pTempChar1[4096]; 							\
                    CcspTraceBaseStr msg;                                                           \
                    if(consoleDebugEnable)                                                          \
                    {\
                        fprintf(debugLogFile, "%s:%d: ", __FILE__, __LINE__); \
                        fprintf(debugLogFile, "%s", pTempChar1);                                    \
                        fflush(debugLogFile);                                                       \
                    }\
                    WriteLog(pTempChar1,bus_handle,g_Subsystem,"Device.LogAgent.HarvesterLogMsg");  \
}

#define  CcspLMLiteEventTrace(msg)                                                               \
{\
		    char pTempChar1[4096];							\
                    CcspTraceBaseStr msg;                                                           \
                    if(consoleDebugEnable)                                                          \
                    {\
                        fprintf(debugLogFile, "%s:%d: ", __FILE__, __LINE__); \
                        fprintf(debugLogFile, "%s", pTempChar1);                                    \
                        fflush(debugLogFile);                                                       \
                    }\
                    WriteLog(pTempChar1,bus_handle,"eRT.","Device.LogAgent.HarvesterEventLogMsg");  \
}


#endif