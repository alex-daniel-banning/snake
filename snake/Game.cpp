#include "Game.h"
#include <glad/glad.h>

Game::Game()
{
	width = 800;
	height = 800;
	snake = std::vector<Coordinates>();
	snake.push_back({ 1, 1 });
	snake.push_back({ 2, 1 });
	snake.push_back({ 3, 1 });
	VAO = VBO = 0;
}

void Game::initialize()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(snakeSegmentVertices), snakeSegmentVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Game::render(Shader& shader)
{
	for (int i = 0; i < snake.size(); i++) {

	}
	shader.use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

// todo, destructor
