#pragma once

#include <GL/glut.h>
#include <GL/gl.h>
#include "constants.h"


//////Parameters
//Window
const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 800;
static int WINDOW_RATIO = WINDOW_WIDTH / WINDOW_HEIGHT;

//Camera
float camera_pos_x = 75, camera_pos_y = 0, camera_pos_z = 80; // position in the world
float camera_target_x = 75, camera_target_y = 240, camera_target_z = -10; // direction to look at
GLfloat camera_pos[3] = { camera_pos_x,camera_pos_y,camera_pos_z };
GLfloat camera_target[3] = { camera_target_x,camera_target_y,camera_target_z };

// target camera angle
GLfloat world_angle = 0;
GLfloat world_direction_vector[3] = { 1, 0, 0 };

// ambient light
GLfloat value1 = 1.0f, value2 = 1.0f, value3 = 1.0f, value4 = 1.0f;

//Cow
float cow_pos_x = 75, cow_pos_y = 75, cow_pos_z = 10;
GLfloat cow_pos[3] = { cow_pos_x,cow_pos_y,cow_pos_z };
float body_angle = 0, head_angle = 0, tail_angle = 0;

// Point Light
float light_pos_x = 75, light_pos_y = 75, light_pos_z = 50; // position in the world
GLfloat light_pos[3] = { light_pos_x,light_pos_y,light_pos_x };
GLfloat light_direction_vector[3] = { 1, 1, 0 };
GLfloat light_angle = 0;

//Menu
//hirarchy
#define START_MENU 0
#define MAIN_MENU 1
#define COW_MENU 2
#define LIGHT_MENU 3
#define CAMERA_MENU 4
int menu_level = START_MENU;
//what to move
#define MOVE_CAMERA_POS 0
#define MOVE_CAMERA_TARGET 1
#define MOVE_COW 2
#define MOVE_HEAD 3
#define MOVE_TAIL 4
#define POINT_LIGHT_POS 5
#define POINT_LIGHT_TARGET 6
#define POINT_LIGHT_IN 7
#define MOVE_AMBIENT 8
int what_to_move = 1000;

int camera_type = 0; // 0 = regular, 1 = cow pov
float camera_movement = 10.0f; // The change in position in every movement by the keyboard
float light_movement = 10.0f;

