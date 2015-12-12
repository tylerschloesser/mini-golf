#ifndef PHYSICS_H
#define PHYSICS_H

class Physics {

private:
    Course& course;
    Ball& ball;
public:
    Physics(Course& course, Ball& ball) :
        course(course), ball(ball) {}
};

#endif // PHYSICS_H
