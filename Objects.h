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

class Objects{
	public:

	Objects();

	// street lamp
	GLfloat lamp_base_size = 25;
	GLfloat street_lamp_pos[3] = { WORLD_SIZE - lamp_base_size, lamp_base_size, 0 }; // bottom right corner of the world
	// metal ball
	GLfloat ball_size = 20;
	GLfloat ball_pos[3] = { WORLD_SIZE - ball_size, WORLD_SIZE - ball_size, ball_size*3/4 }; // top right corner of the world
	// bin
	GLfloat bin_size = 30;
	GLfloat bin_pos[3] = { bin_size, WORLD_SIZE - bin_size, bin_size/2 }; // top left corner of the world


	void draw();
	void drawLamp();
	void drawBall();
	void drawBin();

};


// object 1

// object 2

// object 3 - metalic