#include "Env.h"
#include "libs.h"

Env::Env() {
	generateEnv();
}

GLfloat* Env::getPosition() {
	return this->position;
}

//Draw
void Env::draw() {
	
	glPushMatrix();
	//glTranslatef(camera_x, camera_y, camera_z);  // replace with your camera position
	float size = this->worldSize;
	glTranslatef(this->position[0], this->position[1], this->position[2]);

	glEnable(GL_TEXTURE_2D);

	// front
	glBindTexture(GL_TEXTURE_2D, this->frontTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, size, 0);// bottom left position of the front face
	glTexCoord2f(1, 0); glVertex3f(size, size, 0); // bootom right position of the front face
	glTexCoord2f(1, 1); glVertex3f(size, size, size); // top right position of the front face
	glTexCoord2f(0, 1); glVertex3f(0, size, size); // top left position of the front face
	glEnd();

	// back
	glBindTexture(GL_TEXTURE_2D, this->backTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(size, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(size, 0, size);
	glTexCoord2f(0, 1); glVertex3f(0, 0, size);
	glEnd();

	// right
	glBindTexture(GL_TEXTURE_2D, this->rightTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(size, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(size, size, 0);
	glTexCoord2f(1, 1); glVertex3f(size, size, size);
	glTexCoord2f(0, 1); glVertex3f(size, 0, size);
	glEnd();

	// left
	glBindTexture(GL_TEXTURE_2D, this->leftTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(0, size, 0);
	glTexCoord2f(1, 1); glVertex3f(0, size, size);
	glTexCoord2f(0, 1); glVertex3f(0, 0, size);
	glEnd();

	// top
	glBindTexture(GL_TEXTURE_2D, this->topTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, size);
	glTexCoord2f(1, 0); glVertex3f(size, 0, size);
	glTexCoord2f(1, 1); glVertex3f(size, size, size);
	glTexCoord2f(0, 1); glVertex3f(0, size, size);
	glEnd();

	// ground
	glBindTexture(GL_TEXTURE_2D, this->groundTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(size, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(size, size, 0);
	glTexCoord2f(0, 1); glVertex3f(0, size, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}



//Generate texture
void Env::generateEnv() {
	
	GLuint skyTextures[6];
	const char* skyFiles[6] = { "./img/sky/top.png", "./img/sky/front.png", "./img/sky/back.png", "./img/sky/left.png", "./img/sky/right.png", "./img/ground/grass.png"};
	GLuint* skyTextureTargets[6] = { &this->topTex, &this->frontTex, &this->backTex, &this->leftTex, &this->rightTex ,&this->groundTex};
	
	glGenTextures(6, skyTextures);

	for (int i = 0; i < 6; i++) {
		int width, height, nrChannels;
		//Load images
		unsigned char* data = stbi_load(skyFiles[i], &width, &height, &nrChannels, STBI_rgb_alpha);
		if (!data) {
			std::cout << "Failed to load image" << std::endl;
			return;
		}
		else {
			std::cout << "Successfully loaded" << std::endl;
		}

		//Geberate and bind the textures
		glBindTexture(GL_TEXTURE_2D, skyTextures[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);

		*skyTextureTargets[i] = skyTextures[i];

	}

	glBindTexture(GL_TEXTURE_2D, 0);

}

