#ifndef GAME_H
#define GAME_H
// INLCUDE ALL GAME QUALITIES HERE
#include <deque>
// #include <time.h>

#include<vector>
#include "Player.h"
#include "Enemies.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Game{

public:
    Player* plyr;
    std::deque<Enemies*> enemies;
    GLuint background_id;
    Game();
    Game(bool);

    void setBackDisp(const char*);
	void displayBackground();
    void idle();
    void draw();
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);
    ~Game();
private:
};

#endif