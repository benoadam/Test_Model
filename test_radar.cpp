#include "test_radar.h"

using namespace std;

Coords mssr__veljav(48,15,38.56,17,9,47.83);
Coords mssr__bucen(48,18,19.95,19,52,14.61);
Coords mie__mor(48,3,42.00,17,22,35.00);
Coords mich__p37(48,43,24.98,21,57,4.39);
Coords po__mor5(49,1,55.2701,21,18,51.607);

Radar r1(mssr__veljav,mssr__bucen);


TestRadar::TestRadar(){}

void TestRadar::test_getDistanc(){

QCOMPARE(round(r1.getDistance()),200987.0);
}
