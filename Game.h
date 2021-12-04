#ifndef GAME_H
#define GAME_H
// INLCUDE ALL GAME QUALITIES HERE
#include <deque>
#include <time.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Game{

public:
    GLuint background_id;
    Game();
    Game(bool);

    void setBackDisp(const char*);
	void displayBackground();
    void draw();
    void keyDown(unsigned char key, float x, float y);

    ~Game();
private:
};

#endif