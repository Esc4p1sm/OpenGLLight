#pragma once
#include <iostream>
#define GLEW_STATIC



//�������� ���� �� ���������
 int width, height;

class Window {
	
private:

	GLFWwindow* window;
	int majorVersion, minorVersion; 
	const char* nameOfWindow;
	
public:
	 

	 Window( int majorVersion=3, int minorVersion=3, int w=800, int h=600, const char* nameOfWindow="Window"):window(nullptr),majorVersion(majorVersion), minorVersion(minorVersion),nameOfWindow(nameOfWindow)
	 {
		 width = w;
		 height = h;
	 }
	 
	//�������������	
	void initializationGLFW()
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
	int creatWindow()
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
			cout << "Failed to initialize Glew" << endl;

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
	
	GLFWwindow* ret() { return window; }
};
