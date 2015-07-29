#include "test_coord.h"

using namespace std;

double cutNumber(double number){
    number *= 100000.;
    int i = number;
    number= (double) i / 100000.;
    return number;
}

double cutDecLat;
double cutDecLong;

Coords mssr_veljav(48,15,38.56,17,9,47.83);
Coords mssr_bucen(48,18,19.95,19,52,14.61);
Coords mie_mor(48,3,42.00,17,22,35.00);
Coords mich_p37(48,43,24.98,21,57,4.39);
Coords po_mor5(49,1,55.2701,21,18,51.607);


TestCoord::TestCoord(){}

void TestCoord::test_DegreeToDecimal(){


    cutDecLat=cutNumber(mssr_veljav.getDecLatitude());
    cutDecLong=cutNumber(mssr_veljav.getDecLongitude());

    QCOMPARE(cutDecLat,48.26071);
    QCOMPARE(cutDecLong,17.16328);

    cutDecLat=cutNumber(mssr_bucen.getDecLatitude());
    cutDecLong=cutNumber(mssr_bucen.getDecLongitude());

    QCOMPARE(cutDecLat,48.30554);
    QCOMPARE(cutDecLong,19.87072);

    cutDecLat=cutNumber(mie_mor.getDecLatitude());
    cutDecLong=cutNumber(mie_mor.getDecLongitude());

    QCOMPARE(cutDecLat,48.06166);
    QCOMPARE(cutDecLong,17.37638);

    cutDecLat=cutNumber(mich_p37.getDecLatitude());
    cutDecLong=cutNumber(mich_p37.getDecLongitude());

    QCOMPARE(cutDecLat,48.72360);
    QCOMPARE(cutDecLong,21.95121);

    cutDecLat=cutNumber(po_mor5.getDecLatitude());
    cutDecLong=cutNumber(po_mor5.getDecLongitude());

    QCOMPARE(cutDecLat,49.03201);
    QCOMPARE(cutDecLong,21.31433);
}




