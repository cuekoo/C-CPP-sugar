all: foo.o
	$(CC) -o main main.c foo.o

main.o:
	$(CC) -c main.c
foo.o:
	$(CC) -c foo.c

clean:
	rm -f *.o main
