#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glad\glad.h>

#include "particle.h"

#include <vector>

using namespace std;


class ParticleSystem {


public:
	
	ParticleSystem(unsigned int _VAO, unsigned int _VBO, glm::vec3 _position);

	void createParticle();

	void spawnParticles(float deltaTime);

	void update(float deltaTime);

	void draw(Shader* shader, GLuint texture, glm::mat4 view, glm::mat4 projection);

private:


	int activeParticles = 0;
	int maxParticles = 100;
	int lastParticlePos;

	float particlesPerSpawn = 2;
	float timeBetweenSpawn = 0.3;
	float timeLeftSpawn;

	vector<Particle *> particles;

	glm::vec3 position;
	glm::vec3 positionStart;



	unsigned int VBO;
	unsigned int VAO;


};