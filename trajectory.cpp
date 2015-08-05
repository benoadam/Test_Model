#include "trajectory.h"
#include <vector>
/** @file trajectory.cpp
* @brief Tento subor obsahuje definicie konstruktoru a metod calcDegreePath calcLengthPath triedy Trajectory predstavujuce suradnice radaroveho systemu.

* Mozny obsahlejsi popis na vice
* radek.
*/
using namespace std;
using namespace GeographicLib;


Trajectory::Trajectory(Coords startPoint, Coords endPoint,double quantumStep){
    this->startPoint=startPoint;
    this->endPoint=endPoint;
    this->quantumStep=quantumStep;

}

void Trajectory::calcLengthPath(void){

    try {
        const Geodesic& geod = Geodesic::WGS84();

        double a12 = geod.Inverse(this->startPoint.getDecLatitude(), this->startPoint.getDecLongitude(),this->endPoint.getDecLatitude(), this->endPoint.getDecLongitude(), this->distanceLengthStartToEnd, this->azimuthStartEndPointFromStart,this->azimuthStartEndPointFormEnd);

        const GeographicLib::GeodesicLine line(geod,this->startPoint.getDecLatitude(),this->startPoint.getDecLongitude(), this->azimuthStartEndPointFromStart);
        this->numberOfInervals = int(ceil(this->distanceLengthStartToEnd / this->quantumStep));
        this->distanceStartToNthPoint=this->distanceLengthStartToEnd/this->numberOfInervals;
        for (int i = 0; i <=this->numberOfInervals; ++i) {
            double lat,lon;
            line.Position(i*this->distanceStartToNthPoint,lat,lon);
            this->nThPoint.setDecLatitude(lat);
            this->nThPoint.setDecLongitude(lon);
            this->pathLength.push_back(this->nThPoint);
        }
        vypis(this->pathLength);

    }    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
        //return 1;
    }
}

void Trajectory::calcDegreePath(void){

    try {
        const Geodesic& geod = Geodesic::WGS84();

        this->distanceDegreeStartToEnd = geod.Inverse(this->startPoint.getDecLatitude(), this->startPoint.getDecLongitude(),this->endPoint.getDecLatitude(), this->endPoint.getDecLongitude(), this->distanceLengthStartToEnd, this->azimuthStartEndPointFromStart,this->azimuthStartEndPointFormEnd);

        const GeographicLib::GeodesicLine line(geod,this->startPoint.getDecLatitude(),this->startPoint.getDecLongitude(), this->azimuthStartEndPointFromStart);
        this->numberOfInervals = int(ceil(this->distanceLengthStartToEnd / this->quantumStep));
        this->distanceStartToNthPoint=this->distanceDegreeStartToEnd/this->numberOfInervals;
        for (int i = 0; i < this->numberOfInervals; ++i) {
            double lat,lon;
            line.ArcPosition(i*this->distanceStartToNthPoint,lat,lon);
            this->nThPoint.setDecLatitude(lat);
            this->nThPoint.setDecLongitude(lon);
            this->pathDegree.push_back(this->nThPoint);
        }
        vypis(this->pathDegree);

    }    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
        //return 1;
    }
}

void Trajectory::vypis(vector<Coords>vector){
    cout<<"============================================================================="<<endl;
    cout<<"Star point: "<<this->startPoint.getDecLatitude()<<","<<this->startPoint.getDecLongitude()<<" | End point: "<<this->endPoint.getDecLatitude()<<","<<this->endPoint.getDecLongitude()<<" | Distance: "<<this->distanceLengthStartToEnd<<" |"<<endl;
    cout<<"============================================================================="<<endl;
    for (int i = 0; i < vector.size(); ++i) {
        cout<<i<<": "<<vector[i].getDecLatitude()<<","<<vector[i].getDecLongitude()<<" ||"<<endl;
    }
}
