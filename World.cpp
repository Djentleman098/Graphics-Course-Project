#include "World.h"
#include "WorldParams.h"

extern World* scene;

void displaycallback()
{
	if (scene) scene->Display();
}

void reshapecallback(GLint w, GLint h)
{
	if (scene) scene->Reshape(w, h);
}

void drawText(const char* str, int x, int y) {
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0); 
	glLoadIdentity();
	glRasterPos2i(x, y);

	for (const char* c = str; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	glPopMatrix();
}

void keyboardcallback(unsigned char key, int x, int y) {
	// Start menu
	if (menu_level == START_MENU && key == 'm') { // start -> main
		menu_level = MAIN_MENU;
		what_to_move = 1000;
	}
	// Main menu
	if (menu_level == MAIN_MENU && key == '1') { // main handle camera position
		what_to_move = MOVE_CAMERA_POS;
	}
	if (menu_level == MAIN_MENU && key == '2') { // main handle camera target
		what_to_move = MOVE_CAMERA_TARGET;
	}
	if (menu_level == MAIN_MENU && key == '3') { // main handle ambient light
		what_to_move = MOVE_AMBIENT;
	}
	if (menu_level == MAIN_MENU && key == '4') { // main -> cow
		menu_level = COW_MENU;
		what_to_move = 1000;
	}
	if (menu_level == MAIN_MENU && key == '5') { // main -> point light
		menu_level = LIGHT_MENU;
		what_to_move = 1000;
	}
	if (menu_level == MAIN_MENU && key == '6') { // main -> camera position
		menu_level = CAMERA_MENU;
		what_to_move = 1000;
	}
	if (menu_level == MAIN_MENU && key == 'b') { // main -> start
		menu_level = START_MENU;
		what_to_move = 1000;
	}
	// Cow menu
	if (menu_level == COW_MENU && key == '1') { // cow handle cow
		what_to_move = MOVE_COW;
	}
	if (menu_level == COW_MENU && key == '2') { // cow handle head
		what_to_move = MOVE_HEAD;
	}
	if (menu_level == COW_MENU && key == '3') { // cow handle tail
		what_to_move = MOVE_TAIL;
	}
	if (menu_level == COW_MENU && key == 'b') { // cow -> main
		menu_level = MAIN_MENU;
		what_to_move = 1000;
	}
	// Point light menu
	if (menu_level == LIGHT_MENU && key == '1') { // light handle pos
		what_to_move = POINT_LIGHT_POS;
	}
	if (menu_level == LIGHT_MENU && key == '2') { // light handle target
		what_to_move = POINT_LIGHT_TARGET;
	}
	if (menu_level == LIGHT_MENU && key == '3') { // light handle intensity
		what_to_move = POINT_LIGHT_IN;
	}
	if (menu_level == LIGHT_MENU && key == 'b') { // light -> main
		menu_level = MAIN_MENU;
		what_to_move = 1000;
	}
	// Camera menu
	if (menu_level == CAMERA_MENU && key == '1') { // cow POV
		camera_type = 1;
	}
	if (menu_level == CAMERA_MENU && key == '2') { // camera view
		camera_type = 0;
	}
	if (menu_level == CAMERA_MENU && key == '3') { // top
		camera_pos[0] = WORLD_SIZE/2, camera_pos[1] = WORLD_SIZE / 2, camera_pos[2] = WORLD_SIZE;
		camera_target[0] = WORLD_SIZE / 2, camera_target[1] = WORLD_SIZE / 2, camera_target[2] = 0;
	}
	if (menu_level == CAMERA_MENU && key == '4') { // front
		camera_pos[0] = WORLD_SIZE / 2, camera_pos[1] = 0, camera_pos[2] = WORLD_SIZE/2;
		camera_target[0] = WORLD_SIZE / 2, camera_target[1] = WORLD_SIZE / 2, camera_target[2] = 0;
	}
	if (menu_level == CAMERA_MENU && key == 'b') { // camera -> main
		menu_level = MAIN_MENU;
	}
	if (what_to_move == MOVE_AMBIENT) {
		switch (key) {
		case 'q':
			value1 += 0.05f;
			if (value1 >= 1.0f)
				value1 = 0.0f;
			std::cout << "value1 " << value1 << std::endl;
			break;
		case 'w':
			value2 += 0.05f;
			if (value2 >= 1.0f)
				value2 = 0.0f;
			std::cout << "value2 " << value2 << std::endl;
			break;
		case 'e':
			value3 += 0.05f;
			if (value3 >= 1.0f)
				value3 = 0.0f;
			std::cout << "value3 " << value3 << std::endl;
			break;
		case 'r':
			value4 += 0.05f;
			if (value4 >= 1.0f)
				value4 = 0.0f;
			std::cout << "value4 " << value4 << std::endl;
			break;
		case 't':
			value1 = 1.0f, value2 = 1.0f, value3 = 1.0f, value4 = 1.0f;
		defalut:
			break;
		}
	}
}

void specialKeysCallback(int key, int x, int y) {

	float angle = 5 * (PI / 180);  // Angle in radians. 5 degrees
	GLfloat dx, dy;

	switch (what_to_move) {
	case MOVE_CAMERA_POS: // Move the camera
		switch (key) {
		case GLUT_KEY_UP:
			if (camera_pos[1] + camera_movement > WORLD_SIZE - camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[1] += camera_movement;
				camera_target[1] += camera_movement;
				std::cout << "camera pos y: " << camera_pos[1] << std::endl;
				std::cout << "camera target y: " << camera_target[1] << std::endl;
			}
			break;
		case GLUT_KEY_DOWN:
			if (camera_pos[1] - camera_movement < 0 + camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[1] -= camera_movement;
				camera_target[1] -= camera_movement;
				std::cout << "camera pos y: " << camera_pos[1] << std::endl;
				std::cout << "camera target y: " << camera_target[1] << std::endl;
			}
			break;
		case GLUT_KEY_LEFT:
			if (camera_pos[0] - camera_movement < 0 + camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[0] -= camera_movement;
				camera_target[0] -= camera_movement;
				std::cout << "camera pos x: " << camera_pos[0] << std::endl;
				std::cout << "camera target x: " << camera_target[0] << std::endl;
			}
			break;
		case GLUT_KEY_RIGHT:
			if (camera_pos[0] + camera_movement > WORLD_SIZE - camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[0] += camera_movement;
				camera_target[0] += camera_movement;
				std::cout << "camera pos x: " << camera_pos[0] << std::endl;
				std::cout << "camera target x: " << camera_target[0] << std::endl;
			}
			break;
		case GLUT_KEY_PAGE_UP:
			if (camera_pos[2] + camera_movement > WORLD_SIZE - camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[2] += camera_movement;
				camera_target[2] += camera_movement;
				std::cout << "camera pos z: " << camera_pos[2] << std::endl;
				std::cout << "camera target z: " << camera_target[2] << std::endl;
			}
			break;
		case GLUT_KEY_PAGE_DOWN:
			if (camera_pos[2] - camera_movement < 0 + camera_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				camera_pos[2] -= camera_movement;
				camera_target[2] -= camera_movement;
				std::cout << "camera pos z: " << camera_pos[2] << std::endl;
				std::cout << "camera target z: " << camera_target[2] << std::endl;
			}
			break;
		default:
			break;
		}
		break;
	case MOVE_CAMERA_TARGET: // Move the target of the camera
		if (camera_type == 0) { // Regular view camera
			switch (key) {
				float rotation_angle;
				GLfloat new_x, new_y, magnitude;
			case GLUT_KEY_LEFT:
				// Calculate the new angle
				rotation_angle = -5.0 * (PI / 180.0);  // 5 degrees in radians
				new_x = world_direction_vector[0] * cos(rotation_angle) - world_direction_vector[1] * sin(rotation_angle);
				new_y = world_direction_vector[0] * sin(rotation_angle) + world_direction_vector[1] * cos(rotation_angle);
				world_direction_vector[0] = new_x;
				world_direction_vector[1] = new_y;
				// Normalize the size of the vector
				magnitude = sqrt(world_direction_vector[0] * world_direction_vector[0] + world_direction_vector[1] * world_direction_vector[1]);
				// Check for zero magnitude to avoid division by zero
				if (magnitude != 0) {
					world_direction_vector[0] /= magnitude;
					world_direction_vector[1] /= magnitude;
				}
				std::cout << world_angle << std::endl;
				break;
			case GLUT_KEY_RIGHT:
				// Calculate the new angle
				rotation_angle = 5.0 * (PI / 180.0);  // 5 degrees in radians
				new_x = world_direction_vector[0] * cos(rotation_angle) - world_direction_vector[1] * sin(rotation_angle);
				new_y = world_direction_vector[0] * sin(rotation_angle) + world_direction_vector[1] * cos(rotation_angle);
				world_direction_vector[0] = new_x;
				world_direction_vector[1] = new_y;
				// Normalize the size of the vector
				magnitude = sqrt(world_direction_vector[0] * world_direction_vector[0] + world_direction_vector[1] * world_direction_vector[1]);
				// Check for zero magnitude to avoid division by zero
				if (magnitude != 0) {
					world_direction_vector[0] /= magnitude;
					world_direction_vector[1] /= magnitude;
				}
				std::cout << world_angle << std::endl;
				break;
			case GLUT_KEY_UP:
				camera_target[2] += camera_movement;
				std::cout << "camera pos z: " << camera_target[2] << std::endl;
				break;
			case GLUT_KEY_DOWN:
				camera_target[2] -= camera_movement;
				std::cout << "camera pos z: " << camera_target[2] << std::endl;
				break;
			default:
				break;
			}
		}
		else { // Cow POV camera

		}
		break;
	case MOVE_COW: // Move the cow
		switch (key) {
		case GLUT_KEY_UP:
			scene->cow->moveForward();
			break;
		case GLUT_KEY_DOWN:
			scene->cow->moveBackwards();
			break;
		case GLUT_KEY_LEFT:
			scene->cow->moveLeft();
			break;
		case GLUT_KEY_RIGHT:
			scene->cow->moveRight();
			break;
		default:
			break;
		}
		break;
	case MOVE_HEAD: // Move the head
		switch (key) {
		case GLUT_KEY_UP:
			scene->cow->headUp();
			break;
		case GLUT_KEY_DOWN:
			scene->cow->headDown();
			break;
		case GLUT_KEY_LEFT:
			scene->cow->headLeft();
			break;
		case GLUT_KEY_RIGHT:
			scene->cow->headRight();
			break;
		default:
			break;
		}
		break;
	case MOVE_TAIL: // Move the tail
		switch (key) {
		case GLUT_KEY_UP:
			scene->cow->tailUp();
			break;
		case GLUT_KEY_DOWN:
			scene->cow->tailDown();
			break;
		case GLUT_KEY_LEFT:
			scene->cow->tailLeft();
			break;
		case GLUT_KEY_RIGHT:
			scene->cow->tailRight();
			break;
		default:
			break;
		}
		break;
	case POINT_LIGHT_POS:
		switch (key) {
		case GLUT_KEY_UP:
			if (scene->light->getPos()[1] + light_movement > WORLD_SIZE - light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0], scene->light->getPos()[1] + light_movement, scene->light->getPos()[2]);
				scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1] + light_movement, scene->light->getPos()[2]);
			}
			break;
		case GLUT_KEY_DOWN:
			if (scene->light->getPos()[1] - light_movement < 0 + light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0], scene->light->getPos()[1] - light_movement, scene->light->getPos()[2]);
				scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1] - light_movement, scene->light->getPos()[2]);
			}
			break;
		case GLUT_KEY_LEFT:
			if (scene->light->getPos()[0] - light_movement < 0 + light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0] - light_movement, scene->light->getPos()[1], scene->light->getPos()[2]);
				scene->light->setTarget(scene->light->getPos()[0] - light_movement, scene->light->getPos()[1], scene->light->getPos()[2]);
			}
			break;
		case GLUT_KEY_RIGHT:
			if (scene->light->getPos()[0] + light_movement > WORLD_SIZE - light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0] + light_movement, scene->light->getPos()[1], scene->light->getPos()[2]);
				scene->light->setTarget(scene->light->getPos()[0] + light_movement, scene->light->getPos()[1], scene->light->getPos()[2]);
			}
			break;
		case GLUT_KEY_PAGE_UP:
			if (scene->light->getPos()[2] + light_movement > WORLD_SIZE - light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] + light_movement);
				scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] + light_movement);
			}
			break;
		case GLUT_KEY_PAGE_DOWN:
			if (scene->light->getPos()[2] - light_movement < 0 + light_movement) {
				std::cout << "Out of bounds" << std::endl;
			}
			else {
				scene->light->setPosition(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] - light_movement);
				scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] - light_movement);
			}
			break;
		default:
			break;
		}
		break;
	case POINT_LIGHT_TARGET:
		switch (key) {
			float rotation_angle;
			GLfloat new_x, new_y, magnitude;
			// Calculate the new angle
			rotation_angle = -5.0 * (PI / 180.0);  // 5 degrees in radians
			new_x = light_direction_vector[0] * cos(rotation_angle) - light_direction_vector[1] * sin(rotation_angle);
			new_y = light_direction_vector[0] * sin(rotation_angle) + light_direction_vector[1] * cos(rotation_angle);
			light_direction_vector[0] = new_x;
			light_direction_vector[1] = new_y;
			// Normalize the size of the vector
			magnitude = sqrt(light_direction_vector[0] * light_direction_vector[0] + light_direction_vector[1] * light_direction_vector[1]);
			// Check for zero magnitude to avoid division by zero
			if (magnitude != 0) {
				light_direction_vector[0] /= magnitude;
				light_direction_vector[1] /= magnitude;
			}
			std::cout << light_angle << std::endl;
			break;
		case GLUT_KEY_RIGHT:
			// Calculate the new angle
			rotation_angle = 5.0 * (PI / 180.0);  // 5 degrees in radians
			new_x = light_direction_vector[0] * cos(rotation_angle) - light_direction_vector[1] * sin(rotation_angle);
			new_y = light_direction_vector[0] * sin(rotation_angle) + light_direction_vector[1] * cos(rotation_angle);
			light_direction_vector[0] = new_x;
			light_direction_vector[1] = new_y;
			// Normalize the size of the vector
			magnitude = sqrt(light_direction_vector[0] * light_direction_vector[0] + light_direction_vector[1] * light_direction_vector[1]);
			// Check for zero magnitude to avoid division by zero
			if (magnitude != 0) {
				light_direction_vector[0] /= magnitude;
				light_direction_vector[1] /= magnitude;
			}
			std::cout << light_angle << std::endl;
			break;
		case GLUT_KEY_UP:
			scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] + light_movement);
			break;
		case GLUT_KEY_DOWN:
			scene->light->setTarget(scene->light->getPos()[0], scene->light->getPos()[1], scene->light->getPos()[2] - light_movement);
			break;
		default:
			break;
		}
		break;
	case POINT_LIGHT_IN:
		switch (key) {
		case GLUT_KEY_UP:
			scene->light->setIntensity(scene->light->getIntensity() + 0.5f);
			break;
		case GLUT_KEY_DOWN:
			scene->light->setIntensity(scene->light->getIntensity() - 0.5f);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
		
}

void World::InitGlut(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cow World");
}

void World::MenuSetup() {
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glDisable(GL_LIGHTING);

	whatToDraw();

	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void World::whatToDraw() {
	switch (menu_level) {
	case START_MENU: 
		drawText("PRESS m FOR MENU!", 10, 30);
		drawText("Make sure the keyboard is in english, and capl lock is off!", 10, 10);
		break;
	case MAIN_MENU: 
		drawText("MAIN MENU:", 10, 150);
		drawText("Press 1 to change camera position", 10, 130); // camera pos
		drawText("Press 2 to change camera target", 10, 110); // camera target
		drawText("Press 3 to change ambient light", 10, 90); // ambient light
		drawText("Press 4 to handle cow movement", 10, 70); // cow menu
		drawText("Press 5 to handle point light", 10, 50); // light menu
		drawText("Press 6 to change camera positions (Cow POV)", 10, 30); // camera menu
		drawText("Press b to go back", 10, 10); // back
		break;
	case COW_MENU:
		drawText("COW MENU:", 10, 90);
		drawText("Press 1 to move the cow", 10, 70);
		drawText("Press 2 to move the head", 10, 50);
		drawText("Press 3 to move the tail", 10, 30);
		drawText("Press b to go back", 10, 10); // back
		break;
	case LIGHT_MENU: 
		drawText("LIGHT MENU:", 10, 90);
		drawText("Press 1 to move the point light", 10, 70);
		drawText("Press 2 to move the target point light", 10, 50);
		drawText("Press 3 to change the intensity", 10, 30);
		drawText("Press b to go back", 10, 10); // back
		break;
	case CAMERA_MENU:
		drawText("CAMERA MENU:", 10, 110);
		drawText("Press 1 for cow POV", 10, 90);
		drawText("Press 2 for camera view", 10, 70);
		drawText("Press 3 for top view", 10, 50);
		drawText("Press 4 for front view", 10, 30);
		drawText("Press b to go back", 10, 10); // back
		break;
	default:
		break;
	}
	switch (what_to_move) {
	case MOVE_CAMERA_POS:
		drawText("Press Arrow up to move forward", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to move backward", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to move left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to move right", 10, WINDOW_HEIGHT - 80);
		drawText("Press Page up to move up", 10, WINDOW_HEIGHT - 100);
		drawText("Press Page down to move down", 10, WINDOW_HEIGHT - 120);
		break;
	case MOVE_CAMERA_TARGET:
		drawText("Press Arrow up to look up", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to look down", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to rotate left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to rotate right", 10, WINDOW_HEIGHT - 80);
		break;
	case MOVE_COW:
		drawText("Press Arrow up to move forward", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to move backward", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to rotate left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to rotate right", 10, WINDOW_HEIGHT - 80);
		break;
	case MOVE_HEAD:
		drawText("Press Arrow up to move forward", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to move backward", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to move left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to move right", 10, WINDOW_HEIGHT - 80);
		break;
	case MOVE_TAIL:
		drawText("Press Arrow up to move forward", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to move backward", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to move left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to move right", 10, WINDOW_HEIGHT - 80);
		break;
	case POINT_LIGHT_POS:
		drawText("Press Arrow up to move forward", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to move backward", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to move left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to move right", 10, WINDOW_HEIGHT - 80);
		drawText("Press Page up to move up", 10, WINDOW_HEIGHT - 100);
		drawText("Press Page down to move down", 10, WINDOW_HEIGHT - 120);
		break;
	case POINT_LIGHT_TARGET:
		drawText("Press Arrow up to look up", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to look down", 10, WINDOW_HEIGHT - 40);
		drawText("Press Arrow left to rotate left", 10, WINDOW_HEIGHT - 60);
		drawText("Press Arrow right to rotate right", 10, WINDOW_HEIGHT - 80);
		break;
	case POINT_LIGHT_IN:
		drawText("Press Arrow up to increase intensity", 10, WINDOW_HEIGHT - 20);
		drawText("Press Arrow down to decrease intensity", 10, WINDOW_HEIGHT - 40);
		break;
	case MOVE_AMBIENT:
		drawText("Press q to change red property", 10, WINDOW_HEIGHT - 20);
		drawText("Press w to change green property", 10, WINDOW_HEIGHT - 40);
		drawText("Press e to change blue property", 10, WINDOW_HEIGHT - 60);
		drawText("Press r to change alpha property", 10, WINDOW_HEIGHT - 80);
		drawText("Press t to return to original lighting", 10, WINDOW_HEIGHT - 100);
		break;
	default:
		break;
	}
}

void World::RegisterCallbacks() {
	glutDisplayFunc(displaycallback);
	glutReshapeFunc(reshapecallback);
	MenuSetup();
	glutKeyboardFunc(keyboardcallback);
	glutSpecialFunc(specialKeysCallback);
}

World::World(int argc, char** argv) {
	InitGlut(argc, argv);

	//Create the world objects
	this->env = new Env();
	this->cow = new Cow();
	this->light = new Light(1);
	this->objects = new Objects();

	::scene = this;
	RegisterCallbacks();
}

World::~World() {
	delete env;

}

void World::Display() {
	
	// Clear the buffers
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Clear to red for visibility
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set up the view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, WINDOW_RATIO, 1, 1000);

	// Light
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	GLfloat ambientLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // White light
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glEnable(GL_LIGHT0);
	GLfloat lightDirection[] = { WORLD_SIZE/2, WORLD_SIZE/2, 0, 1.0f };  // Light coming from above
	glLightfv(GL_LIGHT0, GL_POSITION, lightDirection);
	GLfloat mat_ambient[] = { value1, value2, value3, value4 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);


	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glDepthFunc(GL_LEQUAL);
	//glDisable(GL_CULL_FACE);


	// Set up the camera
	if (camera_type == 0) {

		gluLookAt(camera_pos[0], camera_pos[1], camera_pos[2], camera_target[0], camera_target[1], camera_target[2], 0.0, 1.0, 0.0);
	}
	else {
		std::cout << "Cow X " << cow->getPosition(HEAD)[0] << "Cow Y " << cow->getPosition(HEAD)[1] << "Cow Z " << cow->getPosition(HEAD)[2] << std::endl;

		//glTranslatef(cow_pos[0], cow_pos[1], cow_pos[2]);
		gluLookAt(
			cow_pos_x + cow->getPosition(HEAD)[0], cow_pos_y + cow->getPosition(HEAD)[1], cow_pos_z + cow->getPosition(HEAD)[2] + 20,
			//75,75,50,
			cow_pos_x + cow->getPosition(HEAD)[0] + cow->getDirection()[0], cow_pos_y + cow->getPosition(HEAD)[1] + cow->getDirection()[1], cow_pos_z + cow->getPosition(HEAD)[2] + 20 + cow->getDirection()[2],
			0.0, 0.0,1.0);
		//glTranslatef(-cow_pos[0], -cow_pos[1], -cow_pos[2]);
		//std::cout << "Cow X " << cow->getPosition(HEAD)[0] << "Cow Y " << cow->getPosition(HEAD)[1] << "Cow Z " << cow->getPosition(HEAD)[2] << std::endl;

	}

	// Draw the scene
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	// calcualte the camera target angle
	world_angle = atan2(world_direction_vector[1], world_direction_vector[0]) * (180.0 / PI);
	// rotate the env
	glTranslatef(camera_pos[0], camera_pos[1], camera_pos[2]);
	glRotatef(world_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-camera_pos[0], -camera_pos[1], -camera_pos[2]);
	// env
	env->draw();
	// objects
	glTranslatef(0, 0, 0);
	objects->draw();
	// cow
	glTranslatef(cow_pos[0], cow_pos[1], cow_pos[2]);
	cow->draw();
	// point light
	glPushMatrix();
	light_angle = atan2(light_direction_vector[1], light_direction_vector[0]) * (180.0 / PI);
	// rotate the light
	glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
	glRotatef(light_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-light_pos[0], -light_pos[1], -light_pos[2]);
	light->draw();
	glPopMatrix();
	glPopMatrix();

	// Draw sthe menu on the screen
	MenuSetup();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void World::Reshape(GLint winWidth, GLint winHeight) {
	glViewport(0, 0, winWidth, winHeight);
	WINDOW_RATIO = winWidth / winHeight;
}




