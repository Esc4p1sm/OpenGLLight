#pragma once

#include "Input.h"
//#include "Camera.h"



Input::Input(Camera myCamera, int width, int height)
	{
		camera = myCamera;
		lastX = width / 2.0;
		lastY = height / 2.0;
	}

	void Input::DoMovement()
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

	 void Input::MouseCallback(GLFWwindow* window, double xpos, double ypos)
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

	 void Input::ScrollCallback(GLFWwindow* window,double xoffset, double yoffset)
	{
		camera.ProcessMouseScroll(yoffset);

	}

	 void Input::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode)
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


