#if !defined(JOUCONFIG_H)
#define JOUCONFIG_H

#define JOU_DEVELOPER
#if !defined(JOU_DEVELOPER)
/* USER CODE BEGIN ---------------------------------- */

/* USER CODE END ------------------------------------ */

#else
/* JOULIB DEVELOPER CODE BEGIN ---------------------- */
/* Colors Configuration */
#define JCONFIG_COLORS          SET_FLAG(1)

/* HexDump Configuration */
#define JCONFIG_WIDE_DUMP       SET_FLAG(0)

/* JOULIB DEVELOPER CODE END ------------------------ */
#endif

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

#endif /* JOUCONFIG_H */