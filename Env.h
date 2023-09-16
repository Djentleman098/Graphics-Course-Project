#pragma once
#include <GL/glut.h>
#include <GL/gl.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include "constants.h"

using namespace std;

class Env
{
private:
	GLuint topTex;
	GLuint frontTex;
	GLuint backTex;
	GLuint leftTex;
	GLuint rightTex;
	GLuint groundTex;

	GLfloat position[3] = {0.0f, 0.0f,0.0f}; // the position of the env coordinate
public:
	Env();
	void draw();
	void generateEnv();
	GLfloat* getPosition();
	
	float worldSize = WORLD_SIZE;
};

