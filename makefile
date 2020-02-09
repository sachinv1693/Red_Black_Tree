OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
rbt.exe : $(OBJ)
	gcc -Wall -o $@ $^
clean:
	rm *.o *.exe
