#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::string Shader::readFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        throw std::runtime_error("Shader: failed to open file " + path);
    }

    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

unsigned int Shader::compile(unsigned int type, const std::string& source, const std::string& debugName)
{
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char log[1024];
        glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
        std::cerr << "Shader compile error (" << debugName << "):\n" << log << std::endl;
    }

    return shader;
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertexSrc = readFile(vertexPath);
    std::string fragmentSrc = readFile(fragmentPath);

    unsigned int vertexShader = compile(GL_VERTEX_SHADER, vertexSrc, vertexPath);
    unsigned int fragmentShader = compile(GL_FRAGMENT_SHADER, fragmentSrc, fragmentPath);

    m_id = glCreateProgram();
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    int success;
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        char log[1024];
        glGetProgramInfoLog(m_id, sizeof(log), nullptr, log);
        std::cerr << "Shader link error:\n" << log << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(m_id);
}

void Shader::use() const
{
    glUseProgram(m_id);
}

void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}
