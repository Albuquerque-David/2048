default: build

build:
	@$(CC) src/*.c $(C_FLAGS) -o $(TARGET) && echo -e "If you encounter interface messes, use the flag --no-unicode while running"

run: build
	@./$(TARGET)

clean:
	@[ -f $(TARGET) ] && rm $(TARGET) || exit

build_objects:
	@$(CC) src/*.c $(C_FLAGS) -c 

clean_objects: build_objects
	@rm *.o || exit

TARGET=2048

CC=gcc

C_FLAGS=-lncurses  \
	-O2	   \
        -Wall      \
        -ansi      \
        -pedantic  \
	-Wno-unused-result
