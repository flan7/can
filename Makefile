CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC = reader.c

OBJS = $(SRC:.c=.o)

all: reader

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

logger: $(OBJS)
	$(CC) -o $(@F) $(LIBS) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f reader
