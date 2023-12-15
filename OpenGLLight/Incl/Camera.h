#pragma once

#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement 
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const GLfloat YAW =        -90.0f;
const GLfloat PITCH =       0.0f;
const GLfloat SPEED =       3.0f;
const GLfloat SENSITIVTY =  0.25f;
const GLfloat ZOOM =        45.0f;


// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
    public:

        // Camera Attributes
        glm::vec3       position;
        glm::vec3       front;
        glm::vec3       up;
        glm::vec3       right;
        glm::vec3       worldUp;

        // Eular Angles
        GLfloat         yaw;
        GLfloat         pitch;

        // Camera options
        GLfloat         movementSpeed;
        GLfloat         mouseSensitivity;
        GLfloat         fov;

    // Constructor with vectors
    Camera (glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
            GLfloat yaw = YAW, 
            GLfloat pitch = PITCH);

    // ����������� �� ���������� ����������
    Camera (GLfloat posX, 
            GLfloat posY, 
            GLfloat posZ, 
            GLfloat upX, 
            GLfloat upY, 
            GLfloat upZ, 
            GLfloat yaw, 
            GLfloat pitch);

    // ���������� ������� ����, ����������� � �������������� ����� Eular � ������� LookAt
    glm::mat4 GetViewMatrix();

    // ������������ ����, ���������� � ����� ������� �����, �������� ����������. 
    // ��������� ������� �������� � ���� ������������, ������������� ������� (����� �������������� ��� �� ������� ������)
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);

    // ������������ ����, ���������� �� ������� ����� � ������� ����. ������� �������� �������� ��� � ����������� x, ��� � � ����������� y.
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);

    // ������������ ����, ���������� �� ������� ��������� �������� ����. ��������� ���� ������ �� ������������ ��� ��������    
    void ProcessMouseScroll(GLfloat yoffset);

private:

    // ��������� �������� ������ �� (�����������) ����� ������ ������
    void _UpdateCameraVectors();
};