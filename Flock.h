//
// Created by Np on 2017-10-21.
//

#ifndef BOID_ALGORITHM_TBB_FLOCK_H
#define BOID_ALGORITHM_TBB_FLOCK_H

#include <tbb/task.h>


#include <vector>
#include "Boid.h"
#include <Eigen/Dense>
#include <thread>
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"



class Flock {
private:
    std::vector <Boid*> flock;
    static float rgb;
    Eigen::Vector2f averagePositionOfFlock;

    static int IDgen;
    int ID;
public:


    Flock(int numOfBoids);

    virtual ~Flock();

    const std::vector<Boid *> &getFlock() const;

    void setFlock(const std::vector<Boid *> &flock);

    void randomisePosition();


    void updateBoid();

    Eigen::Vector2f cohesion(Boid *pBoid);

    Eigen::Vector2f separation(Boid *pBoid);

    Eigen::Vector2f alignment(Boid *boid);

    //supporting methods
    void limitSpeed(Boid *boid);
    Eigen::Vector2f boundPosition(Boid *boid);


    const Eigen::Vector2f &getAveragePositionOfFlock() const;


    void launchParallelFor(Boid *&pBoid, int j, Eigen::Vector2f matrix);
};


#endif //BOID_ALGORITHM_TBB_FLOCK_H
