#include <iostream>
#include "tbb/task_group.h"
#include "Flock.h"
#include "Engine.h"

using namespace tbb;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Flock* flock = new Flock(20);
    Flock* flock1 = new Flock(20);
    Flock* flock2 = new Flock(20);
    Flock* flock3 = new Flock(20);
    Flock* flock4 = new Flock(20);
    Flock* flock5 = new Flock(20);

    /*  Flock flock5(20);
      Flock flock6(10);
      Flock flock7(14);
      Flock flock8(16);*/

    std::vector <Flock*> flocks= {flock, flock1, flock2, flock3, flock4, flock5};

    //flock.randomisePosition();

    Engine* engine = new Engine(flocks);
    engine->initialize("Boid");




    while(!glfwWindowShouldClose(engine->getWindow())){
        engine->update();
        engine->render();
    }

    //delete(flocks);
    delete(engine);


    std::cout << "This program ends heree" << std::endl;


    return 0;

}