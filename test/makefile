# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := test

# Dependencies
LIBS      := spi

# Definitions / Un-definitions
DEFS      := __PROJ_NAME=\"$(PROJ_NAME)\" DEBUG
UNDEFS    := UNICODE

# Commands
GCC_PREFIX:= i686-w64-mingw32-
AR        := $(GCC_PREFIX)ar
AS        := nasm
CC        := $(GCC_PREFIX)gcc
CPP       := $(GCC_PREFIX)g++
LD        := $(GCC_PREFIX)g++
RES       := $(GCC_PREFIX)windres
STRIP     := $(GCC_PREFIX)strip

SRCDIR    := .
INCDIR    := ../inc
OUTDIR    := ../bin
OBJDIR    := ../obj
LIBDIR    := ../lib

# Files
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.exe)
SRC       := $(wildcard $(SRCDIR)/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)

CPPFLAGS  := -c -Wall -fPIC \
             $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
LDFLAGS   := $(LIBDIR:%=-L%) $(LIBS:%=-l%) -static-libgcc -static-libstdc++

$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(LD) $^ $(LDFLAGS) -o $(OUTPUT)

all: $(OUTPUT)
	$(STRIP) -s $(OUTPUT)

.PHONY : clean
clean :
	rm -f $(OBJ) $(wildcard $(OUTDIR)/*.*)
