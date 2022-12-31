
.PHONY: all clean

CC = g++

SRCDIR = ./src/
IDIR = ./src/deps/include/
LDIR = ./src/deps/lib/

SRCS := $(wildcard $(SRCDIR)/*.cpp)
BINS := $(SRCS:$(SRCDIR)%.cpp=./%)

IFLAGS := -I $(IDIR)
LFLAGS := -lSDL2

ifdef OS
	LDIR := $(LDIR)Windows
	LFLAGS += -L $(LDIR) -lmingw32 -lSDL2Main
#else
#	ifeq ($(shell uname), Linux)
#		LDIR := $(LDIR)Linux
#	endif
endif

all: $(BINS)

$(BINS): $(SRCDIR)$(BINS).o
	@echo "COMPILING OBJECT FILES"
	$(CC) $< -o $@ $(IFLAGS) $(LFLAGS)

%.o: %.cpp
	@echo "CREATING OBJECT $<.o"
	$(CC) -c $< -o $@

clean:
	rm -rvf ./src/*.o $(BINS)
