.PHONY = all clean

all: meow

meow: meow.c
	$(CC) -o $@ $<
clean:
	rm -f meow{,.o}
