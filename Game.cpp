#include "Game.h"
#include "SOIL.h"
// #include "SOIL.cpp"
#include<iostream>
#include<fstream>
#include<math.h>
#include<deque>
#include<vector>
#include<ctime>
#include<stdlib.h>


using namespace std;

Game::Game(bool begin){
    setBackground("images/bg.jpg");
    // plyr = new Player("images/chugga.jpg", -0.125, -0.81, 0.05, 0.25);
    plyr = new Player("images/player2.jpg");
    // enemies.push_back(new Enemies(" ", -0.6, 0.75));
    bulletSp = 0.0035; 
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

void Game::setBackground(const char* bgPic) {
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
    // for(auto it = bullets.begin(); it!=bullets.end(); it++){
    //     
    // }
    int i=0, j=0;
    for(auto it = enemies.begin(); it!=enemies.end(); it++){
        (*it)->advance();
        (*it)->idle();
    }
    for(Rect* r : bullets){
        //move bullet up
        r->setY(r->getY() + bulletSp);
    }
    for(Enemies* e: enemies){
        if(checkCollision(*e, *plyr)){
            exit(0);
        }
        for(Rect* b: bullets){
            if(checkCollision(*b,*e)){
                cout<<"collision check"<<endl;
                enemies.erase(enemies.begin()+i);
                bullets.erase(bullets.begin()+j); 
            }
            j++;
        }
        i++;
    }
    
    if(enemies.size() < 1){
        exit(0);
    }
    
}

void Game::draw(){
    displayBackground();
    plyr->draw();
    for(auto it = bullets.begin(); it!=bullets.end(); it++){
        (*it)->draw(); 
    }
    for(auto it = enemies.begin(); it != enemies.end(); it++){
        (*it)->draw();
    }
}

void Game::keyDown(unsigned char key, float x, float y){
    plyr->keyDown(key,x,y);
    cout<<"key down"<<endl;
    if (key == 32){
        fire();
    }

}
void Game::keyUp(unsigned char key, float x, float y){
    plyr->keyUp(key,x,y);
    cout<<"key up"<<endl;
}

void Game::fire(){
    bullets.push_back(new Rect(plyr->getX() + plyr->getW()/2 - .03, plyr->getY(), .05,.1,0.5,0.5,0.5));
}

bool Game::checkCollision(const Rect& one, const Rect& two) const{ // returns bool if player/enemy or bullet/enemy collide
    return  (one.getX() < (two.getX() + two.getW()) && two.getX() < (one.getX() + one.getW())) && (one.getY() > (two.getY() - two.getH()) && two.getY() > (one.getY() - one.getH()));
}


Game::~Game(){
    delete plyr;

}