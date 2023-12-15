#pragma once

#include <glfw3.h>
#include "Camera.h"

Camera::Camera(glm::vec3 position, 
               glm::vec3 up,
               GLfloat yaw, 
               GLfloat pitch) :
               front(glm::vec3(0.0f, 0.0f, -1.0f)), 
               movementSpeed(SPEED), 
               mouseSensitivity(SENSITIVTY), 
               fov(ZOOM)
{
    this->position = position;
    this->worldUp =  up;
    this->yaw =      yaw;
    this->pitch =    pitch;

    _UpdateCameraVectors();
}
// ����������� �� ���������� ����������
Camera::Camera(GLfloat posX, 
               GLfloat posY, 
               GLfloat posZ, 
               GLfloat upX, 
               GLfloat upY, 
               GLfloat upZ, 
               GLfloat yaw, 
               GLfloat pitch) :
               front(glm::vec3(0.0f, 0.0f, -1.0f)), 
               movementSpeed(SPEED), 
               mouseSensitivity(SENSITIVTY), 
               fov(ZOOM)
{
    position =    glm::vec3(posX, posY, posZ);
    worldUp =     glm::vec3(upX, upY, upZ);
    this->yaw =   yaw;
    this->pitch = pitch;

    _UpdateCameraVectors();
}

// ���������� ������� ����, ����������� � �������������� ����� Eular � ������� LookAt
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

// ������������ ����, ���������� � ����� ������� �����, �������� ����������. 
// ��������� ������� �������� � ���� ������������, ������������� ������� (����� �������������� ��� �� ������� ������)
void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = movementSpeed * deltaTime;

    if (direction == FORWARD)   { position += front * velocity; }

    if (direction == BACKWARD)  { position -= front * velocity; }

    if (direction == LEFT)      { position -= right * velocity; }

    if (direction == RIGHT)     { position += right * velocity; }
}

// ������������ ����, ���������� �� ������� ����� � ������� ����. ������� �������� �������� ��� � ����������� x, ��� � � ����������� y.
void Camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // ���������, ��� ��� ���������� ������ ���� ����� �� ����������������
    if (constrainPitch)
    {
        if (pitch > 89.0f)  { pitch = 89.0f; }

        if (pitch < -89.0f) { pitch = -89.0f; }
    }

    // �������� ��������, ������ � ������� �������, ��������� ����������� ������� ��������        
    _UpdateCameraVectors();
}

// ������������ ����, ���������� �� ������� ��������� �������� ����. ��������� ���� ������ �� ������������ ��� ��������    
void Camera::ProcessMouseScroll(GLfloat yoffset)
{
    if (fov >= 1.0f && fov <= 45.0f) { fov -= yoffset; }

    if (fov <= 1.0f)  { fov = 1.0f; }

    if (fov >= 45.0f) { fov = 45.0f; }
}

// ��������� �������� ������ �� (�����������) ����� ������ ������
void Camera::_UpdateCameraVectors()
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

