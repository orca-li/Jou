/**
 * @copyright MIT License (C) 2024 Orcali
 * @version v0.1.1
 */
#if !defined(JOUCONFIG_H)
#define JOUCONFIG_H

#define JOU_DEVELOPER
#if !defined(JOU_DEVELOPER)
/* USER CODE BEGIN ---------------------------------- */

/* USER CODE END ------------------------------------ */

#else
/* JOULIB DEVELOPER CODE BEGIN ---------------------- */
/* Using templates Configuration */
#define JCONFIG_TEMP_TARGET         SET_VALUE(1) /* view the MANUAL */

/* Preprocessor directive Configuration */
#define JCONFIG_SYNONYM_chj0        SET_FLAG(1)

/* Colors Configuration */
#define JCONFIG_COLORS              SET_FLAG(1)

/* HexDump Configuration */
#define JCONFIG_ADDRESS_COLUMN      SET_FLAG(0)
#define JCONFIG_DUMP_DIRECTION_TOP  SET_FLAG(1)

/* Memory management Configuration */
#define JCONFIG_GENERAL_SIZE        SET_VALUE(512)
#define JCONFIG_PRINTJ_BUF_SIZE     SET_VALUE(JCONFIG_GENERAL_SIZE)
#define JCONFIG_SCANJ_BUF_SIZE      SET_VALUE(JCONFIG_GENERAL_SIZE)
#define JCONFIG_MRGTMP_BUF_SIZE     SET_VALUE(64)

/* JOULIB DEVELOPER CODE END ------------------------ */
#endif

#define CLIP(_clip) _clip
#define SET_FLAG(_flag) _flag
#define SET_VALUE(_value) _value

#if !defined(JCONFIG_PROCESSOR_CAPACITY)
#define JCONFIG_PROCESSOR_CAPACITY SET_VALUE(16)
#endif
#define JCONFIG_HEXDUMP_BYTES_PER_SPACE (JCONFIG_PROCESSOR_CAPACITY / 8)

#if JCONFIG_WIDE_DUMP == 1
#define JCONFIG_HEXDUMP_BYTES_IN_LINE 32
#else
#define JCONFIG_HEXDUMP_BYTES_IN_LINE 16
#endif

#if JCONFIG_ADDRESS_COLUMN == 0
#define JCONFIG_DUMP_DIRECTION_TOP SET_FLAG(1)
#endif

#if JCONFIG_SYNONYM_chj0 == 1
#define jou chj0
#endif

#endif /* JOUCONFIG_H */