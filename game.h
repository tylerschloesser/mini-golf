#ifndef GAME_H
#define GAME_H

#include "course.h"

class Game {
private:
    uint32_t last_frame;

public:
    Course& course;

    Game(Course& course);

    void run();
};

#endif // GAME_H
