# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

CPP       := i686-w64-mingw32-g++
LD        := i686-w64-mingw32-gcc
STRIP     := i686-w64-mingw32-strip

SRCDIR    := .
INCDIR    := ../inc
OUTDIR    := ../bin
OBJDIR    := ../obj
LIBDIR    := ../bin

OUTPUT    := $(OUTDIR)/test.exe
CPPSRC    := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(CPPSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CPPFLAGS  := -c -fno-exceptions -Wall -O0 -std=c++17 -fno-builtin -fno-ident \
             -ffreestanding -I$(INCDIR)
LDFLAGS   := -fno-threadsafe-statics -fabi-version=0 -nostdinc++ -Wall       \
             -fno-rtti -nostartfiles -mwindows -L$(LIBDIR) -lspi -lkernel32  \
             -luser32

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $(OUTPUT)

all: $(OUTPUT)
	$(STRIP) -s $(OUTPUT)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT)
