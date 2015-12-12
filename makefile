CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDL2

SRC=main.cpp window.cpp
OBJ=$(SRC:.cpp=.o)

EXE=mini

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ) $(EXE)
