#pragma once

#include <glew.h>
#include "Window.h"
#include <iostream>
 
Window::Window(int majorVersion,
				int minorVersion,
				int w,
				int h,
				const char* nameOfWindow) :
				_window(nullptr),
				_majorVersion(majorVersion),
				_minorVersion(minorVersion),
				_nameOfWindow(nameOfWindow)
{
	width = w;
	height = h;
}

//�������������	
void Window::InitializationGLFW()
{
	//������������� GLFW
	glfwInit();
	//��������� GLFW
	//�������� ����������� ��������� ������ OpenGL. 
	//�������� 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _majorVersion);
	//��������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _minorVersion);
	//��������� �������� ��� �������� ��������� ��������
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//���������� ����������� ��������� ������� ����
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

//�������� ����
int Window::CreatWindow()
{
	//�������� ������� ����
	_window = glfwCreateWindow(width, height, _nameOfWindow, nullptr, nullptr);
	if (_window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		//����������� ���� � ��������
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

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
	glfwGetFramebufferSize(_window, &width, &height);

	/*������ 2 ��������� ������� glViewport � ��� ������� ������� ������ ���� ����.
	������ � ��������� � ��� ������ � ������ ��������������� ���� � px, ������� �� �������� �������� �� GLFW.
	������ ����, ����� ������ �������� �������� ������ � ������ � 800 � 600 �������������� �� ����� ������������ �������� �� GLFW,
	��������� ����� �������� ����� �������� � �� ������� � ������� DPI(��� Apple Retina).*/
	glViewport(0, 0, width, height);

	//�������� �������
	glEnable(GL_DEPTH_TEST);
	//������ �������
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//������� ����
	//glfwSetKeyCallback(window, KeyCallback);

}

GLFWwindow* Window::ReturnWindow() { return _window; }

Window::~Window() { delete _window; }
