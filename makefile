CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: mario.out

mario.out: main.o Camera.o ProgramBody.o Map.o Mario.o Block.o QuestionBrick.o Pipe.o RedMushroom.o HealthMushroom.o Coin.o Flag.o Goomba.o Koopa.o rsdl.o
	$(CC) main.o ProgramBody.o Camera.o Map.o Mario.o Block.o QuestionBrick.o Pipe.o RedMushroom.o HealthMushroom.o Coin.o Flag.o Goomba.o Koopa.o rsdl.o $(CCFLAGS) -o mario.out

main.o: source/ProgramBody.hpp rsdllib/rsdl.hpp source/Map.hpp source/Camera.hpp source/Mario.hpp source/Block.hpp source/QuestionBrick.hpp source/Pipe.hpp source/Coin.hpp source/Flag.hpp source/Goomba.hpp source/Koopa.hpp source/RedMushroom.hpp source/HealthMushroom.hpp source/main.cpp
	$(CC) -c source/main.cpp -o main.o

ProgramBody.o: source/ProgramBody.hpp rsdllib/rsdl.hpp source/Map.hpp source/Camera.hpp source/Mario.hpp source/Block.hpp source/QuestionBrick.hpp source/Pipe.hpp source/Coin.hpp source/Flag.hpp source/Goomba.hpp source/Koopa.hpp source/RedMushroom.hpp source/HealthMushroom.hpp source/ProgramBody.cpp
	$(CC) -c source/ProgramBody.cpp -o ProgramBody.o

Camera.o: source/Camera.hpp rsdllib/rsdl.hpp source/Map.hpp source/Mario.hpp source/Block.hpp source/Pipe.hpp source/QuestionBrick.hpp source/Coin.hpp source/Flag.hpp source/Goomba.hpp source/Koopa.hpp source/RedMushroom.hpp source/HealthMushroom.hpp source/Camera.cpp
	$(CC) -c source/Camera.cpp -o Camera.o

Map.o: source/Map.hpp rsdllib/rsdl.hpp source/Mario.hpp source/Block.hpp source/Pipe.hpp source/QuestionBrick.hpp source/Coin.hpp source/Flag.hpp source/Goomba.hpp source/Koopa.hpp source/RedMushroom.hpp source/HealthMushroom.hpp source/Map.cpp
	$(CC) -c source/Map.cpp -o Map.o

Mario.o: source/Mario.hpp rsdllib/rsdl.hpp source/Mario.cpp
	$(CC) -c source/Mario.cpp -o Mario.o

Block.o: source/Block.hpp rsdllib/rsdl.hpp source/Block.cpp
	$(CC) -c source/Block.cpp -o Block.o

QuestionBrick.o: source/QuestionBrick.hpp rsdllib/rsdl.hpp source/QuestionBrick.cpp
	$(CC) -c source/QuestionBrick.cpp -o QuestionBrick.o

Pipe.o: source/Pipe.hpp rsdllib/rsdl.hpp source/Pipe.cpp
	$(CC) -c source/Pipe.cpp -o Pipe.o

RedMushroom.o: source/RedMushroom.hpp rsdllib/rsdl.hpp source/RedMushroom.cpp
	$(CC) -c source/RedMushroom.cpp -o RedMushroom.o

HealthMushroom.o: source/HealthMushroom.hpp rsdllib/rsdl.hpp source/HealthMushroom.cpp
	$(CC) -c source/HealthMushroom.cpp -o HealthMushroom.o

Coin.o: source/Coin.hpp rsdllib/rsdl.hpp source/Coin.cpp
	$(CC) -c source/Coin.cpp -o Coin.o

Flag.o:	source/Flag.hpp rsdllib/rsdl.hpp source/Flag.cpp
	$(CC) -c source/Flag.cpp -o Flag.o

Goomba.o: source/Goomba.hpp rsdllib/rsdl.hpp source/Goomba.cpp
	$(CC) -c source/Goomba.cpp -o Goomba.o

Koopa.o: source/Koopa.hpp rsdllib/rsdl.hpp source/Koopa.cpp
	$(CC) -c source/Koopa.cpp -o Koopa.o

rsdl.o: rsdllib/rsdl.hpp rsdllib/rsdl.cpp
	$(CC) -c rsdllib/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o
