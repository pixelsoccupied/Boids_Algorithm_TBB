//
// Created by Np on 2017-10-28.
//

#include "Draw.h"
bool Draw::boidLeft = true;
bool Draw::boidDown = true;

void Draw::drawFlocks(std::vector<Flock *> &flock) {


    for(int i=0; i <flock.size(); i++){
        for(int j=0; j<flock[i]->getFlock().size(); j++){
            Boid *boid = flock[i]->getFlock()[j];

            Eigen::Vector2f  moveAwayFromFlock ;
            moveAwayFromFlock(0)=0;
            moveAwayFromFlock(1)=0;

            moveAwayFromFlock = moveAway(boid, flock[(i+1)%flock.size()]);


            Eigen::Vector2f velocity = boid->getVelocity();


            float r = fmod(boid->getR() , 1);
            float g = fmod(boid->getG() , 1);
            float b = fmod (boid->getB(),1);

            float x = boid->getPosition()(0);
            float y = boid->getPosition()(1);


            if (boidLeft) {
                if (x > (-1 + 0.01)){
                    x -= velocity.norm();
                }
                else {
                    boidLeft = false;
                }
            }
            else {
                if (x < (1-0.01)) {
                    x += velocity.norm();
                }
                else {
                    boidLeft = true;
                }
            }

            //move up n down
            if (boidDown) {
                if (y > (-1+0.01)) {
                    y -= velocity.norm();
                }
                else {
                    boidDown = false;
                }
            }
            else {
                if (y < (1 - 0.01)) {
                    y += velocity.norm();
                }
                else {
                    boidDown = true;
                }
            }






/*




            float result = (atan (abs(velocity(1))/abs(velocity(0)))) + (270 * (3.141592653589793238462643383279502884197169399375105820/180));

            float degrees = (result * (180 /3.141592653589793238462643383279502884197169399375105820));

            glPushMatrix();
            glTranslatef(x, y, 0);
            glRotatef(degrees, 0.0, 0.0, 1.0);
            glTranslatef(-x, -y, 0);


*/

            glBegin(GL_TRIANGLES);
            glColor3f(r, g, b);
            //glColor3f();
            glVertex2f(0  + x + moveAwayFromFlock(0) ,0.01 + y + moveAwayFromFlock(1));
            glVertex2f(-0.01 + x + moveAwayFromFlock(0),  -0.01 +y + moveAwayFromFlock(1));
            glVertex2f(0.01 + x + moveAwayFromFlock(0), -0.01 + y + moveAwayFromFlock(1)) ;

            glEnd();

            glPopMatrix();

            boidLeft = true;
            boidDown = true;
        }
    }





}

Eigen::Vector2f Draw::moveAway(Boid *pBoid, Flock *&pFlock) {

    /*

    PROCEDURE tend_to_place(Boid b)
    Vector place

    RETURN (place - b.position) / 100
    END PROCEDURE
*/


    Eigen::Vector2f place, newPosition;
    place(0)=0;
    place(1)=0;
    newPosition(0) = 0;
    newPosition(1) = 0;

    place = pFlock->getAveragePositionOfFlock();

    newPosition(0) =(-1) * ((place(0) - pBoid->getPosition()(0))/100);
    newPosition(1) =(-1) * ((place(1) - pBoid->getPosition()(1))/100);



    return newPosition;
}
