#include <Shader.h>
#include <Window.h>
#include <Input.h>

const char* vertexPath = "C:/Users/KK/source/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderFall.vs";
const char* fragPath = "C:/Users/KK/source/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderFall.frag";
const char* vertexLightPath = "C:/Users/KK/source/repos/Project/OpenGlProject/OpenGlProject/Shaders/vShaderLamp.vs";
const char* fragLightPath = "C:/Users/KK/source/repos/Project/OpenGlProject/OpenGlProject/Shaders/fShaderLamp.frag";

Window window{ 3,3,1000,900,"LightWindow" };
Input input;
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main()
{
	//������������� glfw
	window.initializationGLFW();
	//�������� ����
	window.creatWindow();
	//������ ����-������� 
	Shader cubeShader(vertexPath, fragPath);
	//������ ���-��������
	Shader lightShader(vertexLightPath, fragLightPath);

	constexpr float vertices[] = {
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

	//��� ������� �����
	GLuint vbo, vao;
	glGenVertexArrays(1,&vao);
	glGenBuffers(1,&vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,8 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	
	GLuint texture;
	int w, h;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	unsigned char* image = SOIL_load_image("C:/Users/KK/Desktop/project/container2.png", &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	//������� ����
	while (!glfwWindowShouldClose(window.ret()))
	{
		GLfloat	currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		//cout <<"delta:" << deltaTime << endl <<"lastFrame:" << lastFrame << endl <<"currentframe:" << currentFrame << endl;

		//�������� ������ �������
		glfwPollEvents();

		//���������� �������
		input.do_movement();
		glfwSetCursorPosCallback(window.ret(), Input::mouse_callback);

		//�������� �������
		glEnable(GL_DEPTH_TEST);

		//������ �������
		glfwSetInputMode(window.ret(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		//������� ����
		glfwSetKeyCallback(window.ret(), Input::keyCallBack);
		glfwSetScrollCallback(window.ret(), Input::scroll_callback);


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
		cubeShader.setInt("material.diffuse", 0);
		glActiveTexture(GL_TEXTURE1);
		cubeShader.setVec3("light.position", lightPos);
		cubeShader.setVec3("viewPos", camera.Position);
		GLint objectColorLoc = glGetUniformLocation(cubeShader.ID, "objectColor");
		GLint lightColorLoc = glGetUniformLocation(cubeShader.ID, "lightColor");
		GLint lightPosition = glGetUniformLocation(cubeShader.ID, "lightPos");
		GLint viewPosLoc = glGetUniformLocation(cubeShader.ID, "viewPos");
		glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
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

		glm::mat4 view{1.0f};
		view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(camera.fov, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(cubeShader.ID, "model");
		GLint viewLoc = glGetUniformLocation(cubeShader.ID, "view");
		GLint projLoc = glGetUniformLocation(cubeShader.ID, "projection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(vao);
		glm::mat4 model{1.0f};
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

		model = glm::mat4{1.0f};
		model = glm::translate(model,lightPos);
		model = glm::scale(model, glm::vec3(0.2f)); 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		//����������� ����� 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//��������� �� ������� �������� � ����� �� �����
		glfwSwapBuffers(window.ret());
	}
	//������� �������
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	//�������� ����
	glfwTerminate();
	return 0;
};




