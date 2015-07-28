#include "radar.h"

/**
 * Konstruktor triedy Radar obsahujuci vlastnu a vzdialenu suradnicu.
 *
 * Konstruktor ma ako vstupne argumenty dva parametre typu Coords.
 *
 * @param arraySize   size of dynamically allocated array
 * @return            nothing
 */
Radar::Radar(Coords selfPoz, Coords otherPoz)
{
    this->selfPoz=selfPoz;
    this->otherPoz=otherPoz;
}

/**
 *Funkcia getDistance triedy Radar pocitajuca vzdialenost.
 *
 * Funkcia pocita vzdialenost pomocou kniznice GeographicLib vytvorenu pre geograficke vypocty.
*/
double Radar::getDistance(void){
    const Geodesic& geod = Geodesic::WGS84();
    geod.Inverse(this->selfPoz.getDecLatitude(),this->selfPoz.getDecLongitude(),this->otherPoz.getDecLatitude(),this->otherPoz.getDecLongitude(),this->directDistance);
    return this->directDistance;
}

//double Radar::getDistance(Coords otherPoz)

