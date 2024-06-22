// Codi.h
#ifndef CODI_H
#define CODI_H

#include <Servo.h>
#include <NewPing.h>

class Codi {
public:
    Codi();
    void begin();
    void idle();
    void test();
    void standup();
    void laydown();
    void gym();
    void wink();
    void small_stop();
    void forward();
    void backward();
    void rightturn();
    void leftturn();
    void loop();
    void stand();

private:
    Servo hip1, knee11, hip2, knee21, hip3, knee31, hip4, knee41, eye;
    NewPing sonar;
    int b, x, w, up, up2, up3, down, down2, steps, rightsteps, leftsteps, back, pos, sensor;
    int distance;

    void setupServos();
    void setupSensor();
};

#endif
