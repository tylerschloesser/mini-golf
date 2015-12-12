CC=g++
CFLAGS=-c -Wall
LDFLAGS=

SRC=main.cpp window.cpp
OBJ=$(SRC:.cpp=.o)

EXE=mini

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ) $(EXE)
