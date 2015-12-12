CC=g++
CFLAGS=-c -Wall -std=c++11 -g
LDFLAGS=-lSDL2 -lSDL2_gfx -g

SRC=main.cpp window.cpp course.cpp game.cpp renderer.cpp physics.cpp ball.cpp math.cpp
OBJ=$(SRC:.cpp=.o)

EXE=mini

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ) $(EXE)
