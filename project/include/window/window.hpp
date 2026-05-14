#pragma once
#include <gladlib/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace window {
  int init(int width, int height, const char name[]);
  void fbscb(GLFWwindow* window, int width, int height);
}
