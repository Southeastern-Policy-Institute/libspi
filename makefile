# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := libspi

# Definitions / Un-definitions
DEFS      := __PROJ_NAME=\"$(PROJ_NAME)\" DEBUG
UNDEFS    := UNICODE

# Commands
GCC_PREFIX:= i686-w64-mingw32-
AR        := $(GCC_PREFIX)ar
AS        := nasm
CC        := $(GCC_PREFIX)gcc
CPP       := $(GCC_PREFIX)g++
LD        := $(GCC_PREFIX)ld
RES       := $(GCC_PREFIX)windres
STRIP     := $(GCC_PREFIX)strip

# Directories
SRCDIR    := src
INCDIR    := inc
OUTDIR    := lib
OBJDIR    := obj
RESDIR    := res

# Files
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.a)
SRC       := $(wildcard $(SRCDIR)/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)

# Flags
ASFLAGS   := -f elf
CPPFLAGS  := -c -Wall -fPIC \
             $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
CFLAGS    := $(CPPFLAGS)

# Rules
$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OBJDIR)/%.c.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR)/%.asm.o : $(SRCDIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(AR) rcs $@ $^

$(OUTDIR)/test : $(OUTPUT)
	cd test && $(MAKE) all

.PHONY : all
all : $(OUTDIR)/test

.PHONY : clean
clean :
	clear
	rm -f $(wildcard $(OBJDIR)/*.*) $(wildcard $(OUTDIR)/*.*)
