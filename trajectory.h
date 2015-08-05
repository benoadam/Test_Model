#ifndef TRAJECTORY_H
#define TRAJECTORY_H
/** @file trajecotry.h
* @brief Tento subor obsahuje deklaraciu triedy Trajectory, ktora pocita body najkratsej vzdialenosti medzi 2 bodmi na geoide definovanom standardom WGS84.

* Mozny obsahlejsi popis na vice
* radek.
*/

#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <iomanip>
#include <GeographicLib/Geodesic.hpp>
#include <GeographicLib/Constants.hpp>
#include <GeographicLib/GeodesicLine.hpp>
#include "coords.h"


using namespace std;
using namespace GeographicLib;
/**
 * Deklaracia triedy Trajectory
*/
class Trajectory
{
public:
    Coords startPoint;/**< Atribut obsahujuci zaciatocny bod trajektorije ktoru chceme spocitat */
    Coords endPoint;  /**< Atribut obsahujuci koncovy bod trajektorije ktoru chceme spocitat */
    Coords nThPoint; /**< Atribut obsahujuci bod ktory sa pouziva pri vypocte radu bodov predstavujucich trajektoriu */
    vector<Coords> pathLength;/**< Atribut obsahujuci vektor bodov na drahe pouzivajuc dlzkovu priamu mieru v metroch medzi jednotlivymi bodmi trajektorie*/
    vector<Coords> pathDegree;/**< Atribut obsahujuci vektor bodov na drahe pouzivajuc oblukovu mieru v stupnoch medzi jednotlivymi bodmi trajektorie*/

    double distanceLengthStartToEnd; /**< Atribut obsahujuci vzdialenost medzi zaciatocnym a koncovym bodom v metroch*/
    double distanceDegreeStartToEnd; /**< Atribut obsahujuci vzdialenost medzi zaciatocnym a koncovym bodom v stupnoch */

    double distanceStartToNthPoint;  /**< Atribut obsahujuci bod ktory sa pouziva pri vypocte P-ntheo bodu na trajektorii*/
    double lat;
    double longt;
    int numberOfInervals; /**< Atribut obsahujuci pocet intervalov na ktore sa rozdeli trajektoria v zavislosti na pozadovanom pocet bodov (hustote bodov) na nej */
    double quantumStep; /**< Atribut obsahujuci vzdialenost bodov(hustotu) ktore ma obsahovat trajektoria*/
    double azimuthStartEndPointFromStart; /**< Atribut obsahujuci azimut od zaciatocneho bodu ku koncovemu*/
    double azimuthStartEndPointFormEnd;  /**< Atribut obsahujuci azimut od koncoveho bodu ku 'priamke' na geoide . "Priamka obsahujuce zaciatocny a koncovy bod" Pozor azimuty niesu rovnake pretoze niesme na euklidovskej rovine ale na elipsoide WGS84*/

    Trajectory(Coords,Coords,double); /**< Konstruktor triedy Trajectory obsahujuci suradnice zaciatocneho a koncoveho bodu plus vzdialenost ktoru pozadujeme medzi jednotlivymi bodmi*/
    void calcLengthPath(void); /**< Metoda spocita rad suradnic v zavislosti na dlzke v metroch medzi bodmi na trajectorii definovanej zaciatocnym a koncovym bodom v konstruktore*/
    void calcDegreePath(void); /**< Metoda spocita rad suradnic v zavislosti na oblukovej dlzke v stupnoch medzi bodmi na trajectorii definovanej zaciatocnym a koncovym bodom v konstruktore*/
    void vypis(vector<Coords>); /**< Metoda vypise zadany vector WGS suradnic pozadovanej trajektorie*/
};

#endif // TRAJECTORY_H
