#ifndef RADAR_H
#define RADAR_H

#include "coords.h"
#include <iostream>
#include <GeographicLib/Geodesic.hpp>

using namespace std;
using namespace GeographicLib;

//!  Trieda Radar
/*!
 Trieda predstavuje model radaru.
*/
class Radar
{
public:

    const double sac=48.0; /**< SAC identifikator */
    double directDistance; /**< Vzdialenost od inej wgs suradnice */
    Coords selfPoz;        /**< Vlastna pozicia radaru */
    Coords otherPoz;       /**< Pozicia od ktorej sa pocita vzdialenost */


    Radar(Coords,Coords);
    double getDistance(void);
   //void getDistance(Coords);

};

#endif // RADAR_H
