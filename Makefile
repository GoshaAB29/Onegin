CC=g++

CFLAGS=-c

all: program

program: main.o onegin.o
	$(CC) main.o onegin.o -o program

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

onegin.o:
	$(CC) $(CFLAGS) C:\Projects\Onegin\source\onegin.cpp

clean:
	rm -f $(OBJECTS) main.o 
	rm -f $(OBJECTS) onegin.o