#pragma once

#define GLEW_STATIC
#include <glew.h>

class Renderer
{
  public:
		 
	Renderer();

	void GenerateBuffers (const float(&vertices)[288],GLuint *vbo,GLuint* vao);

	void GenerateBuffers (GLuint* vbo, GLuint* vao);
	
	void AddAtribb(int layout,
				   int argumentSize,
				   int argumentType ,
				   int normalizeData,
				   int dataStep,
				   GLvoid* beginningData)
	{
		glVertexAttribPointer(layout, argumentSize, argumentType, normalizeData, dataStep, beginningData);
		glEnableVertexAttribArray(layout);
	}

	void Render (int mode, GLuint vao,int elements)
	{
		glBindVertexArray(vao);
		glDrawArrays(mode, 0, elements);
		glBindVertexArray(0);
	}

	static void AtribbUnbind ()
	{
		glBindVertexArray(0);
	}

	static void DeleteVao(int value,GLuint *vao)
	{
		glDeleteVertexArrays(value, &*vao);
	}

	static void DeleteVbo(int value,GLuint *vbo)
	{
		glDeleteBuffers(value, &*vbo);
	}

	 ~Renderer();
};

