CC = gcc-7
FLAGS = -std=c11 -g -o 
SOURCE = square.c row.c board.c main.c ai.c statenode.c statelist.c
OBJ = tictactoe
DEPS = main.c square.h row.h board.h ai.h statenode.h statelist.h
tictactoe: $(DEPS); $(CC) $(SOURCE) $(FLAGS) $(OBJ);

clean: ;\rm -rf *.o *.out tictactoe
    
