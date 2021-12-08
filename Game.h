#ifndef GAME_H
#define GAME_H
// INLCUDE ALL GAME QUALITIES HERE
#include <deque>

#include<vector>
#include "Player.h"
#include "Enemies.h"
#include "Rect.h"

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
    std::vector<Enemies*> enemies;
    std::deque<Rect*> bullets;
    GLuint background_id;
    Game();
    Game(bool);
    float bulletSp;

    void setBackground(const char*);
	void displayBackground();
    void idle();
    void draw();
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);
    void fire();
    bool checkCollision(const Rect&, const Rect&) const; 
    ~Game();
private:
};

#endif