.POSIX:

TARGET := blink
BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include
LDFILE := link.ld

VERBOSE := 0

# -----------------------------------------------------------------------------

CROSS_COMPILE := arm-none-eabi
AS := $(CROSS_COMPILE)-as
AR := $(CROSS_COMPILE)-ar
CC := $(CROSS_COMPILE)-gcc
LD := $(CROSS_COMPILE)-ld
OBJCOPY := $(CROSS_COMPILE)-objcopy
OBJDUMP := $(CROSS_COMPILE)-objdump
SIZE := $(CROSS_COMPILE)-size
GDB := $(CROSS_COMPILE)-gdb


COMMON_FLAGS += -mcpu=cortex-m0plus -march=armv6-m -mthumb
ASFLAGS := $(COMMON_FLAGS) --warn --fatal-warnings
CFLAGS := -I$(INCLUDE_DIR) -std=c17 $(COMMON_FLAGS)
CFLAGS += -Os -Wall -Wpedantic -Wextra -Wswitch-enum
CFLAGS += -ffreestanding -fdata-sections -ffunction-sections
LDFLAGS := -nostdlib -nostartfiles -static
LDFLAGS += -Wl,--build-id=none,--gc-sections
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,-T$(LDFILE)

S_SRCS := $(wildcard $(SRC_DIR)/*.s)
S_OBJS += $(subst $(SRC_DIR)/,$(BUILD_DIR)/,$(S_SRCS:.s=.o))

C_SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c \
		  	$(SRC_DIR)/*/*/*/*.c $(SRC_DIR)/*/*/*/*/*.c)
C_OBJS := $(subst $(SRC_DIR)/,$(BUILD_DIR)/,$(C_SRCS:.c=.o))

# Prettify output
PRINTF := @printf "%-8s %s\n"
ifeq ($(VERBOSE), 0)
	Q := @
endif

# -----------------------------------------------------------------------------

all: $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s
	$Qmkdir -p $(@D)
	$(PRINTF) "AS" $@
	$Q$(COMPILE.s) -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$Qmkdir -p $(@D)
	$(PRINTF) "CC" $@
	$Q$(COMPILE.c) -o $@ $<

$(BUILD_DIR)/$(TARGET).elf: $(C_OBJS) $(S_OBJS)
	$(PRINTF) "LD" $@
	$Q$(LINK.o) $^ $(LDLIBS) -o $@
	$(PRINTF) "OBJDUMP" $(BUILD_DIR)/$(TARGET).lst
	$Q$(OBJDUMP) -St $@ >$(BUILD_DIR)/$(TARGET).lst
	$(PRINTF) "SIZE" $@
	$Q$(SIZE) $@

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(PRINTF) "OBJCOPY" $@
	$Q$(OBJCOPY) -O binary $< $@

clean:
	$(PRINTF) "CLEAN" $(BUILD_DIR)
	$Q$(RM) -r $(BUILD_DIR)

.PHONY: all clean
