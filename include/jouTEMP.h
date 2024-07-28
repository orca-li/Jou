#if !defined(JOUTEMP_H)
#define JOUTEMP_H

#include "jouERR.h"
#include "jouFMT.h"
#include "jouSUP.h"

#if JCONFIG_TEMP_TARGET == 0ul

/* >= 0 && < 10 stdio */
#elif JCONFIG_TEMP_TARGET == 1ul
#define JCONFIG_TUNNEL_PRINT(_buffer) fputs(_buffer, stdout)
#define JCONFIG_TUNNEL_PUTC(_char) fputc(_char, stdout)
#define JCONFIG_TUNNEL_SCAN(_buffer) fgets(_buffer, JCONFIG_SCANJ_BUF_SIZE, stdin)
#define JCONFIG_TUNNEL_GETC(_char) fgetc(stdin)

/* >= 10 && < 100 stm32 hal */
#elif JCONFIG_TEMP_TARGET == 10ul 
#define JCONFIG_TUNNEL_PRINT(_buffer) HAL_UART_Transmit(&huart1, (uint8_t *)_buffer, strlen(_buffer), 5)
#define JCONFIG_TUNNEL_PUTC(_char) HAL_UART_Transmit(&huart1, (uint8_t *)_buffer, 1, 2)
#define JCONFIG_TUNNEL_SCAN
#define JCONFIG_TUNNEL_GETC

#elif JCONFIG_TEMP_TARGET == 20ul
#define JCONFIG_TUNNEL_PRINT(_buffer) HAL_UART_Transmit(&huart2, (uint8_t *)_buffer, strlen(_buffer), 5)
#define JCONFIG_TUNNEL_PUTC(_char) HAL_UART_Transmit(&huart2, (uint8_t *)_buffer, 1, 2)
#define JCONFIG_TUNNEL_SCAN
#define JCONFIG_TUNNEL_GETC

/* >= 100 && < 1000 stm32 liteMCU */

#endif 

#endif /* JOUTEMP_H */