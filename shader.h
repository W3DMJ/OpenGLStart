//
// Created by w3dmj on 8/24/21.
//

#ifndef INC_02_OPENGLSTART_SHADER_H
#define INC_02_OPENGLSTART_SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& fileName);
    void Bind();

    virtual ~Shader();

protected:
private:
    static const unsigned int NUM_SHADERS = 2;

    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, GLenum shaderType);

    GLuint mProgram;
    GLuint mShaders[NUM_SHADERS];
};


#endif //INC_02_OPENGLSTART_SHADER_H
