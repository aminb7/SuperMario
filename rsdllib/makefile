CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: test.out

test.out: main.o rsdl.o ProgramBody.o
	$(CC) main.o rsdl.o ProgramBody.o $(CCFLAGS) -o test.out

main.o: src/rsdl.hpp example/ProgramBody.hpp example/main.cpp
	$(CC) -c example/main.cpp -o main.o

ProgramBody.o: src/rsdl.hpp example/ProgramBody.hpp example/ProgramBody.cpp
	$(CC) -c example/ProgramBody.cpp -o ProgramBody.o
rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o
