
#include <iostream>
#include <math.h>

#include "robot.hh"

using std::cout;
using std::endl;

const double goal_x = 20.0;
const double goal_y = 0.0;
bool done = false;

void
callback(Robot* robot)
{
    /*
    cout << endl;
    cout << "robot x =" << robot->pos_x << endl;
    cout << "robot y =" << robot->pos_y << endl;
    */
    double dx = goal_x - robot->pos_x;
    double dy = goal_y - robot->pos_y;
    if (abs(dx) < 0.75 && abs(dy) < 0.75) {
        cout << "we win!" << endl;
        robot->set_vel(0.0);
        robot->set_turn(0.0);
        robot->done();
        return;
    }

    bool turn = false;

    for (LaserHit hit : robot->hits) {
        if (hit.range < 2) {
            if (hit.angle < 0.78 && -0.78 < hit.angle) {
                turn = true;
            }
        }
    }

    if (turn) {
        robot->set_vel(6.0);
        robot->set_turn(0.5);
    }
    else {
        robot->set_vel(30.0);
	double dist_1 = goal_x - robot->pos_x;
	double dist_2 = goal_y - robot->pos_y;
	if (robot->pos_t > atan2(dist_2, dist_1))
	{
		robot->set_turn(0.2);
	}
	else
	{
		robot->set_turn(-0.2);
	}
    }
}

int
main(int argc, char* argv[])
{
    cout << "making robot" << endl;
    Robot robot(argc, argv, callback);
    robot.do_stuff();

    return 0;
}
