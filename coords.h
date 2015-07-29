#ifndef COORDS_H
#define COORDS_H

#include <proj_api.h>
#include <iostream>
#include<iomanip>
#include <cmath>
#include <stdio.h>

//!  Trieda Coords
/*!
 Trieda Coords predstavuje suradnice radaroveho systemu a ich prevod do roznych typov.
*/

class Coords
{
private:

    double latitudeD,latitudeM,latitudeS;
    double longitudeD,longitudeM,longitudeS;

    double decLatitude;
    double decLongitude;
    double decHeightAboveGeoid=0;


    double cartX;
    double cartY;
    double cartZ;

public:
    Coords();
    Coords(double,double,double,double,double,double);


    //setters
    void setLatitudeD(double);
    void setLatitudeM(double);
    void setLatitudeS(double);
    void setLongitudeD(double);
    void setLongitudeM(double);
    void setLongitudeS(double);


    void setDecLatitude(double);
    void setDecLongitude(double);

    void setCartX(double);
    void setCartY(double);
    void setCartZ(double);

   //getters
    double getLatitudeD(void);
    double getLatitudeM(void);
    double getLatitudeS(void);
    double getLongitudeD(void);
    double getLongitudeM(void);
    double getLongitudeS(void);

    double getDecLatitude();
    double getDecLongitude();
    double getDecHeightAboveGeoid();

    double getCartX(void);
    double getCartY(void);
    double getCartZ(void);
    // degre to decimal

    void DegToDec(void);

};

#endif // COORDS_H
