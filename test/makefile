# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

CPP       := i686-w64-mingw32-g++
LD        := i686-w64-mingw32-gcc

SRCDIR    := .
INCDIR    := ../inc
OUTDIR    := ../bin
OBJDIR    := ../obj
LIBDIR    := ../bin

OUTPUT    := $(OUTDIR)/test.exe
CPPSRC    := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(CPPSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CPPFLAGS  := -fno-threadsafe-statics -fabi-version=0    \
             -nostdinc++   \
             -Wall -I$(INCDIR) -fno-rtti -nostartfiles
LDFLAGS   := -mwindows -L$(LIBDIR) -lspi -lkernel32 -luser32

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) -c -fno-exceptions -Wall -O0 -std=c++17 -fno-builtin -fno-ident -ffreestanding -o $@ $<

all: $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) $(CPPFLAGS) -o $(OUTPUT)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT)