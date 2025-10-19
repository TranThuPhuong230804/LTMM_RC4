CC      := gcc
CFLAGS  := -I../include -O2 -Wall -Wextra
SRC     := src/rc4.c main.c
BIN     := rc4_encrypt

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean
