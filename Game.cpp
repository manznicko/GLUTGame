#include "Game.h"
#include "SOIL.h"
// #include "SOIL.cpp"
#include<iostream>
#include<fstream>
#include<math.h>
#include<deque>
#include<ctime>
#include<stdlib.h>


using namespace std;

Game::Game(bool begin){
    setBackDisp("images/bg.jpg");
}

void Game::setBackDisp(const char* bgPic) {
	//Sets background image
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    background_id = SOIL_load_OGL_texture (
    	bgPic,
    	SOIL_LOAD_AUTO,
    	SOIL_CREATE_NEW_ID,
     	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void Game::displayBackground() {
	//Displays background image
	glBindTexture( GL_TEXTURE_2D, background_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(-1.0, -1.0);
    
    glTexCoord2f(0, 1);
    glVertex2f(-1.0, 1.0);
    
    glTexCoord2f(1, 1);
    glVertex2f(1.0, 1.0);
    
    glTexCoord2f(1, 0);
    glVertex2f(1.0, -1.0);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

void Game::draw(){
    displayBackground();
}

void Game::keyDown(unsigned char key, float x, float y){


}
Game::~Game(){}