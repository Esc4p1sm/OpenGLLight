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

	//Инициализация	
	void Window::initializationGLFW()
	{
		//Инициализация GLFW
		glfwInit();
		//Настройка GLFW
		//Задается минимальная требуемая версия OpenGL. 
		//Мажорная 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
		//Минорная
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
		//Установка профайла для которого создается контекст
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//Выключение возможности изменения размера окна
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	//Создание окна
	int Window::creatWindow()
	{
		//Создание объекта окна
		window = glfwCreateWindow(width, height, nameOfWindow, nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			//Уничтожение окна и курсоров
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		//Создание объекта glew для управления функциями OpenGL
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize Glew" << std::endl;

			return -1;
		}

		/*Прежде чем мы начнем что - либо отрисовывать нам надо еще кое что сделать. Нам нужно сообщить OpenGL размер отрисовываемого окна,
		чтобы OpenGL знал, как мы хотим отображать данные и координаты относительно окна.
		Мы можем установить эти значения через функцию glViewport.*/
		glfwGetFramebufferSize(window, &width, &height);

		/*Первые 2 аргумента функции glViewport — это позиция нижнего левого угла окна.
		Третий и четвертый — это ширина и высота отрисовываемого окна в px, которые мы получаем напрямую из GLFW.
		Вместо того, чтобы руками задавать значения ширины и высоты в 800 и 600 соответственно мы будем использовать значения из GLFW,
		поскольку такой алгоритм также работает и на экранах с большим DPI(как Apple Retina).*/
		glViewport(0, 0, width, height);

		//Проверка глубины
		glEnable(GL_DEPTH_TEST);
		//Захват курсора
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		//Закрыть окно
		//glfwSetKeyCallback(window, KeyCallback);

	}

	GLFWwindow* Window::ret() { return window; }

	Window::~Window() { delete window; }
