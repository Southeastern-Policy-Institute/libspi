# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

CPP       := i686-w64-mingw32-g++
LD        := i686-w64-mingw32-gcc
STRIP     := i686-w64-mingw32-strip

SRCDIR    := src
INCDIR    := inc
OUTDIR    := bin
OBJDIR    := obj

OUTPUT    := $(OUTDIR)/libspi.dll
CPPSRC    := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(CPPSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# For testing purposes
TESTDIR   := test
TEST      := $(OUTDIR)/test.exe

CPPFLAGS  := -c -fno-exceptions -O0 -fno-threadsafe-statics -fabi-version=0 \
             -nostdinc++ -std=c++2a -fno-builtin -fno-ident -ffreestanding  \
             -Wall -fno-rtti -nostartfiles -DBUILDING_LIBSPI
LDFLAGS   := -shared -fno-threadsafe-statics -fabi-version=0 -nostdinc++       \
             -fno-rtti -nostartfiles -lkernel32              \
             -luser32 -Wl,--out-implib,$(OUTPUT:%.dll=%.a) -e_DllMain@12

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $(OUTPUT)
	$(STRIP) -s $(OUTPUT)

$(TEST): $(OUTPUT)
	make -C $(TESTDIR) all

all: $(OUTPUT) $(TEST)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT) $(TEST)
	make -C $(TESTDIR) clean
