#ifndef PLY_EXPLORER
#define PLY_EXPLORER

#include "Application.hpp"
#include "GL/glew.h"

class PlyExplorer : public Application {
public:
    PlyExplorer();
protected:
    void loop() override;
private:
    // TODO: create shader class
    // VBO, VAO
    GLuint VBO, VAO;
};

#endif