#pragma once
#include  "Camera.h"
#include  <iostream>

//Создание объекта камеры
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
// Время, прошедшее между последним и текущим кадром
GLfloat deltaTime = 0.0f;
// Время вывода последнего кадра
GLfloat lastFrame = 0.0f;
//Массив для ключей нажатия клавиш
bool keys[1024];
bool firstMouse = true;
GLfloat lastX;
GLfloat lastY;

class Input
{
	public:
	
	Input(int width=width,int height=height)
	{
		 lastX = width / 2.0;
		 lastY = height / 2.0;
	}
	void do_movement()
	{
		// Контроль камеры
		if (keys[GLFW_KEY_W])
			camera.ProcessKeyboard(FORWARD, deltaTime);
		if (keys[GLFW_KEY_S])
			camera.ProcessKeyboard(BACKWARD, deltaTime);
		if (keys[GLFW_KEY_A])
			camera.ProcessKeyboard(LEFT, deltaTime);
		if (keys[GLFW_KEY_D])
			camera.ProcessKeyboard(RIGHT, deltaTime);
	}

	 static void mouse_callback(GLFWwindow* window, double xpos, double ypos)
	 {

		//Возвращение курсора в начальную позицию, чтобы не было резкого движения
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		GLfloat xoffset = xpos - lastX;
		GLfloat yoffset = lastY - ypos; // Обратный порядок вычитания потому что оконные Y-координаты возрастают с верху вниз  
		lastX = xpos;
		lastY = ypos;

		camera.ProcessMouseMovement(xoffset, yoffset);
	 }

	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		camera.ProcessMouseScroll(yoffset);

	}

	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;

		// когда пользователь нажимает esc, мы устанавливаем свойство windowshouldclose в true, 
		// и приложение после этого закроется
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}
	

};