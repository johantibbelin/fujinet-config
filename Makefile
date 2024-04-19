TARGET_EXEC ?= fnconfig.prg

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
LIBCMINI := /opt/libcmini

#LIB_PROJECT := -l../fujinet-rc2014/libfn_cpm -l../fujinet-rc2014/libfujinet
#LIB_PROJECT_INC := ../fujinet-rc2014/lib/include

CC=m68k-atari-mint-gcc
AS=m68k-atari-mint-as

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d) 

CFLAGS=-DBUILD_ATARI16BIT
LDFLAGS=
ASFLAGS=

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIB_PROJECT) -o $(TARGET_EXEC)
	

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# asm source
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r FNCONFIG* fnconfig* $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
