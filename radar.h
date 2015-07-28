#ifndef RADAR_H
#define RADAR_H

#include "coords.h"
#include <iostream>
#include <GeographicLib/Geodesic.hpp>

using namespace std;
using namespace GeographicLib;

class Radar
{
public:

    double directDistance;
    Coords selfPoz;
    Coords otherPoz;


    Radar(Coords,Coords);
  double getDistance(void);
   //void getDistance(Coords);

};

#endif // RADAR_H
