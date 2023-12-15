#pragma once
#define GLEW_STATIC

#include <glew.h>
#include <glfw3.h>
//Значения окна по умолчанию
int width, height;

class Window {

private:

	GLFWwindow* window;
	int majorVersion, minorVersion;
	const char* nameOfWindow;

public:


	Window(int majorVersion = 3, int minorVersion = 3, int w = 800, int h = 600, const char* nameOfWindow = "Window");

	//Инициализация	
	void initializationGLFW();
	//Создание окна
	int creatWindow();

	GLFWwindow* ret();

	~Window();
};