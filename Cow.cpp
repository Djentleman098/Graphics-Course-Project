#include "Cow.h"
//#include "libs.h"

Cow::Cow() {
	generateCow();
}

GLfloat* Cow::getPosition(int bodyPart) {
    return this->bodyPos[bodyPart];
}

GLfloat* Cow::getDirection() {
    return this->body_direction_vector;
}

//Movements
//Full cow
void Cow::moveLeft() {
    // Calculate the new angle
    float rotation_angle = 5.0 * (PI / 180.0);  // 5 degrees in radians
    GLfloat new_x = body_direction_vector[0] * cos(rotation_angle) - body_direction_vector[1] * sin(rotation_angle);
    GLfloat new_y = body_direction_vector[0] * sin(rotation_angle) + body_direction_vector[1] * cos(rotation_angle);
    body_direction_vector[0] = new_x;
    body_direction_vector[1] = new_y;
    // Normalize the size of the vector
    GLfloat magnitude = sqrt(body_direction_vector[0] * body_direction_vector[0] + body_direction_vector[1] * body_direction_vector[1]);
    // Check for zero magnitude to avoid division by zero
    if (magnitude != 0) {
        body_direction_vector[0] /= magnitude;
        body_direction_vector[1] /= magnitude;
    }

    std::cout << body_angle << std::endl;
    std::cout << "Cow X " << bodyPos[BODY][0] << std::endl;
    std::cout << "Cow Y " << bodyPos[BODY][1] << std::endl;
    std::cout << "Dir Vector: " << body_direction_vector[0] << ", " << body_direction_vector[1] << std::endl;
}

void Cow::moveRight() {
    // Calculate the new angle
    float rotation_angle = -5.0 * (PI / 180.0);  // -5 degrees in radians
    GLfloat new_x = body_direction_vector[0] * cos(rotation_angle) - body_direction_vector[1] * sin(rotation_angle);
    GLfloat new_y = body_direction_vector[0] * sin(rotation_angle) + body_direction_vector[1] * cos(rotation_angle);
    body_direction_vector[0] = new_x;
    body_direction_vector[1] = new_y;
    // Normalize the size of the vector
    GLfloat magnitude = sqrt(body_direction_vector[0] * body_direction_vector[0] + body_direction_vector[1] * body_direction_vector[1]);
    // Check for zero magnitude to avoid division by zero
    if (magnitude != 0) {
        body_direction_vector[0] /= magnitude;
        body_direction_vector[1] /= magnitude;
    }

    std::cout << body_angle << std::endl;
    std::cout << "Cow X " << bodyPos[BODY][0] << " " << std::endl;
    std::cout << "Cow Y " << bodyPos[BODY][1] << " " << std::endl;
    std::cout << "Dir Vector: " << body_direction_vector[0] << ", " << body_direction_vector[1] << std::endl;
}

void Cow::moveForward() {
    GLfloat dx = cow_movement * body_direction_vector[0];
    GLfloat dy = cow_movement * body_direction_vector[1];

    // Check for boundries
    if ((bodyPos[1][0] + dx > WORLD_SIZE / 4 - WORLD_SIZE/20 && dx > 0) ||
        (bodyPos[1][1] + dy > WORLD_SIZE / 4 - WORLD_SIZE / 20 && dy > 0)||
        (bodyPos[1][0] - dx < -WORLD_SIZE / 4 + WORLD_SIZE / 20 && dx < 0)||
        (bodyPos[1][1] - dy < -WORLD_SIZE / 4 + WORLD_SIZE / 20 && dy < 0)){
        std::cout << "Out of bounds" << std::endl;
    }
    else {
        for (int i = 0; i < 10; i++) {
            this->bodyPos[i][0] += dx;
            this->bodyPos[i][1] += dy;
        }
    }
    std::cout << "Cow X " << bodyPos[BODY][0] << " " << dx << std::endl;
    std::cout << "Cow Y " << bodyPos[BODY][1] << " " << dy << std::endl;
    std::cout << "Head X " << bodyPos[HEAD][0] << std::endl;
    std::cout << "Head Y " << bodyPos[HEAD][1] << std::endl;
    std::cout << "Dir Vector: " << body_direction_vector[0] << ", " << body_direction_vector[1] << std::endl;


}

void Cow::moveBackwards() {
    GLfloat dx = cow_movement * body_direction_vector[0];
    GLfloat dy = cow_movement * body_direction_vector[1];

    // Check for boundries
    if ((bodyPos[1][0] + dx > WORLD_SIZE / 4 - WORLD_SIZE / 20 && dx < 0) ||
        (bodyPos[1][1] + dy > WORLD_SIZE / 4 - WORLD_SIZE / 20 && dy < 0) ||
        (bodyPos[1][0] - dx < -WORLD_SIZE / 4 + WORLD_SIZE / 20 && dx > 0) ||
        (bodyPos[1][1] - dy < -WORLD_SIZE / 4 + WORLD_SIZE / 20 && dy > 0)) {
        std::cout << "Out of bounds" << std::endl;
    }
    else {
        for (int i = 0; i < 10; i++) {
            this->bodyPos[i][0] -= dx;
            this->bodyPos[i][1] -= dy;
        }
    }
    std::cout << "Cow X " << bodyPos[BODY][0] << " " << dx << std::endl;
    std::cout << "Cow Y " << bodyPos[BODY][1] << " " << dy << std::endl;
    std::cout << "Head X " << bodyPos[HEAD][0] << std::endl;
    std::cout << "Head Y " << bodyPos[HEAD][1] << std::endl;
    std::cout << "Dir Vector: " << body_direction_vector[0] << ", " << body_direction_vector[1] << std::endl;

}


//Head
void Cow::headLeft() {
    //if (head_angle <= -20) {
    //    std::cout << "Out of bounds" << std::endl;
    //}
    //else {
    //    head_angle -= 5;
    //}
    //std::cout << head_angle << std::endl;
    //std::cout << "Head X " << bodyPos[HEAD][0] << std::endl;
    //std::cout << "Head Y " << bodyPos[HEAD][1] << std::endl;

}

void Cow::headRight() {
    //if (head_angle >= 20) {
    //    std::cout << "Out of bounds" << std::endl;
    //}
    //else {
    //    head_angle += 5;
    //}
    //std::cout << head_angle << std::endl;
    //std::cout << "Head X " << bodyPos[HEAD][0] << std::endl;
    //std::cout << "Head Y " << bodyPos[HEAD][1] << std::endl;
}

void Cow::headUp() {
    //head, ears, eyes, nose should move in an angle
}

void Cow::headDown() {
    //head, ears, eyes, nose should move in an angle
}
//Tail
void Cow::tailLeft() {
    //tail_angle += 5;
    //std::cout << tail_angle << std::endl;
    //std::cout << "Tail X " << bodyPos[TAIL][0] << std::endl;
    //std::cout << "Tail Y " << bodyPos[TAIL][1] << std::endl;
}

void Cow::tailRight() {
    //tail_angle -= 5;
    //std::cout << tail_angle << std::endl;
    //std::cout << "Tail X " << bodyPos[TAIL][0] << std::endl;
    //std::cout << "Tail Y " << bodyPos[TAIL][1] << std::endl;
}

void Cow::tailUp() {
    //tail should move in an angle
}

void Cow::tailDown() {
    //tail should move in an angle
}


//Draw
void Cow::generateCow() {
    draw();
}

float Cow::calcBodyAngle() {
    return atan2(body_direction_vector[1], body_direction_vector[0]) * (180.0 / PI);
}

void Cow::rotate(int bodyPart, GLfloat angle) {
    glTranslatef(bodyPos[bodyPart][0], bodyPos[bodyPart][1], bodyPos[bodyPart][2]);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-bodyPos[bodyPart][0], -bodyPos[bodyPart][1], -bodyPos[bodyPart][2]);
}

void Cow::draw() {
    glPushMatrix();

    // Handle angle of body
    glTranslatef(bodyPos[BODY][0], bodyPos[BODY][1], bodyPos[BODY][2]);

    body_angle = calcBodyAngle();
    rotate(BODY, body_angle);

    head();
	body();
	legs();
	tail();

    glTranslatef(-bodyPos[BODY][0], -bodyPos[BODY][1], -bodyPos[BODY][2]);

    glPopMatrix();
}

void Cow::head() {
    // Draw head
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(bodyPos[HEAD][0], bodyPos[HEAD][1], bodyPos[HEAD][2]);
    rotate(HEAD, head_angle);

    glColor3f(0.545, 0.271, 0.075);  // Set color to white
    glutSolidSphere(head_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // Draw ears, eyes, nose
    //glTranslatef(bodyPos[EARS][0], bodyPos[EARS][1], bodyPos[EARS][2]);
    ears();
   // glTranslatef(-bodyPos[EARS][0], -bodyPos[EARS][1], -bodyPos[EARS][2]);
   // glTranslatef(bodyPos[EYES][0], bodyPos[EYES][1], bodyPos[EYES][2]);
    eyes();
   // glTranslatef(-bodyPos[EYES][0], -bodyPos[EYES][1], -bodyPos[EYES][2]);
   // glTranslatef(bodyPos[NOSE][0], bodyPos[NOSE][1], bodyPos[NOSE][2]);
    nose();
   // glTranslatef(-bodyPos[NOSE][0], -bodyPos[NOSE][1], -bodyPos[NOSE][2]);
}

void Cow::body() {
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.545, 0.271, 0.075);  // Set color to white
    glTranslatef(bodyPos[BODY][0], bodyPos[BODY][1], bodyPos[BODY][2]);
    glScalef(1, 0.5, 0.5);
    glutSolidCube(body_size);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void Cow::legs() {
    for (int i = FRONT_LEFT_LEG; i <= BACK_RIGHT_LEG; ++i) {
        glPushMatrix();
        glDisable(GL_LIGHTING);
        glColor3f(0.545, 0.271, 0.075);  // Set color to white
        glTranslatef(bodyPos[i][0], bodyPos[i][1], bodyPos[i][2]);
        glScalef(0.2, 0.2, 1);
        glutSolidCube(leg_size);
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }
}

void Cow::ears() {
    // left ear
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glTranslatef(bodyPos[EARS][0], bodyPos[EARS][1] - 4, bodyPos[EARS][2]); // adjusted for left ear
    rotate(HEAD, head_angle);
    glutSolidSphere(ear_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // right ear
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glTranslatef(bodyPos[EARS][0], bodyPos[EARS][1] + 4, bodyPos[EARS][2]); // adjusted for right ear
    rotate(HEAD, head_angle);
    glutSolidSphere(ear_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void Cow::tail() {
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(bodyPos[TAIL][0], bodyPos[TAIL][1], bodyPos[TAIL][2]);
    rotate(TAIL, tail_angle);

    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glScalef(0.3, 0.3, 1.0);
    glutSolidCube(tail_size);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void Cow::eyes() {
    // left eye
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glTranslatef(bodyPos[EYES][0], bodyPos[EYES][1] - 4, bodyPos[EYES][2]); // adjusted for left eye
    glutSolidSphere(eye_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // right eye
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glTranslatef(bodyPos[EYES][0], bodyPos[EYES][1] + 4, bodyPos[EYES][2]); // adjusted for right eye
    glutSolidSphere(eye_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void Cow::nose() {
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);  // Set color to black
    glTranslatef(bodyPos[NOSE][0], bodyPos[NOSE][1], bodyPos[NOSE][2]);
    glutSolidSphere(nose_size, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

