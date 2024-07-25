# --- PROJECT CONFIGURATION CODE BEGIN ----------------------
PROJECTNAME := jou

BUILD_DIR := .build
OBJDIR := ${BUILD_DIR}/objects
DBGDIR := ${BUILD_DIR}/debug
BINDIR := ${BUILD_DIR}/binary
# --- PROJECT CONFIGURATION CODE END ------------------------

# --- TOOLCHAIN VARIABLES CODE BEGIN ------------------------
## compiler tools
PREFIXCC :=
CC := $(PREFIXCC)gcc
OCOPY := $(PREFIXCC)objcopy
ODUMP := $(PREFIXCC)objdump
CSIZE := $(PREFIXCC)size

## flags
### flags for CC
# CFLAGS = -O0
# CFLAGS = -ggdb
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
# --- TOOLCHAIN VARIABLES CODE END --------------------------

# --- PATHS AND SYMBOLS CODE BEGIN --------------------------

INCLUDES := -I"../jou"

SOURCES += ${wildcard *.c}

# --- PATHS AND SYMBOLS CODE END ----------------------------

BIN_PATH := $(BINDIR)/$(PROJECTNAME).exe
SHORTBIN_PATH := $(BIN_PATH) $(basename $(BIN_PATH))
SHORTDBG_PATH := $(DBGDIR)/$(notdir $(basename $(BIN_PATH)))

all: mkdir getobj getbin getsymb
	$(CSIZE) $(BIN_PATH)

getobj:
	$(foreach source, $(SOURCES), \
		$(CC) $(INCLUDES) $(CFLAGS) -c -MD $(source) -o $(OBJDIR)/$(subst .c,.o,$(notdir $(source))); \
	)

getbin:
	$(CC) $(CFLAGS) $(OBJDIR)/*.o -o $(BIN_PATH)
	$(OCOPY) -O binary $(SHORTBIN_PATH).bin
	$(OCOPY) -O ihex $(SHORTBIN_PATH).hex

getsymb:
	$(ODUMP) -h -S $(BIN_PATH) > $(SHORTDBG_PATH).list

mkdir:
	@mkdir -p ${OBJDIR}
	@mkdir -p ${BINDIR}
	@mkdir -p ${DBGDIR}

run:
	./$(SHORTBIN_PATH)

clean:
	@rm -rf ${BUILD_DIR}