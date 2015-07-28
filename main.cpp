#include <QCoreApplication>

#include "AutoTest.h"
#include <QDebug>

//#if 1
//// This is all you need to run all the tests
//TEST_MAIN
//#else
// Or supply your own main function

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
    return failures;
 }
//#endif


main(int argc, char **argv) {
     projPJ pj_merc, pj_latlong;
     double x, y;

     if (!(pj_merc = pj_init_plus("+proj=merc +ellps=clrk66 +lat_ts=33")) )
        exit(1);
     if (!(pj_latlong = pj_init_plus("+proj=latlong +ellps=clrk66")) )
        exit(1);
     while (scanf("%lf %lf", &x, &y) == 2) {
        x *= DEG_TO_RAD;
        y *= DEG_TO_RAD;
        p = pj_transform(pj_latlong, pj_merc, 1, 1, &x, &y, NULL );
        printf("%.2f\t%.2f\n", x, y);
     }
     exit(0);
}
