CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lcurl

# Source files
SRC = test.c fetch.c
# Header files
HEADERS = common.h fetch.h
# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: test

test: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test $(OBJ)

# Phony targets to avoid conflicts with file names
.PHONY: all clean

