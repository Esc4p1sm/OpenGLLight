#pragma once

// Std. Includes
#include <vector>
#include <glm/gtc/matrix_transform.hpp>



// ���������� ��������� ��������� ��������� ����������� ������. ������������ � �������� ����������, ����� �������� ������������� ������� �����, ����������� ��� ������� �������
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.25f;
const GLfloat ZOOM = 45.0f;


// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // Camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // Eular Angles
    GLfloat Yaw;
    GLfloat Pitch;
    // Camera options
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat fov;

    // Constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw=YAW, GLfloat pitch = PITCH) : 
                Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), fov(ZOOM)
    {
        this->Position = position;
        this->WorldUp = up;
        this->Yaw = yaw;
        this->Pitch = pitch;
        this->updateCameraVectors();
    }
    // ����������� �� ���������� ����������
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : 
            Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), fov(ZOOM)
    {
        this->Position = glm::vec3(posX, posY, posZ);
        this->WorldUp = glm::vec3(upX, upY, upZ);
        this->Yaw = yaw;
        this->Pitch = pitch;
        this->updateCameraVectors();
    }

    // ���������� ������� ����, ����������� � �������������� ����� Eular � ������� LookAt
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
    }

    // ������������ ����, ���������� � ����� ������� �����, �������� ����������. 
    // ��������� ������� �������� � ���� ������������, ������������� ������� (����� �������������� ��� �� ������� ������)
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
    {
        GLfloat velocity = this->MovementSpeed * deltaTime;
        if (direction == FORWARD)
            this->Position += this->Front * velocity;
        if (direction == BACKWARD)
            this->Position -= this->Front * velocity;
        if (direction == LEFT)
            this->Position -= this->Right * velocity;
        if (direction == RIGHT)
            this->Position += this->Right * velocity;
    }

   // ������������ ����, ���������� �� ������� ����� � ������� ����. ������� �������� �������� ��� � ����������� x, ��� � � ����������� y.
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= this->MouseSensitivity;
        yoffset *= this->MouseSensitivity;

        this->Yaw += xoffset;
        this->Pitch += yoffset;


        // ���������, ��� ��� ���������� ������ ���� ����� �� ����������������
        if (constrainPitch)
        {
            if (this->Pitch > 89.0f)
                this->Pitch = 89.0f;
            if (this->Pitch < -89.0f)
                this->Pitch = -89.0f;
        }

        // �������� ��������, ������ � ������� �������, ��������� ����������� ������� ��������        
        this->updateCameraVectors();
    }

    // ������������ ����, ���������� �� ������� ��������� �������� ����. ��������� ���� ������ �� ������������ ��� ��������    
    void ProcessMouseScroll(GLfloat yoffset)
    {
        if (this->fov >= 1.0f && this->fov <= 45.0f)
            this->fov -= yoffset;
        if (this->fov <= 1.0f)
            this->fov = 1.0f;
        if (this->fov >= 45.0f)
            this->fov = 45.0f;
    }

    private:

    // ��������� �������� ������ �� (�����������) ����� ������ ������
    void updateCameraVectors()
    {
        // ��������� ����� �������� ������
        glm::vec3 front;
        front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
        front.y = sin(glm::radians(this->Pitch));
        front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
        this->Front = glm::normalize(front);
        // ����� �������� ��������� ������ � ���������� �������        
        this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));  // ������������ �������, ������ ��� �� ����� ���������� ����� � 0, ��� ������ �� �������� ����� ��� ����, ��� �������� � ���������� ��������.
        this->Up = glm::normalize(glm::cross(this->Right, this->Front));
    }
};
