#include "coords.h"
/** @file coords.h
* @brief Tento subor obsahuje konstruktor a metody triedy Coords predstavujuce suradnice radaroveho systemu.

* Mozny obsahlejsi popis na vice
* radek.
*/
using namespace std;

template<typename T>
T sgn(T n){
    if (n < 0) return -1;
    if (n > 0) return 1;
    return 0;
}

/**
 * Implicitny konstruktor
*/
Coords::Coords(){}

/**
 * Konstruktor triedy Coords obsahujuci vstupne suradnice v decimalnych stupnoch.
 *
*/
Coords::Coords(double decLatitude, double decLongitude, double decHeightAboveGeoid ){
    this->decLatitude=decLatitude;
    this->decLongitude=decLongitude;
    this->decHeightAboveGeoid=decHeightAboveGeoid;

    calcDegToDec(); //prevod z WGS do Kartezianskej sustavy
}

/**
 * Konstruktor triedy Coords obsahujuci vstupne suradnice v stupnoch minutach sekundach.
 *
 * Konstruktor ma ako vstupne argumenty sestticu cisel predstavujucich stupne minuty a sekundy zemepisnej sirky a dlzky.
 *
 * @param arraySize   size of dynamically allocated array
 * @return            nothing
 */

Coords::Coords(double latitudeD,double latitudeM,double latitudeS,double longitudeD,double longitudeM,double longitudeS)
{
    this->latitudeD=latitudeD; /**< Informacia o stupni zemepisnej sirky */
    this->latitudeM=latitudeM; /**< Informacia o minute zemepisnej sirky  */
    this->latitudeS=latitudeS; /**< Informacia o sekunde zemepisnej sirky */
    this->longitudeD=longitudeD; /**< Informacia o stupni zemepisnej dlzky */
    this->longitudeM=longitudeM; /**< Informacia o stupni zemepisnej dlzky */
    this->longitudeS=longitudeS; /**< Informacia o stupni zemepisnej dlzky */

    this->decLatitude=sgn(this->latitudeD)* (abs(this->latitudeD) + (this->latitudeM / 60.0) + (this->latitudeS / 3600.0)); /**< Prevod zemepisnej sirky do dekadickych stupnov */
    this->decLongitude=sgn(this->longitudeD)* (abs(this->longitudeD) + (this->longitudeM / 60.0) + (this->longitudeS / 3600.0)); /**< Prevod zemepisnej dlzky do dekadickych stupnov */

    calcDegToDec(); //prevod z WGS do Kartezianskej sustavy
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

double Coords::getDecLatitude(){return this->decLatitude; }
double Coords::getDecLongitude(){return this->decLongitude; }
double Coords::getDecHeightAboveGeoid(){return this->decHeightAboveGeoid; }

double Coords::getCartX(void){return this->cartX;}
double Coords::getCartY(void){return this->cartY;}
double Coords::getCartZ(void){return this->cartZ;}

// degree to decimal

void Coords::calcDegToDec(){

    projPJ pj_latlong, pj_geocent;
    int p;

    if (!(pj_latlong = pj_init_plus("+proj=latlong +ellps=WGS84 +a=6378137 +b=6356752.3142")) )
        exit(1);
    if (!(pj_geocent = pj_init_plus("+proj=geocent +ellps=WGS84 +a=6378137 +b=6356752.3142")) )
        exit(1);

    this->cartX=this->decLongitude;
    this->cartY=this->decLatitude;
    this->cartZ=this->decHeightAboveGeoid;

    this->cartX *= DEG_TO_RAD;
    this->cartY *= DEG_TO_RAD;

    p = pj_transform(pj_latlong, pj_geocent, 1, 1, &this->cartX, &this->cartY, &this->cartZ);
}
