#pragma once

#include <GL/glut.h>
#include <GL/gl.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

#include "Env.h"
#include "Cow.h"
#include "light.h"
#include "Objects.h"

//Class
class World
{

public:
	static World* scene;
	Env* env;
	Cow* cow;
	Light* light;
	Objects* objects;
	int menu;
	World(int, char**);
	~World();
	void InitGlut(int, char**);
	void RegisterCallbacks();
	void Display();
	void Reshape(GLint, GLint);
	void MenuSetup();
	void whatToDraw();

};


