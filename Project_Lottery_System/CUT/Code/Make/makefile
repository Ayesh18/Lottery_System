SRC = ../SRC
INC = -I../Header
BIN = ../bin
DATA = ../data
CFLAGS = -pg -fprofile-arcs -ftest-coverage
LINK = -lpthread
OBJ_CL = *.o
G = gcc
GP = gprof
GC = gcov
V = valgrind
S = splint
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

gprof:
        $(GP) -b ./$(BIN)/test gmon.out

gcov:
        $(GC) $(BIN)/main

gcovshow:
        cat main.c.gcov

run:
        ./$(BIN)/test

clean:
        rm $(BIN)/$(M) $(BIN)/$(T)
        rm $(DATA)/Participant $(DATA)/Plot

cleanall:
        rm *.gcov $(BIN)/*.gcda $(BIN)/*.gcno *.out

