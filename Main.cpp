#include "main.h"
#include "World.h"

World* scene = nullptr;

int main(int argc, char** argv)
{
	scene = new World(argc, argv);
	glutMainLoop();

	delete scene;
	scene = nullptr;

	return 0;
}



