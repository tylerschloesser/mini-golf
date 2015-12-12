#ifndef GAME_H
#define GAME_H

#include "course.h"

class Game {
private:
    uint32_t last_frame;
    uint32_t frame_time;

public:
    Course& course;

    Game(Course& course);

    void run();
};

#endif // GAME_H
