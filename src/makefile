BUILD_DIR=../build
OUTPUT_DIR=../

SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

CC=g++
COMPILER_FLAGS=-std=c++20 -c
LINKER_FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

EXEC_FILE=run

all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $(OUTPUT_DIR)$@ $(LINKER_FLAGS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $< -o $@ $(COMPILER_FLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC_FILE)

