#pragma once

#include  "Camera.h"

glm::vec3 vectorfOfCamera;

//�������� ������� ������ (�������� �� ���������)
Camera camera { vectorfOfCamera };

// �����, ��������� ����� ��������� � ������� ������
GLfloat deltaTime = 0.0f;

// ����� ������ ���������� �����
GLfloat lastFrame = 0.0f;

//������ ��� ������ ������� ������
bool keys[1024];

bool firstMouse = true;

GLfloat lastX;
GLfloat lastY;

class Input
{
public:

	Input(int width = 800, int height = 600, glm::vec3 vector = { 0.0f, 0.0f, 3.0f })
	{
		lastX = width / 2.0;
		lastY = height / 2.0;
		vectorfOfCamera = vector;
	}

	void DoMovement()
	{
		// �������� ������
		if (keys[GLFW_KEY_W]) { camera.ProcessKeyboard(FORWARD, deltaTime); }

		if (keys[GLFW_KEY_S]) { camera.ProcessKeyboard(BACKWARD, deltaTime); }

		if (keys[GLFW_KEY_A]) { camera.ProcessKeyboard(LEFT, deltaTime); }

		if (keys[GLFW_KEY_D]) { camera.ProcessKeyboard(RIGHT, deltaTime); }
	}

	static void MouseCallback(GLFWwindow* window, double xpos, double ypos)
	{
		//����������� ������� � ��������� �������, ����� �� ���� ������� ��������
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		GLfloat xoffset = xpos - lastX;
		GLfloat yoffset = lastY - ypos; // �������� ������� ��������� ������ ��� ������� Y-���������� ���������� � ����� ����  
		lastX = xpos;
		lastY = ypos;

		camera.ProcessMouseMovement(xoffset, yoffset);
	}

	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		camera.ProcessMouseScroll(yoffset);
	}

	static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (action == GLFW_PRESS) { keys[key] = true; }

		else if (action == GLFW_RELEASE) { keys[key] = false; }

		// ����� ������������ �������� esc, �� ������������� �������� windowshouldclose � true, 
		// � ���������� ����� ����� ���������
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}

	~Input() {};
};