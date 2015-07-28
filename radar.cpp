#include "radar.h"

Radar::Radar(Coords selfPoz, Coords otherPoz)
{
    this->selfPoz=selfPoz;
    this->otherPoz=otherPoz;
}

double Radar::getDistance(void){
    const Geodesic& geod = Geodesic::WGS84();
    geod.Inverse(this->selfPoz.getDecLatitude(),this->selfPoz.getDecLongitude(),this->otherPoz.getDecLatitude(),this->otherPoz.getDecLongitude(),this->directDistance);
    return this->directDistance;
}

//double Radar::getDistance(Coords otherPoz)

