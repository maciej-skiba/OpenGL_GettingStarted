#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void DrawTriangle();
void CheckShaderCompilation(unsigned int vertexShader);
void CheckShaderLink(unsigned int shaderProgram);