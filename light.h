#pragma once
#include <GL/glut.h>
#include <GL/gl.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include "constants.h"

class Light
{
public:
	Light(GLenum);
	GLenum lightID;
	GLfloat lightPosition[4] = { WORLD_SIZE/2, WORLD_SIZE/2, WORLD_SIZE/4, 1.0f };
	GLfloat lightTarget[4] = { 0, 0, 0 , 0.0f};

	GLfloat color[3] = { 1.0f, 1.0f, 1.0f };

	GLfloat intensity = 0.5; // the intensity distribution of the light


	void enable();
	void disable();
	void draw();
	void setPosition(GLfloat, GLfloat, GLfloat);
	void setTarget(GLfloat, GLfloat, GLfloat);
	void setIntensity(GLfloat);

	GLfloat* getPos();
	GLfloat* getTarget();
	GLfloat getIntensity();

};