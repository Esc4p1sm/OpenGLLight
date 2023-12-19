#include "Renderer.h"

Renderer::Renderer() = default;

void Renderer::GenerateBuffers (const float (&vertices)[288],GLuint *vbo,GLuint* vao)
{
	glGenVertexArrays(1, &*vao);
	glGenBuffers(1, *&vbo);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Renderer::GenerateBuffers (GLuint* vbo,  GLuint* vao)
{  
	glGenVertexArrays(1, &*vao);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
}

Renderer::~Renderer() {}

