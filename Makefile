SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

minishell.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o
