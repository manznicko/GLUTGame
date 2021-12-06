#include "Enemies.h"
#include <iostream>
#include "SOIL.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Enemies::Enemies(const char* epic, float a, float b) : Rect::Rect(a,b, .15,.15,1,1,1), speed(-0.00029){ // -0.6, 0.75
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    enemy_id = SOIL_load_OGL_texture (
    	epic,
    	SOIL_LOAD_AUTO,
    	SOIL_CREATE_NEW_ID,
     	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
void Enemies::draw(){
    glBindTexture( GL_TEXTURE_2D, enemy_id );
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

void Enemies::idle(){
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

void Enemies::advance(){
    dy = speed;
}