#pragma once

#define GLEW_STATIC
#include <glew.h>

#define GLM_FORCE_SWIZZLE
#include "glm/ext.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader {

    public:

    //Идентификатор программы
    unsigned int ID;

    //Получаем исходный код шейдера из filePath
    string      vertexCode;
    string      fragmentCode;
    ifstream    vShaderFile;
    ifstream    fShaderFile;

    GLuint      vertex;
    GLuint      fragment;
    GLint       success;
    GLchar      infoLog[512];

    Shader (const GLchar* vertexPath, const GLchar* fragmentPath);

    void Use();

    void setBool  (const std::string& name, bool value) const;

    void setInt   (const std::string& name, int value) const;

    void setFloat (const std::string& name, float value) const;

    void setVec2  (const std::string& name, const glm::vec2& value) const;

    void setVec2  (const std::string& name, float x, float y) const;

    void setVec3  (const std::string& name, const glm::vec3& value) const;

    void setVec3  (const std::string& name, float x, float y, float z) const;

    void setVec4  (const std::string& name, const glm::vec4& value) const;

    void setVec4  (const std::string& name, float x, float y, float z, float w) const;

    void setMat2  (const std::string& name, const glm::mat2& mat) const;

    void setMat3  (const std::string& name, const glm::mat3& mat) const;

    void setMat4  (const std::string& name, const glm::mat4& mat) const;
};

