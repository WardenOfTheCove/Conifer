#include <fstream>
#include <iostream>
#include <string>
#include <stddef.h>
#include <gladlib/glad.h>
#include "shader.hpp"

const char* shaders::readShaders(std::string filename) {
    //Create input filestream shaderFile
    std::ifstream shaderFile;
    //Create string
    std::string shaderSource;
    //Create stringstream shaderStringFile
    std::stringstream shaderStringFile;
    //Open the file filename in the input filestream shaderFile
    shaderFile.open(filename);
    //Take the read buffer of the input filestream shaderFile and pass it to stringstream shaderStringFile
    shaderStringFile >> shaderFile.rdbuf();
    //Create a string out of the stringstream shaderStringFile and set shaderSource to it
    shaderSource = shaderStringFile.str();
    //Make shaderSource as a C string to create the shader
    const char* shader = shaderSource.c_str();
    //Return shader
    return shader;
}

int shaders::createShaders(const char* shaderSrc, unsigned int shaderTypes) {
    //Create shader variable
    unsigned int x_shader;
    //Find what type of shader to make
    switch(shaderTypes) {
        case 0:
            x_shader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case 1:
            x_shader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        case 2:
            x_shader = glCreateShader(GL_GEOMETRY_SHADER);
            break;
    }
    //Get the source for the shader and link it
    glShaderSource(x_shader, 1, &shaderSrc, NULL);
    //Compile the shader
    glCompileShader(x_shader);
    //Return the compiled shader
    return x_shader;
}

int shaders::createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader, unsigned int geometryShader) {
    //Create a program
    unsigned int shaderProgram = glCreateProgram();
    //Attach the shaders to the program
    glAttachShader(vertexShader, shaderProgram);
    glAttachShader(fragmentShader, shaderProgram);
    glAttachShader(geometryShader, shaderProgram);
    //Link the program
    glLinkProgram(shaderProgram);
    //Delete the shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(geometryShader);
    //Return the program
    return shaderProgram;
}
