#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

    unsigned int id() const { return m_id; }

private:
    unsigned int m_id;

    static std::string readFile(const std::string& path);
    static unsigned int compile(unsigned int type, const std::string& source, const std::string& debugName);
};
