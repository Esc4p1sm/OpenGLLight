
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include "Renderer.h"
#include <SOIL.h>

const char* vertexPath =		"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderFall.vs";
const char* fragPath =			"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderFall.frag";
const char* vertexLightPath =	"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderLamp.vs";
const char* fragLightPath =		"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderLamp.frag";

const char* testVerShader =		"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/TestShader/TestShader.vs";
const char* testFragShader =	"D:/Program Files/repos/Project/OpenGlProject/OpenGlProject/Shaders/TestShader/TestShaderFrag.frag";

Window *window=new Window { 3,3,1000,900,"LightWindow" };

Input input{ 800,600,glm::vec3{1.0f,1.0f,1.0f} };

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main()
{
	//Инициализация glfw
	window->InitializationGLFW();

	//Создание окна
	window->CreatWindow();
	//Шейдер куба-падение 
	Shader cubeShader(vertexPath, fragPath);
	//Шейдер куб-источник
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

	constexpr glm::vec3 cubePositions[] =
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
	constexpr GLuint indices[] = {  // Note that we start from 0!
	   0, 1, 3, // First Triangle
	   1, 2, 3  // Second Triangle
	};

	GLuint vbo;

	//Куб падения света
	GLuint vao;
	Renderer* fall = new Renderer{};
	fall->GenerateBuffers(vertices, &vbo, &vao);
	fall->AddAtribb(0,3,GL_FLOAT,0,(8*sizeof(float)),nullptr);
	fall->AddAtribb(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	fall->AddAtribb(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	
	//Куб в качестве источника света
	GLuint lightVAO;
	Renderer* light = new Renderer{};
	light->GenerateBuffers(&vbo,&lightVAO);
	light->AddAtribb(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), nullptr);
	
	//testCube
	GLuint  testVao{};
	Renderer*testCube=new Renderer{};
	testCube->GenerateBuffers(vertices,&vbo,&testVao);
	testCube->AddAtribb(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), nullptr);
	testCube->AddAtribb(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	Renderer::AtribbUnbind();

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
	
	
	
	//Игровой цикл
	while (!glfwWindowShouldClose(window->GetWindow()))
	{
		GLfloat	currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		//cout <<"delta:" << deltaTime << endl <<"lastFrame:" << lastFrame << endl <<"currentframe:" << currentFrame << endl;

		//Проверка вызова событий
		glfwPollEvents();

		//Управление камерой
		input.DoMovement();
		glfwSetCursorPosCallback(window->GetWindow(), Input::MouseCallback);

		//Проверка глубины
		glEnable(GL_DEPTH_TEST);

		//Захват курсора
		glfwSetInputMode(window->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		//Закрыть окно
		glfwSetKeyCallback(window->GetWindow(), Input::KeyCallBack);
		glfwSetScrollCallback(window->GetWindow(), Input::ScrollCallback);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		//Очистка буффера
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Изменение со временем
		lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0;
		lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;

		//Отрисовка куб-падение
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
		cubeShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f); 
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
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		
		fall->Render(GL_TRIANGLES,vao,36);

		//Отрисовка куб-источник
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

		light->Render(GL_TRIANGLES,lightVAO,36);

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
		model = glm::scale(model, glm::vec3(20.0f));
		//model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		testCube->Render(GL_TRIANGLES,testVao,36);
		
		//Отображение линий 
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//Отрисовка на текущей итерации и вывод на экран
		glfwSwapBuffers(window->GetWindow());
	}
	//Очистка буферов
	Renderer::DeleteVao(1, &vao);
	Renderer::DeleteVbo(1, &vbo);
	Renderer::DeleteVao(1, &testVao);
	Renderer::DeleteVao(1, &lightVAO);
	
	//Удаление окна
	glfwTerminate();
	return 0;
};




