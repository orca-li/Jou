/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.2.2
 */
#if !defined(JOUTEMP_H)
#define JOUTEMP_H

#include "jouERR.h"
#include "jouFMT.h"
#include "jouSUP.h"

#if jconfigTEMP_TARGET == 0x0000
/* templates: off */

/* 0x0000 - 0x000F | stdio */
#elif jconfigTEMP_TARGET == 0x0001
#define jconfigVIFC_PRINT(_buffer) fputs(_buffer, stdout)
#define jconfigVIFC_PUTC(_char) fputc(_char, stdout)
#define jconfigVIFC_SCAN(_buffer) fgets(_buffer, jconfigSCANJ_BUF_SIZE, stdin)
#define jconfigVIFC_GETC(_char) fgetc(stdin)

/* 0x0100 - 0x01FF | stm32 hal */
#elif jconfigTEMP_TARGET == 0x0100
#define jconfigVIFC_PRINT(_buffer) HAL_UART_Transmit(&huart1, (uint8_t *)_buffer, strlen(_buffer), 5)
#define jconfigVIFC_PUTC(_char) HAL_UART_Transmit(&huart1, (uint8_t *)_buffer, 1, 2)
#define jconfigVIFC_SCAN
#define jconfigVIFC_GETC

#elif jconfigTEMP_TARGET == 0x0101
#define jconfigVIFC_PRINT(_buffer) HAL_UART_Transmit(&huart2, (uint8_t *)_buffer, strlen(_buffer), 5)
#define jconfigVIFC_PUTC(_char) HAL_UART_Transmit(&huart2, (uint8_t *)_buffer, 1, 2)
#define jconfigVIFC_SCAN
#define jconfigVIFC_GETC

/* 0x0200 - 0x02FF | stm32 liteMCU */


#endif 

#if jconfigLITE_VERSION == 1
#define jouINOUT_PRINT(...) JOUP(__VA_ARGS__)
#define jouINOUT_SCAN(...) JOUS(__VA_ARGS__)
#define jouINOUT_PUTC(...) JOUC(__VA_ARGS__)
#define jouINOUT_GETC(...) JOUG(__VA_ARGS__)

#else
#define jouINOUT_PRINT(...) chj0.print(__VA_ARGS__)
#define jouINOUT_SCAN(...) chj0.scan(__VA_ARGS__)
#define jouINOUT_PUTC(...) chj0.putc(__VA_ARGS__)
#define jouINOUT_GETC(...) chj0.getc(__VA_ARGS__)

#endif

#endif /* JOUTEMP_H */