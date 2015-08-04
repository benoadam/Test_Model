#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include <iostream>
#include <exception>
#include <GeographicLib/Geodesic.hpp>
#include <GeographicLib/Constants.hpp>
#include "coords.h"
#include <vector>

 using namespace std;
using namespace GeographicLib;

class Trajectory
{
public:
    Coords startPoint;
    Coords endPoint;
    double distance;
    double lat;
    double longt;
    double quantumStep;
    double azimut;
    vector<Coords> path;

    Trajectory(Coords,Coords,double,double);
    void calcPath(void);
};

#endif // TRAJECTORY_H
