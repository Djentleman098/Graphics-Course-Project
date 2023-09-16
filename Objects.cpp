#include "Objects.h"


Objects::Objects() {
	draw();
}

void Objects::draw() {
	drawLamp();
	drawBall();
	drawBin();
}

void Objects::drawLamp() {
	glPushMatrix();
	glDisable(GL_LIGHTING);

	// base
	glTranslatef(street_lamp_pos[0], street_lamp_pos[1], street_lamp_pos[2]);
	glColor3f(0, 0, 0); // 
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, lamp_base_size / 10, lamp_base_size / 10, lamp_base_size, 32, 32); // cylinder for base

	// light source
	glTranslatef(0.0f, 0.0f, lamp_base_size);
	glColor3f(1.0, 1.0, 1.0); // yellow
	glutSolidSphere(lamp_base_size / 4, 20, 20);

	gluDeleteQuadric(quad);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

// metalic ball
void Objects::drawBall() {
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glTranslatef(ball_pos[0], ball_pos[1], ball_pos[2]);
	// metallic material properties
	GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shininess[] = { 76.8 };  // Reflectivity coefficient
	// material properties
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glutSolidSphere(ball_size, 20, 20);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void Objects::drawBin() {
	glPushMatrix();
	glDisable(GL_LIGHTING);

	glTranslatef(bin_pos[0], bin_pos[1], bin_pos[2]);
	glColor3f(0.96f, 0.86f, 0.7f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);

	// top half of the sphere as the bowl
	GLdouble eqn[4] = { 0.0, -1.0, 0.0, 0.0 };  // Plane equation to clip bottom half of the sphere
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_CLIP_PLANE0);
	glScalef(1, 0.5, 1);  // Squeeze the sphere to make it more bowl-like
	glutSolidSphere(bin_size, 32, 32);
	glDisable(GL_CLIP_PLANE0);

	glEnable(GL_LIGHTING);
	glPopMatrix();
}

