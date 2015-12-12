#ifndef PHYSICS_H
#define PHYSICS_H

#include "course.h"
#include "ball.h"

class Physics {

private:
    Course& course;
    Ball& ball;
public:
    Physics(Course& course, Ball& ball) :
        course(course), ball(ball) {}
};

#endif // PHYSICS_H
