# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

CPP       := i686-w64-mingw32-g++
AR        := i686-w64-mingw32-ar

SRCDIR    := src
INCDIR    := inc
OUTDIR    := bin
OBJDIR    := obj

OUTPUT    := $(OUTDIR)/libspi.a
CPPSRC    := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(CPPSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# For testing purposes
TESTDIR   := test
TEST      := $(OUTDIR)/test.exe

CPPFLAGS  := -c -fno-exceptions -O0 -fno-threadsafe-statics -fabi-version=0 \
             -nostdinc++ -std=c++17 -fno-builtin -fno-ident -ffreestanding  \
             -Wall -I$(INCDIR) -fno-rtti -nostartfiles
ARFLAGS   := rcs

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(AR) $(ARFLAGS) $(OUTPUT) $(OBJ)

$(TEST): $(OUTPUT)
	make -C $(TESTDIR) all

all: $(OUTPUT) $(TEST)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT) $(TEST)
	make -C $(TESTDIR) clean