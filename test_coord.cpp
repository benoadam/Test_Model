#include "test_coord.h"

using namespace std;

double cutNumber(double number){
    number *= 100000.;
    long i = number;
    number= (double) i / 100000.;
    return number;
}

double myRound(double value, double exp){

       double nas=pow(10,exp);
       double pom=value*nas;
       double result=((long)pom)/nas;
//     cout<<"value: "<<value<<endl;
//     cout<<" pom: "<<setprecision(15)<<pom<<endl;
//     cout<<" c: "<<c<<endl;

       return result;
}

double cutDecLat;
double cutDecLong;

Coords mssr_veljav(48,15,38.56,17,9,47.83);
Coords mssr_bucen(48,18,19.95,19,52,14.61);
Coords mie_mor(48,3,42.00,17,22,35.00);
Coords mich_p37(48,43,24.98,21,57,4.39);
Coords po_mor5(49,1,55.2701,21,18,51.607);

  Coords c1(38.889139,-77.049,0); //lat, long, heigh
  Coords c2(29.779139,-68.150000,1.00);
  Coords c3(20.189169, -48.150000, 12.00);
  Coords c4(10.189169, 88.150000, 37.00);
  Coords c5(80.189169, 27.150000, 230.0);


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

void TestCoord::test_WGS_To_ECEF(){
        double error = 0.01; // error na testovanie testu(ak pridam velku hodnotu test ma ukazat fail koli mimohranicnej hodnote)
        double delta = 0.10;//hranicna prenost s akou sa ma testovat

    QVERIFY((c1.getCartX()+error)-delta <= 1114103.15 && (c1.getCartX()+error)+delta >=1114103.15);
    QVERIFY((c1.getCartY()+error)-delta <= -4844609.77 && (c1.getCartY()+error)+delta >=-4844609.77);
    QVERIFY((c1.getCartZ()+error)-delta <= 3982745.07 && (c1.getCartZ()+error)+delta >=3982745.07);

    QVERIFY((c2.getCartX()+error)-delta <= 2062036.27 && (c2.getCartX()+error)+delta >=2062036.27);
    QVERIFY((c2.getCartY()+error)-delta <= -5142439.12 && (c2.getCartY()+error)+delta >=-5142439.12);
    QVERIFY((c2.getCartZ()+error)-delta <=  3149148.16 && (c2.getCartZ()+error)+delta >= 3149148.16);

    QVERIFY((c3.getCartX()+error)-delta <= 3995525.79 && (c3.getCartX()+error)+delta >=3995525.79);
    QVERIFY((c3.getCartY()+error)-delta <= -4460911.71 && (c3.getCartY()+error)+delta >=-4460911.71);
    QVERIFY((c3.getCartZ()+error)-delta <= 2187368.15 && (c3.getCartZ()+error)+delta >=2187368.15);

    QVERIFY((c4.getCartX()+error)-delta <= 202680.36 && (c4.getCartX()+error)+delta >=202680.36);
    QVERIFY((c4.getCartY()+error)-delta <= 6274969.46 && (c4.getCartY()+error)+delta >=6274969.46);
    QVERIFY((c4.getCartZ()+error)-delta <= 1120854.86 && (c4.getCartZ()+error)+delta >=1120854.86);

    QVERIFY((c5.getCartX()+error)-delta <= 970250.84 && (c5.getCartX()+error)+delta >=970250.84);
    QVERIFY((c5.getCartY()+error)-delta <= 497571.34 && (c5.getCartY()+error)+delta >=497571.34);
    QVERIFY((c5.getCartZ()+error)-delta <= 6263403.20 &&(c5.getCartZ()+error)+delta >=263403.20);
}




