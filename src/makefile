OBJS:=$(patsubst %.cpp, %.o, $(notdir $(wildcard *.cpp)))

CC=g++

COMPILER_FLAGS=-std=c++20 -c

LINKER_FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

EXEC_FILE=run

%.o: %.cpp
	$(CC) $^ -o $@ $(COMPILER_FLAGS)

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $@ $(LINKER_FLAGS)

all:
	$(EXEC_FILE)