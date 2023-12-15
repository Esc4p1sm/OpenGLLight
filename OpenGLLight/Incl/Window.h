#pragma once
#define GLEW_STATIC

#include <glew.h>
#include <glfw3.h>
//�������� ���� �� ���������
int width, height;

class Window {

private:

	GLFWwindow* window;
	int majorVersion, minorVersion;
	const char* nameOfWindow;

public:


	Window(int majorVersion = 3, int minorVersion = 3, int w = 800, int h = 600, const char* nameOfWindow = "Window");

	//�������������	
	void initializationGLFW();
	//�������� ����
	int creatWindow();

	GLFWwindow* ret();

	~Window();
};