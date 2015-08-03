#include "test_radar.h"

using namespace std;

Coords coordsMssrVeljav(48,15,38.56,17,9,47.83);
Coords coordsMssrBucen(48,18,19.95,19,52,14.61);
Coords coordsMieMor(48,3,42.00,17,22,35.00);
Coords coordsMichP37(48,43,24.98,21,57,4.39);
Coords coordsPoMor5(49,1,55.2701,21,18,51.607);

Radar r1(coordsMssrVeljav,coordsMssrBucen);
Radar r2(coordsMssrVeljav,coordsMieMor);
Radar r3(coordsMssrVeljav,coordsMichP37);
Radar r4(coordsMssrVeljav,coordsPoMor5);

TestRadar::TestRadar(){

}

void TestRadar::test_getDistanc(){

QCOMPARE(round(r1.getDistance()),200987.0);
QCOMPARE(round(r2.getDistance()),27224.0);
QCOMPARE(round(r3.getDistance()),357552.0);
QCOMPARE(round(r4.getDistance()),317635.0);

}
