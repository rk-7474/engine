#OBJS = main.cpp $(shell find ./src -name '*.cpp')

# OBJS:=$(pathsubst %.cpp,%.o,$(shell find . -name '*.cpp'))

OBJS:= $(addprefix ../build/, $(patsubst %.cpp,%.o, $(notdir $(wildcard *.cpp))))

CC = g++

COMPILER_FLAGS = -Wall -std=c++20 -I .

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJ_NAME = executable

all: 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ../$(OBJ_NAME)


%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c ./src/$< -o ../build/$@



#all:
#	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f *.o

