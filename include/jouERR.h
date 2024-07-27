#if !defined(JOUERR_H)
#define JOUERR_H

#include "jouCONFIG.h"

#if ((JCONFIG_PROCESSOR_CAPACITY % 8) != 0) && (JCONFIG_PROCESSOR_CAPACITY <= 0) && (JCONFIG_PROCESSOR_CAPACITY >= 65) 
#error "((JCONFIG_PROCESSOR_CAPACITY % 8) != 0) && (JCONFIG_PROCESSOR_CAPACITY <= 0) && (JCONFIG_PROCESSOR_CAPACITY >= 65) "
#endif


#if defined(JOU_DEVELOPER)
#warning "turn off JOU_DEVELOPER if you are not the developer of this library"
#endif

#endif /* JOUERR_H */
