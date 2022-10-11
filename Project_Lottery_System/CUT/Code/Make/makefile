SRC = ../SRC
INC = -I../Header
BIN = ../bin
DATA= ../data
CFLAGS = -c -g
LINK = -lpthread
OBJ_CL = *.o
G = gcc
M = main.o
MAIN = main.c
T = test
test: $(M)
	$(G)  $(BIN)/$(M) $(INC) -o $(BIN)/test $(LINK)
$(M):
	$(G) $(CFLAGS) $(SRC)/$(MAIN) $(INC) -o $(BIN)/$(M) $(LINK)
run:
	./$(BIN)/test
clean:
	rm $(BIN)/$(M) $(BIN)/$(T)
	rm $(DATA)/Participant $(DATA)/Plot