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
#include "constants.h"

using namespace std;

#define HEAD 0
#define BODY 1
#define FRONT_LEFT_LEG 2
#define FRONT_RIGHT_LEG 3
#define BACK_LEFT_LEG 4
#define BACK_RIGHT_LEG 5
#define EARS 6
#define TAIL 7
#define EYES 8
#define NOSE 9

#define head_size 6
#define body_size 15
#define leg_size 15
#define ear_size 0.6
#define tail_size 6
#define eye_size 0.4
#define nose_size 0.4

#define cow_movement 5

#define PI 3.14159265358979323846

class Cow
{
public:
	Cow();

	GLfloat* getPosition(int);
	GLfloat* getDirection();

	// relative posistions
	GLfloat bodyPos[10][3] =
	{// HEAD
	{ (body_size / 2), 0.0f, (body_size/4)},
	// BODY - central reference
	{ 0.0f, 0.0f, 0.0f },
	// FRONT_LEFT_LEG
	{ (body_size / 2) - (leg_size / 10), (body_size / 4) - (leg_size / 10), -(body_size / 4) },
	// FRONT_RIGHT_LEG
	{ (body_size / 2) - (leg_size / 10), -(body_size / 4) + (leg_size / 10), -(body_size / 4) },
	// BACK_LEFT_LEG
	{ -(body_size / 2) + (leg_size / 10), (body_size / 4) - (leg_size / 10), -(body_size / 4) },
	// BACK_RIGHT_LEG
	{ -(body_size / 2) + (leg_size / 10),-(body_size / 4) + (leg_size / 10), -(body_size / 4) },
	// EARS - will use one position as a base and adjust in the drawing function
	{ (body_size / 2), 0.0f, (head_size / 2) + (body_size / 2) - (ear_size/2) - 1.5},
	// TAIL
	{ -(body_size / 2), 0.0f, 3.75f },
	// EYES - will use one position as a base and adjust in the drawing function
	{ (body_size / 2) + (head_size / 2) + eye_size*4, 0.0f, (body_size / 4) + eye_size*4},
	// NOSE
	{ (body_size / 2) + (head_size / 2) + nose_size*7, 0.0f, (body_size / 4) - eye_size*2 }};

	//Angles and directions of the body parts
	GLfloat body_angle = 0, head_angle = 0, tail_angle = 0;
	GLfloat body_direction_vector[3] = { 1, 0, 0 };//, head_direction_vector[3] = { 0, 10, 0 }, tail_direction_vector[3] = { 0, 10, 0 };

	//Movements
	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackwards();
	void headLeft();
	void headRight();
	void headUp();
	void headDown();
	void tailLeft();
	void tailRight();
	void tailUp();
	void tailDown();

	//Draw
	void generateCow();
	float calcBodyAngle();
	void rotate(int, GLfloat);
	void draw();
	void head();
	void body();
	void legs();
	void ears();
	void tail();
	void eyes();
	void nose();

};
