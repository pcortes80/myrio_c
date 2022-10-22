#----------------------------------------------------------------------------
# Macros
#----------------------------------------------------------------------------

# Compiler to use
CC := gcc

#----------------------------------------------------------------------------
# Setting of target
#----------------------------------------------------------------------------

# Source file directories
SRCDIR := ./src

# Directory of executable
BINDIR := ./bin

LDFLAGS = -ldl
EXECUTABLE = crio
OBJECTS = leds.o NiFpga.o

# Include header file directories
INC := -I ./include

all: $(OBJECTS)
	$(CC) $(SRCDIR)/leds.o include/NiFpga.o $(LDFLAGS) -o $(EXECUTABLE)

leds.o:
	$(CC) -c $(SRCDIR)/leds.c -o $(SRCDIR)/leds.o

NiFpga.o:
	$(CC) -c include/NiFpga.c -o include/NiFpga.o

clean:
	rm -f $(EXECUTABLE) include/NiFpga.o $(SRCDIR)/leds.o