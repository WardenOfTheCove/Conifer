#include <gladlib/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

void window::fbscb(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

int window::init(int width, int height, const char name[]) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  if(!glfwInit()) {
    std::cerr << "GLFW initializing error" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
  glfwMakeContextCurrent(window);
  
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "GLAD failed initialization" << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, window::fbscb);
  return 0;
}
