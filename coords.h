#ifndef COORDS_H
#define COORDS_H

#include <iostream>
#include<iomanip>
#include <cmath>

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


    void setDecLatitude(double decLatitude);
    void setDecLongitude(double decLongitude);

   //getters
    double getLatitudeD(void);
    double getLatitudeM(void);
    double getLatitudeS(void);
    double getLongitudeD(void);
    double getLongitudeM(void);
    double getLongitudeS(void);

    double getDecLatitude();
    double getDecLongitude();

    // degre to decimal

    void DegToDec(void);

};

#endif // COORDS_H
