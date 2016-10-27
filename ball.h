#pragma once

#include "gwindow.h"
#include "circle.h"

const int DELTA_MAX = 5;

class Ball {
public:
    // make a new ball and add it to the screen
    Ball();

    // Gets Circle properties corresponding to Ball
    Circle getBlueCircle();

    // add the ball to the screen
    void addToScreen(GWindow & w);

    // move the ball
    void takeStep(int screenWidth, int screenHeight, Ball ball2);

    // Check for ball collisions
    bool collision(Ball ball2);

    // overload the << operator
    friend ostream& operator<<(ostream& out, Ball& ball);

private:
    Circle blueCircle;
    double dx;
    double dy;
};
