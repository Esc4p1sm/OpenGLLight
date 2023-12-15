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
// Конструктор со скалярными значениями
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

// Возвращает матрицу вида, вычисленную с использованием углов Eular и матрицы LookAt
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

// Обрабатывает ввод, полученный с любой системы ввода, подобной клавиатуре. 
// Принимает входной параметр в виде перечисления, определенного камерой (чтобы абстрагировать его от оконных систем)
void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = movementSpeed * deltaTime;

    if (direction == FORWARD)   { position += front * velocity; }

    if (direction == BACKWARD)  { position -= front * velocity; }

    if (direction == LEFT)      { position -= right * velocity; }

    if (direction == RIGHT)     { position += right * velocity; }
}

// Обрабатывает ввод, полученный от системы ввода с помощью мыши. Ожидает значение смещения как в направлении x, так и в направлении y.
void Camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // Убедитесь, что при превышении высоты тона экран не переворачивается
    if (constrainPitch)
    {
        if (pitch > 89.0f)  { pitch = 89.0f; }

        if (pitch < -89.0f) { pitch = -89.0f; }
    }

    // Обновите передний, правый и верхний векторы, используя обновленные угловые значения        
    _UpdateCameraVectors();
}

// Обрабатывает ввод, полученный из события прокрутки колесика мыши. Требуется ввод только по вертикальной оси колесика    
void Camera::ProcessMouseScroll(GLfloat yoffset)
{
    if (fov >= 1.0f && fov <= 45.0f) { fov -= yoffset; }

    if (fov <= 1.0f)  { fov = 1.0f; }

    if (fov >= 45.0f) { fov = 45.0f; }
}

// Вычисляет передний вектор по (обновленным) углам обзора камеры
void Camera::_UpdateCameraVectors()
{
    // Вычислить новый передний вектор
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->front = glm::normalize(front);

    // Также повторно вычислите правый и восходящий векторы        
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));  // Нормализуйте векторы, потому что их длина становится ближе к 0, чем больше вы смотрите вверх или вниз, что приводит к замедлению движения.
    this->up = glm::normalize(glm::cross(this->right, this->front));
}

