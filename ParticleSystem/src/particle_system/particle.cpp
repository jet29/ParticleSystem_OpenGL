#include "particle.h"
#include <iostream>

using namespace std;


Particle::Particle(glm::vec3 _position) {

	dir = glm::vec3(0, 1, 0);
	ttl = 3;
	speed = 1.0f;

	positionStart = _position;
	position = positionStart;
}

void Particle::draw() {

	// Render triangle's geometry
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	

}


void Particle::update(float deltaTime) {

	position = position + (deltaTime * dir * speed);

}

glm::mat4 Particle::calculateBillboardMatrix() {

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, position);

	return model;
}

void Particle::reset(glm::vec3 _position) {

	positionStart = _position;
	position = positionStart;
}