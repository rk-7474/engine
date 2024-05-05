OBJ_NAME = run

all:
	make src
	mv ./src/$(OBJ_NAME) . 

clean:
	rm -f ./build/*.o