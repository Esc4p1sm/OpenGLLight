#pragma once

#include <glfw3.h>
#include "Camera.h"



Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) :
    front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY), fov(ZOOM)
{
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;
    this->UpdateCameraVectors();
}
// ����������� �� ���������� ����������
Camera::Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) :
    front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY), fov(ZOOM)
{
    this->position = glm::vec3(posX, posY, posZ);
    this->worldUp = glm::vec3(upX, upY, upZ);
    this->yaw = yaw;
    this->pitch = pitch;
    this->UpdateCameraVectors();
}

// ���������� ������� ����, ����������� � �������������� ����� Eular � ������� LookAt
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(this->position, this->position + this->front, this->up);
}

// ������������ ����, ���������� � ����� ������� �����, �������� ����������. 
// ��������� ������� �������� � ���� ������������, ������������� ������� (����� �������������� ��� �� ������� ������)
void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = this->movementSpeed * deltaTime;
    if (direction == FORWARD)
        this->position += this->front * velocity;
    if (direction == BACKWARD)
        this->position -= this->front * velocity;
    if (direction == LEFT)
        this->position -= this->right * velocity;
    if (direction == RIGHT)
        this->position += this->right * velocity;
}

// ������������ ����, ���������� �� ������� ����� � ������� ����. ������� �������� �������� ��� � ����������� x, ��� � � ����������� y.
void Camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= this->mouseSensitivity;
    yoffset *= this->mouseSensitivity;

    this->yaw += xoffset;
    this->pitch += yoffset;


    // ���������, ��� ��� ���������� ������ ���� ����� �� ����������������
    if (constrainPitch)
    {
        if (this->pitch > 89.0f)
            this->pitch = 89.0f;
        if (this->pitch < -89.0f)
            this->pitch = -89.0f;
    }

    // �������� ��������, ������ � ������� �������, ��������� ����������� ������� ��������        
    this->UpdateCameraVectors();
}

// ������������ ����, ���������� �� ������� ��������� �������� ����. ��������� ���� ������ �� ������������ ��� ��������    
void Camera::ProcessMouseScroll(GLfloat yoffset)
{
    if (this->fov >= 1.0f && this->fov <= 45.0f)
        this->fov -= yoffset;
    if (this->fov <= 1.0f)
        this->fov = 1.0f;
    if (this->fov >= 45.0f)
        this->fov = 45.0f;
}



// ��������� �������� ������ �� (�����������) ����� ������ ������
void Camera::UpdateCameraVectors()
{
    // ��������� ����� �������� ������
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->front = glm::normalize(front);
    // ����� �������� ��������� ������ � ���������� �������        
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));  // ������������ �������, ������ ��� �� ����� ���������� ����� � 0, ��� ������ �� �������� ����� ��� ����, ��� �������� � ���������� ��������.
    this->up = glm::normalize(glm::cross(this->right, this->front));
}

