#ifndef Enemies_h
#define Enemies_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Rect.h"

class Enemies: public Rect{
    float dx, dy, speed;
    GLuint enemy_id; 
    public:
        Enemies();
        Enemies(const char*, float, float);

        void idle();
        void draw();
        void advance();

};

#endif