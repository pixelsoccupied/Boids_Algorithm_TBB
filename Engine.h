//
// Created by Np on 2017-10-21.
//

#ifndef BOID_ALGORITHM_TBB_ENGINE_H
#define BOID_ALGORITHM_TBB_ENGINE_H

#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include "Flock.h"


class Engine {
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    // static float getDT();

    Engine();

    Engine(const std::vector<Flock *> &flock);

    ~Engine();

    bool initialize(char* windowTitle);

    void update();
    void render();

    static double limitFPS ;

    double lastTime = glfwGetTime(), timer = lastTime;
    double changeInTime = 0, currentTime = 0;
    int frames = 0 , updates = 0;

    // bool init = true;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

    static GLFWwindow *getWindow();

    static void setWindow(GLFWwindow *window);

public:
    static GLFWwindow* window;
    std::vector<Flock*> flock;

};




#endif //BOID_ALGORITHM_TBB_ENGINE_H
