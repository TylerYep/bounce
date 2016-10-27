#include "ball.h"
#include "random.h"
#include "math.h"

Ball::Ball() {
    dx = randomReal(-DELTA_MAX, DELTA_MAX);
    dy = randomReal(-DELTA_MAX, DELTA_MAX);
}

Circle Ball::getBlueCircle() {
    return blueCircle;
}

void Ball::addToScreen(GWindow &window) {
    double x = window.getWidth() / 2;
    double y = window.getHeight() / 2;
    blueCircle.add(window, x, y);
}

bool Ball::collision(Ball ball2){
    if(fabs(getBlueCircle().getX() - ball2.getBlueCircle().getX()) < 30
            && fabs(getBlueCircle().getY() - ball2.getBlueCircle().getY()) < 30) {
        return true;
    }
    return false;
}

void Ball::takeStep(int screenWidth, int screenHeight, Ball ball2) {
    if(blueCircle.getX() < DELTA_MAX || blueCircle.getX() > screenWidth - blueCircle.getSize()
            || collision(ball2)) {
        dx *= -1;
    }
    if(blueCircle.getY() < DELTA_MAX || blueCircle.getY() > screenHeight - blueCircle.getSize()) {
        dy *= -1;
    }
    blueCircle.move(dx, dy);
}

ostream& operator<<(ostream& out, Ball& ball){
    out << ball.dx << ", " << ball.dy;
    return out;
}
