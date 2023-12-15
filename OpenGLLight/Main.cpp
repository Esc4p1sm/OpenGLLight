
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include <SOIL.h>
//#define GLM_FORCE_SWIZZLE
//#include "glm/ext.hpp"
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
const char* vertexPath = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderFall.vs";
const char* fragPath = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderFall.frag";
const char* vertexLightPath = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderLamp.vs";
const char* fragLightPath = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderLamp.frag";

const char* testVerShader = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/TestShader/TestShader.vs";
const char* testFragShader = "D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/TestShader/TestShaderFrag.frag";

Window *window=new Window{ 3,3,1000,900,"LightWindow" };
Input input{ 800,600,glm::vec3{1.0f,1.0f,1.0f} };
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main()
{
	//������������� glfw
	window->InitializationGLFW();

	//change
	//�������� ����
	window->CreatWindow();
	//������ ����-������� 
	Shader cubeShader(vertexPath, fragPath);
	//������ ���-��������
	Shader lightShader(vertexLightPath, fragLightPath);

	//TestShader
	Shader testShader(testVerShader, testFragShader);

	constexpr float vertices[] =
	{
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	glm::vec3 cubePositions[] =
	{
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};

	constexpr float testVertexes[] =
	{
		// Positions          // Texture Coords
	   0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // Top Right
	   0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // Bottom Right
	  -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // Bottom Left
	  -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // Top Left     


	};
	GLuint indices[] = {  // Note that we start from 0!
	   0, 1, 3, // First Triangle
	   1, 2, 3  // Second Triangle
	};


	GLuint vbo;

	//��� ������� �����
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	//��� � �������� ��������� �����
	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	//testCube
	GLuint testVAO, testVBO, testEBO;
	glGenVertexArrays(1, &testVAO);
	glGenBuffers(1, &testVBO);
	glGenBuffers(1, &testEBO);
	glBindVertexArray(testVAO);
	glBindBuffer(GL_ARRAY_BUFFER, testVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, testEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), nullptr);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	//textures
	GLuint texture;
	int w, h;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	unsigned char* image = SOIL_load_image("C:/Users/KK/Desktop/project/container2.png", &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);


	GLuint texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	unsigned char* image2 = SOIL_load_image("C:/Users/KK/Desktop/project/sky.jpg", &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image2);
	glBindTexture(GL_TEXTURE_2D, 0);


	//������� ����
	while (!glfwWindowShouldClose(window->ReturnWindow()))
	{
		GLfloat	currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		//cout <<"delta:" << deltaTime << endl <<"lastFrame:" << lastFrame << endl <<"currentframe:" << currentFrame << endl;

		//�������� ������ �������
		glfwPollEvents();

		//���������� �������
		input.DoMovement();
		glfwSetCursorPosCallback(window->ReturnWindow(), Input::MouseCallback);

		//�������� �������
		glEnable(GL_DEPTH_TEST);

		//������ �������
		glfwSetInputMode(window->ReturnWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		//������� ����
		glfwSetKeyCallback(window->ReturnWindow(), Input::KeyCallBack);
		glfwSetScrollCallback(window->ReturnWindow(), Input::ScrollCallback);


		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		//������� �������
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//��������� �� ��������
		lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0;
		lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;

		//��������� ���-�������
		cubeShader.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE1);
		cubeShader.setInt("material.diffuse", 0);
		cubeShader.setVec3("light.position", lightPos);
		cubeShader.setVec3("viewPos", camera.position);
		GLint objectColorLoc = glGetUniformLocation(cubeShader.ID, "objectColor");
		GLint lightColorLoc = glGetUniformLocation(cubeShader.ID, "lightColor");
		GLint lightPosition = glGetUniformLocation(cubeShader.ID, "lightPos");
		GLint viewPosLoc = glGetUniformLocation(cubeShader.ID, "viewPos");
		glUniform3f(viewPosLoc, camera.position.x, camera.position.y, camera.position.z);
		glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
		glUniform3f(lightPosition, lightPos.x, lightPos.y, lightPos.z);


		cubeShader.setVec3("material.ambient", 0.5f, 0.2f, 0.31f);
		cubeShader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
		cubeShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
		cubeShader.setFloat("material.shininess", 32.0f);

		cubeShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
		cubeShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f); // darken the light a bit to fit the scene
		cubeShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

		glm::mat4 view{ 1.0f };
		view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(camera.fov, (GLfloat)window->width / (GLfloat)window->height, 0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(cubeShader.ID, "model");
		GLint viewLoc = glGetUniformLocation(cubeShader.ID, "view");
		GLint projLoc = glGetUniformLocation(cubeShader.ID, "projection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glm::mat4 model{ 1.0f };
		glBindVertexArray(vao);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);


		//��������� ���-��������
		lightShader.Use();



		modelLoc = glGetUniformLocation(lightShader.ID, "model");
		viewLoc = glGetUniformLocation(lightShader.ID, "view");
		projLoc = glGetUniformLocation(lightShader.ID, "projection");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		model = glm::mat4{ 1.0f };
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);


		//renderer of testCube
		testShader.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glActiveTexture(GL_TEXTURE1);

		modelLoc = glGetUniformLocation(testShader.ID, "model");
		viewLoc = glGetUniformLocation(testShader.ID, "view");
		projLoc = glGetUniformLocation(testShader.ID, "projection");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		model = glm::mat4{ 1.0f };
		model = glm::translate(model, glm::vec3{ 1.0f });
		model = glm::scale(model, glm::vec3(100.9f));
		model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(testVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);



		//����������� ����� 
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//��������� �� ������� �������� � ����� �� �����
		glfwSwapBuffers(window->ReturnWindow());
	}
	//������� �������
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	//�������� ����
	glfwTerminate();
	return 0;
};




