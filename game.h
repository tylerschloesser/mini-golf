#ifndef GAME_H
#define GAME_H

#include "course.h"

class Game {
public:
    Course& course;

    Game(Course& course);
};

#endif // GAME_H
