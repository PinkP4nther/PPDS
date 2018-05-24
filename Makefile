COMP=gcc

PPDS: PPDS.o
	$(COMP) -o PPDS PPDS.o

clean:
	rm -rf *.o PPDS
