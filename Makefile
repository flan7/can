# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Source files
SOURCES = reader.c

# Executable name
EXECUTABLE = reader

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)
