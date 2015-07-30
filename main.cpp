#include <QCoreApplication>

#include "AutoTest.h"
#include <QDebug>
#include "coords.h"
#include <iostream>

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

    //Coords c1(38,53,20.9,-77,2,56.4);

    //  Coords c1(38.889139,-77.049,0); //lat, long, heigh
    //  Coords c1(29.779139,-68.150000,1.00);
    //  Coords c1(20.189169, -48.150000, 12.00);
    //  Coords c1(10.189169, 88.150000, 37.00);
        Coords c1(80.189169, 27.150000, 230.0);

    double x=c1.getCartX();
    double y=c1.getCartY();
    double z=c1.getCartZ();

    cout<<"x: "<<x<<"y: "<<y<<"z: "<<z<<endl;

    return failures;
 }
//#endif



