#include <QCoreApplication>

#include "AutoTest.h"
#include <QDebug>
#include "coords.h"
#include "radar.h"
#include <iostream>
#include "trajectory.h"
//#if 1
//// This is all you need to run all the tests
//TEST_MAIN
//#else
// Or supply your own main function

using namespace std;
int main(int argc, char *argv[])
{


    int failures = AutoTest::run(argc, argv);
    if (failures == 0)
    {
    qDebug() << "ALL TESTS PASSED";
    }
    else
    {
    qDebug() << failures << " TESTS FAILED!";
    }

    //  Coords c1(38,53,20.9,-77,2,56.4);
    //  Coords c1(38.889139,-77.049,0); //lat, long, heigh


//    double x=c1.getCartX();
//    double y=c1.getCartY();
//    double z=c1.getCartZ();
//    cout<<"x: "<<x<<"y: "<<y<<"z: "<<z<<endl;

//    Coords deg__mssr__veljav(48,15,38.56,17,9,47.83);
//    Coords deg_mssr__bucen(48,18,19.95,19,52,14.61);
//    Radar r1(deg__mssr__veljav,deg_mssr__bucen);
//    double dist=r1.getDistance();
//    cout<<"r1 dist:"<<dist<<endl;

//    Coords dec__mssr__veljav(48.2607111,17.1632861,0);
//    Coords dec_mssr__bucen(48.3055417,19.8707250,0);
//    Radar r2(dec__mssr__veljav,dec_mssr__bucen);
//    double dist2=r2.getDistance();
//    cout<<"r2 dist2:"<<dist2<<endl;

    Coords ruzomberok(49.078611,19.308333,0);
    Coords bystrica(48.738611,19.156944,0);
    Coords kosice(48.72,21.258056,0);
    double azimut=104.9;
    double qutatumStep=10000;


    Trajectory t1(ruzomberok,kosice,azimut,qutatumStep);
    t1.calcPath();

    return failures;
 }
//#endif



