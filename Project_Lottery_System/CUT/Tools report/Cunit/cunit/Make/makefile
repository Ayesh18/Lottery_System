SRC = ../SRC
INC = -I../Header
BIN = ../bin
LINK = -lcunit
G = gcc
MAIN = cunit.c
T = test
test:
	$(G)  $(SRC)/$(MAIN) $(INC) -o $(BIN)/test $(LINK)
run:
	./$(BIN)/test
clean:
	rm $(BIN)/$(T)
