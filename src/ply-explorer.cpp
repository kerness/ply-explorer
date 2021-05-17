#include "ply-explorer.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define SHADER_DIR "../shader/"
#include <iostream>


PlyExplorer::PlyExplorer()
    :Application() {}




void PlyExplorer::loop() {

    if(glfwWindowShouldClose(getWindow()))
        exit();

    glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

}


