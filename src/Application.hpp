#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>

struct GLFWwindow;

class Application {
public:
    Application();
    void run();
    int getWidth() const;
    int getHeight() const;
    GLFWwindow* getWindow() const;
    void exit();

protected:
    virtual void loop();

private:
    enum State { stateReady, stateRun, stateExit };
    State state;

    GLFWwindow* window;

    // window attributes
    int width;
    int height;
    std::string title;
};

#endif 