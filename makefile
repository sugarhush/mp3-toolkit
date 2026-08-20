CC: gcc

all:
	$(CC) src/*.c
run:
	./a.out
clean:
	rm -rf a.out
