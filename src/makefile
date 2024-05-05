OBJS:=$(patsubst %.cpp, %.o, $(notdir $(wildcard *.cpp)))

CC=g++

COMPILER_FLAGS=-std=c++20 -I .

LINKER_FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

OBJ_NAME=run

%.o:
	$(CC) $(COMPILER_FLAGS) -c $(patsubst %.o,%.cpp,$@) -o $@

$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

all:
	mv ../build/*.o .
	make $(OBJ_NAME)
	mv *.o ../build/
	
clean:
	rm -f *.o

