CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lSDL2

SRC=main.cpp window.cpp course.cpp
OBJ=$(SRC:.cpp=.o)

EXE=mini

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ) $(EXE)
