#ifndef TESTRADAR_H
#define TESTRADAR_H
#include "AutoTest.h"
#include "coords.h"
#include "radar.h"
#include <math.h>
#include<iomanip>
#include <iostream>

using namespace std;

class TestRadar:public QObject
{
        Q_OBJECT
public:
    TestRadar();
private slots:
    void test_getDistanc();
};
DECLARE_TEST(TestRadar)
#endif // TESTRADAR_H
