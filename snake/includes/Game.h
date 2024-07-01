#pragma once

#include <vector>

#include "Coordinates.h"
#include "Shader.h"

class Game {
public:
	Game();
	void initialize();
	void render(Shader& shader);
private:
	static const int VERTEX_ARRAY_SIZE = 18;

	std::vector<Coordinates> snake;
	int width, height;

	// rendering
	unsigned int VBO, VAO;
	const float snakeSegmentVertices[VERTEX_ARRAY_SIZE] = {
		0.5f,  0.5f, 0.0f,  // Top right
		0.5f, -0.5f, 0.0f,  // Bottom right
	   -0.5f, -0.5f, 0.0f,  // Bottom left

	   // Second triangle
		0.5f,  0.5f, 0.0f,  // Top right
	   -0.5f, -0.5f, 0.0f,  // Bottom left
	   -0.5f,  0.5f, 0.0f   // Top left
	};
};

