.PHONY = all clean

all: meow

meow: src/meow.c
	$(CC) -o $@ $<
clean:
	rm -f meow{,.o}
