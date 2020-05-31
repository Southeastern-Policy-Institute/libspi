# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

CPP       := i686-pc-cygwin-g++
AR        := i686-pc-cygwin-ar

SRCDIR    := src
INCDIR    := inc
OUTDIR    := bin
OBJDIR    := obj

OUTPUT    := $(OUTDIR)/libspi.a
CPPSRC    := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(CPPSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CPPFLAGS  := -c -fno-exceptions -O0 -fno-threadsafe-statics -fabi-version=0 \
             -nostdinc++ -std=c++17 -fno-builtin -fno-ident -ffreestanding  \
             -Wall -I$(INCDIR) -fno-rtti -nostartfiles
ARFLAGS   := rcs

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

all: $(OBJ)
	$(AR) $(ARFLAGS) $(OUTPUT) $(OBJ)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT)