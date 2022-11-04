AS		= $(VASM)
CC		= $(VC)
LD		= $(VLINK)

ASFLAGS		:= -quiet -Fhunk -kick1hunks -nosym -m68060 -no-opt
CFLAGS		:= -v -O2 -size -cpu=68060 -fastcall -nostdlib -c99 -k -sc -DDEBUG

TARGET		:= tf-rom
OBJECTS		:= start.o main.o kprintf.o payload.o
INCLUDE 	:= $(wildcard *.h) $(wildcard *.s)

.EXPORT_ALL_VARIABLES:

.PHONY: clean

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) $(OBJECTS:.o=.asm) *.txt

$(TARGET) : $(OBJECTS) Makefile | buildenv
	$(LD) -sc $(OBJECTS) -o $@ -M$@.txt -b amigahunk

%.o: %.c $(INCLUDE) Makefile | buildenv
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s Makefile | buildenv
	$(AS) $< -o $@ -L $<.txt $(ASFLAGS) -I $(INC_ASM)

include ../Makefile.build
