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
    // plyr = new Player("images/chugga.jpg", -0.125, -0.81, 0.05, 0.25);
    plyr = new Player("images/player2.jpg");
    // enemies.push_back(new Enemies(" ", -0.6, 0.75));
    for(int i = 1; i < 3; i++){ //Row of enemies
        for(int j = 0;j<4;j++){
            // enemies.push_back(new Enemies(" ", j*-0.35+0.4, (1-(i*0.2))));
            if(i%2 == 1){
                enemies.push_back(new Enemies(" ", j*-0.35+0.4, (1-(i*0.2))));
            }
            else  {  
                enemies.push_back(new Enemies(" ", j*-0.35+0.22, (1-(i*0.33))));
                if(j == 3)
                   enemies.push_back(new Enemies(" ", (j-4)*-0.60, (1-(i*0.33)))); 
            }
        }
    }
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
void Game::idle(){
    plyr->idle();

    for(auto it = enemies.begin(); it!=enemies.end(); it++){
        (*it)->advance();
        (*it)->idle();
    }
}

void Game::draw(){
    displayBackground();
    plyr->draw();
    for(auto it = enemies.begin(); it != enemies.end(); it++){
        (*it)->draw();
    }
}

void Game::keyDown(unsigned char key, float x, float y){
    plyr->keyDown(key,x,y);
    cout<<"key down"<<endl;

}
void Game::keyUp(unsigned char key, float x, float y){
    plyr->keyUp(key,x,y);
    cout<<"key up"<<endl;
}

Game::~Game(){}