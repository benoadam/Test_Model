#ifndef TESTCOORD_H
#define TESTCOORD_H

#include "AutoTest.h"
#include "coords.h"


class TestCoord:public QObject
{
    Q_OBJECT
public:
    TestCoord();
private slots:
    void test_DegreeToDecimal();
    void test_WGS_To_ECEF();


};

DECLARE_TEST(TestCoord)
#endif // TESTCOORD_H
