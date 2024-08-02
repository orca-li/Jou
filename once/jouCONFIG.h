/**
 * @copyright MIT License, 2024 (c) Orcali
 * @version 0.2.2
 */
#if !defined(JOUCONFIG_H)
#define JOUCONFIG_H

#define JOU_DEVELOPER
#if !defined(JOU_DEVELOPER)
/* USER CODE BEGIN ---------------------------------- */

/* USER CODE END ------------------------------------ */

#else
/* JOULIB DEVELOPER CODE BEGIN ---------------------- */
/* Lite Version Configuration */
#define jconfigLITE_VERSION         SET_FLAG(1)

/* API Configuration */
#define jconfigAPI_ADDONS_TAG       SET_FLAG(1)
#define jconfigAPI_ADDONS_HOOK      SET_FLAG(1)
#define jconfigAPI_ADDONS_CMP       SET_FLAG(1)
#define jconfigAPI_DUMP_HEX         SET_FLAG(1)
#define jconfigAPI_DUMP_BIN         SET_FLAG(1)

/* Using templates Configuration */
#define jconfigTEMP_TARGET         SET_VALUE_HEX(0x0001) /* view the MANUAL */

/* Preprocessor directive Configuration */
#define jconfigSYNONYM_chj0        SET_FLAG(1)

/* Colors Configuration */
#define jconfigCOLORS               SET_FLAG(1)

/* Dump Configuration */
#define jconfigBIN_SEPARATOR        SET_FLAG(1)
#define jconfigADDRESS_COLUMN       SET_FLAG(0)
#define jconfigPROCESSOR_CAPACITY   SET_VALUE(16)
#define jconfigHEX_BYTES_IN_LINE    SET_VALUE(16)
#define jconfigBIN_BYTES_IN_LINE    SET_VALUE(8)

/* Memory management Configuration */
#define jconfigGENERAL_SIZE         SET_VALUE(512)
#define jconfigPRINTJ_BUF_SIZE      SET_VALUE(jconfigGENERAL_SIZE)
#define jconfigSCANJ_BUF_SIZE       SET_VALUE(jconfigGENERAL_SIZE)
#define jconfigMRGTMP_BUF_SIZE      SET_VALUE(64)

/* Addons Configuration */
#define jconfigHOOK_LENGTH          SET_VALUE(24)

/* JOULIB DEVELOPER CODE END ------------------------ */
#endif

#define CLIP(_clip) _clip
#define SET_FLAG(_flag) _flag
#define SET_VALUE(_value) _value
#define SET_VALUE_HEX(_hex_value) _hex_value

#if !defined(jconfigPROCESSOR_CAPACITY)
#define jconfigPROCESSOR_CAPACITY SET_VALUE(16)
#endif
#define jconfigDUMP_BYTES_PER_SPACE (jconfigPROCESSOR_CAPACITY / 8)

#define jconfigDUMP_DIRECTION_TOP   SET_FLAG(1)
#if jconfigADDRESS_COLUMN == 1
#define jconfigDUMP_DIRECTION_TOP SET_FLAG(0)
#endif

#if jconfigSYNONYM_chj0 == 1
#define jou chj0
#endif

#define jCASE_TYPEDUMP_HEX 'H'
#define jCASE_TYPEDUMP_BIN 'B'
#define jCASE_TYPEDUMP_ASCII 'A'

#endif /* JOUCONFIG_H */