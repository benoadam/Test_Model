#include "coords.h"

using namespace std;

template<typename T>
T sgn(T n){
    if (n < 0) return -1;
    if (n > 0) return 1;
    return 0;
    }

Coords::Coords(){}
Coords::Coords(double latitudeD,double latitudeM,double latitudeS,double longitudeD,double longitudeM,double longitudeS)
{
    this->latitudeD=latitudeD;
    this->latitudeM=latitudeM;
    this->latitudeS=latitudeS;
    this->longitudeD=longitudeD;
    this->longitudeM=longitudeM;
    this->longitudeS=longitudeS;

    this->decLatitude=sgn(this->latitudeD)* (abs(this->latitudeD) + (this->latitudeM / 60.0) + (this->latitudeS / 3600.0));
    this->decLongitude=sgn(this->longitudeD)* (abs(this->longitudeD) + (this->longitudeM / 60.0) + (this->longitudeS / 3600.0));
}

//setters
void Coords::setLatitudeD(double latitudeD) { this->latitudeD = latitudeD; }
void Coords::setLatitudeM(double latitudeM) { this->latitudeM = latitudeM; }
void Coords::setLatitudeS(double latitudeS) { this->latitudeS = latitudeS; }
void Coords::setLongitudeD(double longitudeD) { this->longitudeD = longitudeD; }
void Coords::setLongitudeM(double longitudeM) { this->longitudeM = longitudeM; }
void Coords::setLongitudeS(double longitudeS) { this->longitudeS = longitudeS; }

void Coords::setDecLatitude(double decLatitude){this->decLatitude=decLatitude;}
void Coords::setDecLongitude(double decLongitude){this->decLongitude=decLongitude;}

//getters
double Coords::getLatitudeD(){ return this->latitudeD; }
double Coords::getLatitudeM(){ return this->latitudeM; }
double Coords::getLatitudeS(){ return this->latitudeS; }
double Coords::getLongitudeD(){ return this->longitudeD; }
double Coords::getLongitudeM(){ return this->longitudeM; }
double Coords::getLongitudeS(){ return this->longitudeS; }

double Coords::getDecLatitude(){return this->decLatitude;}
double Coords::getDecLongitude(){return this->decLongitude;}

 // degree to decimal

void Coords::DegToDec(void){
}
