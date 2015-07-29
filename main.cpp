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

    Coords c1(38,53,20.9,-77,2,56.4);
    cout<<"aaaa"<<endl;
    double x=c1.getCartX();
    double y=c1.getCartY();
    double z=c1.getCartZ();

    cout<<"x: "<<x<<"y: "<<y<<"z: "<<z<<endl;

    return failures;
 }
//#endif



