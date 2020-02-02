#include "particleSystem.h"
#include <iostream>

using namespace std;

ParticleSystem::ParticleSystem(unsigned int _VAO, unsigned int _VBO, glm::vec3 _position) {

	VAO = _VAO;
	VBO = _VBO;

	particles.resize(maxParticles);

	positionStart = _position;
	position = positionStart;

	lastParticlePos = -1;

	timeLeftSpawn = timeBetweenSpawn;
}


void ParticleSystem::createParticle() {

	int index = (lastParticlePos + 1) % maxParticles;
	
	if (activeParticles < maxParticles) {
		cout << "Creating a new particle number: " <<index<< endl;

		Particle* particle;
		particle = new Particle(position);
		particles[index] = particle;
		activeParticles++;
	}
	else {
		particles[index]->reset(position);
	}

	lastParticlePos = index;
}



void ParticleSystem::draw(Shader* shader, GLuint texture, glm::mat4 view, glm::mat4 projection) {

	shader->use();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	shader->setInt("image", 0);

	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
	

	// Binds the vertex array to be drawn
	glBindVertexArray(VAO);

	for (int i = 0; i < activeParticles; i++) {


		glm::mat4 model = particles[i]->calculateBillboardMatrix();
		//glm::mat4 model = glm::mat4(1.0f);
		shader->setMat4("model", model);
		particles[i]->draw();
	}

	glBindVertexArray(0);
}

void ParticleSystem::update(float deltaTime){

	spawnParticles(deltaTime);

	for (int i = 0; i < activeParticles; i++) {
		
		particles[i]->update(deltaTime);
	}
}


void ParticleSystem::spawnParticles(float deltaTime) {

	timeLeftSpawn -= deltaTime;

	if (timeLeftSpawn <= 0) {

		for (int i = 0; i < particlesPerSpawn; i++) {

			createParticle();
		}

		timeLeftSpawn = timeBetweenSpawn;
	}
}