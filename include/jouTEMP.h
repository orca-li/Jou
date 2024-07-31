/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.2.1
 */
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

#if jconfigLITE_VERSION == 1
#define jouINOUT_PRINT(...) JOU_PRINT(__VA_ARGS__)
#define jouINOUT_SCAN(...) JOU_SCAN(__VA_ARGS__)
#define jouINOUT_PUTC(...) JOU_PUTC(__VA_ARGS__)
#define jouINOUT_GETC(...) JOU_GETC(__VA_ARGS__)

#else
#define jouINOUT_PRINT(...) jou.print(__VA_ARGS__)
#define jouINOUT_SCAN(...) jou.scan(__VA_ARGS__)
#define jouINOUT_PUTC(...) jou.putc(__VA_ARGS__)
#define jouINOUT_GETC(...) jou.getc(__VA_ARGS__)

#endif

#endif /* JOUTEMP_H */