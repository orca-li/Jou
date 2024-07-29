/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#if !defined(JOUERR_H)
#define JOUERR_H

#include "jouCONFIG.h"

#if ((JCONFIG_PROCESSOR_CAPACITY % 8) != 0) && (JCONFIG_PROCESSOR_CAPACITY <= 0) && (JCONFIG_PROCESSOR_CAPACITY >= 65) 
#error "((JCONFIG_PROCESSOR_CAPACITY % 8) != 0) && (JCONFIG_PROCESSOR_CAPACITY <= 0) && (JCONFIG_PROCESSOR_CAPACITY >= 65) "
#endif

#if (JCONFIG_PROCESSOR_CAPACITY != 16)
#warning "it is forbidden to use such settings"
#endif


#if defined(JOU_DEVELOPER)
#warning "turn off JOU_DEVELOPER if you are not the developer of this library"
#endif

#endif /* JOUERR_H */
