#include "Application.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>


Application::Application() : width(640), height(480), title("PLY EXPLORER") {
    
    // GLFW init
    if(!glfwInit()) {
        throw std::runtime_error("Could not init GLFW.");
    }

    // openGL settings
    int major = 3;
    int minor = 2;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if(!window) {
        glfwTerminate();
        throw std::runtime_error("Could not create a window.");
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    if(status != GLEW_OK) {
        glfwTerminate();
        throw std::runtime_error("Could not initialize GLEW.");
    }


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

}
GLFWwindow *Application::getWindow() const {
    return window;
}

int Application::getHeight() const {
    return height;
}

int Application::getWidth() const {
    return width;
}

void Application::loop() {
    std::cout << "loop";
}

void Application::run() {
    state = stateRun;
    std::cout << "stateRun";
    glfwMakeContextCurrent(window);

    while (state == stateRun) {
        loop();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Application::exit() {
    state = stateExit;
}


