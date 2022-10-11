SRC = ../SRC
INC = -I../Header
BIN = ../bin
DATA= ../data
CFLAGS = -pg
LINK = -lpthread
OBJ_CL = *.o
G = gcc
V= valgrind
S= splint
M = main.o
MAIN = main.c
T = test
test: $(M)
        $(G) $(CFLAGS) $(BIN)/$(M) $(INC) -o $(BIN)/test $(LINK)
$(M):
        $(G) -c $(CFLAGS) $(SRC)/$(MAIN) $(INC) -o $(BIN)/$(M) $(LINK)
valgrind:
        $(V) $(BIN)/./test
splint:
        $(S) $(INC) $(SRC)/$(MAIN)
gcov:
        $(G) -fprofile-arcs -ftest-coverage $(INC) $(SRC)/$(MAIN) -o $(BIN)/test $(LINK)
        ./$(BIN)/test
run:
        ./$(BIN)/test
clean:
        rm $(BIN)/$(M) $(BIN)/$(T)
        rm $(DATA)/Participant $(DATA)/Plot
clean_gcov:
        rm *.gcov *.gcda *.gcno
