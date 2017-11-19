//
// Created by Np on 2017-10-28.
//

#ifndef BOID_ALGORITHM_TBB_DRAW_H
#define BOID_ALGORITHM_TBB_DRAW_H


#include <vector>
#include <fcntl.h>
#include "Flock.h"
#include <GLFW/glfw3.h>


class Draw {
public:
    static bool boidLeft;
    static bool boidDown;
     static void drawFlocks(std::vector<Flock*> &flock);

    static Eigen::Vector2f moveAway(Boid *pBoid, Flock *&pFlock);
};


#endif //BOID_ALGORITHM_TBB_DRAW_H
