#include "Player.h"
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
using namespace std;

void Player::draw(){
    
    glBindTexture( GL_TEXTURE_2D, player_id );
    glEnable(GL_TEXTURE_2D);


    glColor3f(red, green, blue);
	
	glBegin(GL_QUADS);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
    glDisable(GL_TEXTURE_2D);
}
Player::Player(const char* ppic) : Rect::Rect(-.125,-.6, .17,.17,0.6,0.1,1), dx(0), dy(0), speed(.004){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    player_id = SOIL_load_OGL_texture (
    	ppic,
    	SOIL_LOAD_AUTO,
    	SOIL_CREATE_NEW_ID,
     	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void Player::idle(){ // Prevents out of bounds on screen
    x += dx;
    y += dy;

    if(x < -1){
        x = -1;
    }
    if(x + w > 1){
        x = 1- w;
    }
    if(y > 1){
        y = 1;
    }
    if(y - h < -1){
        y = -1 + h;
    }
}
void Player::keyDown(unsigned char key, float x, float y) { // Gets player to move
    if(key == 'w'){
        dy += speed;
        cout<< dy << endl;

    }else if(key == 'a'){
        dx += -speed;

    }else if(key == 'd'){
        dx += speed;

    }else if(key == 's'){
        dy += -speed;
    }
}

void Player::keyUp(unsigned char key, float x, float y) { // Gets player to stop if key is released
    if(key == 'w'){
        dy += -speed;
    }

    if(key == 's'){
        dy += speed;
    }

    if(key == 'a'){
        dx += speed;
    }

    if(key == 'd'){
        dx += -speed;
    }
}

float Player::getSpeed() const{ // getter for speed
    return speed;
}

