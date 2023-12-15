#pragma once

//#define GLEW_STATIC
//#include <glew.h>
//#include <glfw3.h>
#include "Window.h"
#include <iostream>

Window::Window(int majorVersion,
				int minorVersion,
				int w,
				int h,
				const char* nameOfWindow) :
				window(nullptr),
				majorVersion(majorVersion),
				minorVersion(minorVersion),
				nameOfWindow(nameOfWindow)
	{
		width = w;
		height = h;
	}

	//�������������	
	void Window::initializationGLFW()
	{
		//������������� GLFW
		glfwInit();
		//��������� GLFW
		//�������� ����������� ��������� ������ OpenGL. 
		//�������� 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
		//��������
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
		//��������� �������� ��� �������� ��������� ��������
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//���������� ����������� ��������� ������� ����
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	//�������� ����
	int Window::creatWindow()
	{
		//�������� ������� ����
		window = glfwCreateWindow(width, height, nameOfWindow, nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			//����������� ���� � ��������
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		//�������� ������� glew ��� ���������� ��������� OpenGL
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize Glew" << std::endl;

			return -1;
		}

		/*������ ��� �� ������ ��� - ���� ������������ ��� ���� ��� ��� ��� �������. ��� ����� �������� OpenGL ������ ��������������� ����,
		����� OpenGL ����, ��� �� ����� ���������� ������ � ���������� ������������ ����.
		�� ����� ���������� ��� �������� ����� ������� glViewport.*/
		glfwGetFramebufferSize(window, &width, &height);

		/*������ 2 ��������� ������� glViewport � ��� ������� ������� ������ ���� ����.
		������ � ��������� � ��� ������ � ������ ��������������� ���� � px, ������� �� �������� �������� �� GLFW.
		������ ����, ����� ������ �������� �������� ������ � ������ � 800 � 600 �������������� �� ����� ������������ �������� �� GLFW,
		��������� ����� �������� ����� �������� � �� ������� � ������� DPI(��� Apple Retina).*/
		glViewport(0, 0, width, height);

		//�������� �������
		glEnable(GL_DEPTH_TEST);
		//������ �������
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		//������� ����
		//glfwSetKeyCallback(window, KeyCallback);

	}

	GLFWwindow* Window::ret() { return window; }

	Window::~Window() { delete window; }
