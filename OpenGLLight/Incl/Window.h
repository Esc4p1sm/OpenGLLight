#pragma once

#include <glfw3.h>

class Window {

	private:

		GLFWwindow*		_window;
		int				_majorVersion, _minorVersion;
		const char*		_nameOfWindow;

	public:

		int width, height;

		//Конструктор окна
		Window (int majorVersion = 3, int minorVersion = 3, int w = 800, int h = 600, const char* nameOfWindow = "Window");

		//Инициализация	
		void InitializationGLFW();

		//Создание окна
		int CreatWindow() noexcept;

		//Получение объекта окна	
		GLFWwindow* GetWindow();

		~Window();
};