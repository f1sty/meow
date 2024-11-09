.PHONY = all clean

all: meow

meow: src/meow.c
	$(CC) -Wall -Wextra -pedantic -ggdb -o $@ $<
clean:
	rm -f meow{,.o}
