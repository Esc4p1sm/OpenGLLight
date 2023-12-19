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

//Инициализация	
void Window::InitializationGLFW()
{
	//Инициализация GLFW
	glfwInit();
	
	//Мажорная версия
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _majorVersion);
	//Минорная версия
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _minorVersion);
	//Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Выключение возможности изменения размера окна
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

//Создание окна
int Window::CreatWindow() noexcept
{
	//Создание объекта окна
	_window = glfwCreateWindow(width, height, _nameOfWindow, nullptr, nullptr);

	if (_window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		//Уничтожение окна и курсоров
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

	//Создание объекта glew для управления функциями OpenGL
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize Glew" << std::endl;

		return -1;
	}

	//Буфер размера окна
	glfwGetFramebufferSize(_window, &width, &height);

	glViewport(0, 0, width, height);

	//Проверка глубины
	glEnable(GL_DEPTH_TEST);
	//Захват курсора
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//Закрыть окно
	//glfwSetKeyCallback(window, KeyCallback);

}

GLFWwindow* Window::GetWindow() { return _window; }

Window::~Window() { delete _window; }

