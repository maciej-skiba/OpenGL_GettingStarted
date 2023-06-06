#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "functions.hpp" 

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "cant load glew" << std::endl;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    unsigned int VAO1;
    unsigned int VAO2;
    
    unsigned int leftTriangleProgram = CreateTriangleProgram(VAO1, true);
    unsigned int rightTriangleProgram = CreateTriangleProgram(VAO2, false);

    // -- uncomment to see the outline only --
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        //processInput(window);
        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(leftTriangleProgram);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(rightTriangleProgram);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}