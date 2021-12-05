// #ifndef PLAYER_H
// #define PLAYER_H

// #include "SOIL.h"
// #if defined WIN32
// #include <freeglut.h>
// #include "SOIL.h"
// #elif defined __APPLE__
// #include <GLUT/glut.h>
// #include "SOIL.h"
// #else
// #include <GL/freeglut.h>
// #include "SOIL.h"
// #endif

// class Player{
//     	float x;
//     	float y;
//     	float h;
//     	float w;
//         float dx, dy, speed;    
//     	GLuint player_id;
// public:

// 	Player(const char*, float, float, float, float);

// 	~Player();

	

// 	void draw();
// 	void keyUp(unsigned char key, float x, float y);
//     void keyDown(unsigned char key, float x, float y);
//     float getSpeed() const;

// 	void setX(int);
// 	void setY(int);
// 	void setH(int);
// 	void setW(int);

// 	float getX() const;
// 	float getY() const;
// 	float getH() const;
// 	float getW() const;
// };
// #endif

#ifndef Player_h
#define Player_h
#include "SOIL.h"
#if defined WIN32
#include <freeglut.h>
#include "SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include "SOIL.h"
#else
#include <GL/freeglut.h>
#include "SOIL.h"
#endif
#include "Rect.h"

class Player: public Rect{
    float dx, dy, speed;
    GLuint player_id; 

    public:

        Player();
        Player(const char*);

        void idle();
        void draw();
        void keyUp(unsigned char key, float x, float y);
        void keyDown(unsigned char key, float x, float y);
        float getSpeed() const;
};



#endif