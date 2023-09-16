#include "light.h"


Light::Light(GLenum id) : lightID(id) {
    enable();
}

// getters and setters
GLfloat* Light::getPos() {
    return this->lightPosition;
}

GLfloat* Light::getTarget() {
    return this->lightTarget;
}

GLfloat Light::getIntensity() {
    return this->intensity;
}

void Light::setPosition(GLfloat x, GLfloat y, GLfloat z) {
    lightPosition[0] = x;
    lightPosition[1] = y;
    lightPosition[2] = z;
}

void Light::setTarget(GLfloat x, GLfloat y, GLfloat z) {
    lightTarget[0] = x;
    lightTarget[1] = y;
    lightTarget[2] = z;
}

void Light::setIntensity(GLfloat inten) {
    this->intensity = inten;
}

void Light::enable() {
    glEnable(lightID);
}

void Light::disable() {
    glDisable(lightID);
}

// draw the light
void Light::draw() {
    glPushMatrix();
    glTranslated(lightPosition[0], lightPosition[1], lightPosition[2]);

    GLfloat ambient[4] = {0.8f,0.8f,0.8f,1.0f};
    GLfloat diffuse[4] = {0.01f,0.01f,0.01f,1.0f};
    GLfloat specular[4] = {0.5f,0.5f,0.5f,1.0f};
    GLfloat shine = 32.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

    // the light in the scene
    glDisable(GL_LIGHTING);
    glColor3fv(color);
    glutSolidSphere(0.2, 100, 100);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightTarget);
    GLfloat lightIntensity[] = { intensity,intensity,intensity, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

    glPopMatrix();

}

