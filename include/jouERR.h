/**
 * @copyright MIT License (C) 2024 Orcali
 * @version 0.2
 */
#if !defined(JOUERR_H)
#define JOUERR_H

#include "jouCONFIG.h"

#if ((jconfigPROCESSOR_CAPACITY % 8) != 0) && (JCONFIG_PROCESSOR_CAPACITY <= 0) && (jconfigPROCESSOR_CAPACITY >= 65) 
#error "rules for jconfigPROCESSOR_CAPACITY: %8 != 0, >0, <65"
#endif

#if (jconfigPROCESSOR_CAPACITY != 16)
#warning "it is forbidden to use such settings"
#endif


#if defined(JOU_DEVELOPER)
#warning "turn off JOU_DEVELOPER if you are not the developer of this library"
#endif

#endif /* JOUERR_H */
