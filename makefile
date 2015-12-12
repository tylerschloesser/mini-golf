CC=g++
CFLAGS=-c -Wall -std=c++11 -g
LDFLAGS=-lSDL2 -g

SRC=main.cpp window.cpp course.cpp game.cpp renderer.cpp
OBJ=$(SRC:.cpp=.o)

EXE=mini

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ) $(EXE)
