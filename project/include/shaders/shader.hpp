#pragma once
#include <sstream>
#include <string>
#include <fstream>

namespace shaders {
  const char* readShaders(std::string filename);
  int createShaders(const char* shaderSrc, unsigned int Shadertype);
  int createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader, unsigned int geometryShader);
}
