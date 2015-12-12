#include <cstdio>

#include "game.h"

Game::Game(Course& course) : course(course) {
    fprintf(stderr, "Game initialized");
}
