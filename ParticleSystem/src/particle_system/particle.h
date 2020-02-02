#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glad\glad.h>
#include "../Shader.h"

class Particle {

public:

	Particle(glm::vec3 _position);

	void update(float deltaTime);

	void draw();

	void reset(glm::vec3 _position);

	glm::mat4 calculateBillboardMatrix();

private:

	//time to live
	float ttl;
	float speed;
	glm::vec3 dir;
	glm::vec3 position;
	glm::vec3 positionStart;
	
	
	





};
