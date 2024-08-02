/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.2.2
 */
#if !defined(__JOU_VERSION_H__)
#define __JOU_VERSION_H__

#include "jouCONFIG.h"

#if jconfigLITE_VERSION == 1

void jouPrint(char *fmt, ...);
void jouScan(char *fmt, ...);
void jouPut(char c);
int jouGetChar(void);

void jouLevelInfo(char *fmt, ...);
void jouLevelDebug(char *fmt, ...);
void jouLevelError(char *fmt, ...);
void jouLevelWarning(char *fmt, ...);

#define JOUE(...) jouLevelError(__VA_ARGS__)
#define JOUI(...) jouLevelInfo(__VA_ARGS__)
#define JOUW(...) jouLevelWarning(__VA_ARGS__)
#define JOUD(...) jouLevelDebug(__VA_ARGS__)

#define JOUP(...) jouPrint(__VA_ARGS__)
#define JOUS(...) jouScan(__VA_ARGS__)
#define JOUG() jouGetChar()
#define JOUC(...) jouPut(__VA_ARGS__)

#if jconfigAPI_DUMP_HEX == 1
void jouHexDump(char *buf, size_t len);
#define JOUX(...) jouHexDump(__VA_ARGS__)
#endif

#if jconfigAPI_DUMP_BIN == 1
void jouBinDump(char *buf, size_t len);
#define JOUB(...) jouBinDump(__VA_ARGS__)
#endif


#if jconfigAPI_ADDONS_HOOK == 1
void jouLevelHook(char *fmt, ...);
#define JOUH(...)
#endif
#if jconfigAPI_ADDONS_TAG == 1
void jouTagPrint(char *tag, char *fmt, ...);
#define JOUT(...)
#endif

#endif 

#endif /* __JOU_VERSION_H__ */