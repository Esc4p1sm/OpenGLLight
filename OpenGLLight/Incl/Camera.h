#pragma once

#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement 
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const GLfloat YAW =        -90.0f;
const GLfloat PITCH =       0.0f;
const GLfloat SPEED =       3.0f;
const GLfloat SENSITIVTY =  0.25f;
const GLfloat ZOOM =        45.0f;

class Camera
{
    public:

        // Camera Attributes
        glm::vec3       position;
        glm::vec3       front;
        glm::vec3       up;
        glm::vec3       right;
        glm::vec3       worldUp;

        // Углы Эйлера
        GLfloat         yaw;
        GLfloat         pitch;

        // Опции камеры
        GLfloat         movementSpeed;
        GLfloat         mouseSensitivity;
        GLfloat         fov;

    
    Camera (glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
            GLfloat yaw = YAW, 
            GLfloat pitch = PITCH);

    // Конструктор со скалярными значениями
    Camera (GLfloat posX, 
            GLfloat posY, 
            GLfloat posZ, 
            GLfloat upX, 
            GLfloat upY, 
            GLfloat upZ, 
            GLfloat yaw, 
            GLfloat pitch);

    // Возвращает матрицу вида, вычисленную с использованием углов Eular и матрицы LookAt
    glm::mat4 GetViewMatrix();

    // Обрабатывает ввод, полученный с любой системы ввода, подобной клавиатуре. 
    // Принимает входной параметр в виде перечисления, определенного камерой (чтобы абстрагировать его от оконных систем)
    void ProcessKeyboard (Camera_Movement direction, GLfloat deltaTime);

    // Обрабатывает ввод, полученный от системы ввода с помощью мыши. Ожидает значение смещения как в направлении x, так и в направлении y.
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);

    // Обрабатывает ввод, полученный из события прокрутки колесика мыши. Требуется ввод только по вертикальной оси колесика    
    void ProcessMouseScroll(GLfloat yoffset);

private:

    // Вычисляет передний вектор по (обновленным) углам обзора камеры
    void _UpdateCameraVectors();

};