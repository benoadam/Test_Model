#include "trajectory.h"
#include <vector>
using namespace std;
using namespace GeographicLib;

Trajectory::Trajectory(Coords startPoint, Coords endPoint, double azimut,double quantumStep){
    this->startPoint=startPoint;
    this->endPoint=endPoint;
    this->azimut=azimut;
    this->quantumStep=quantumStep;

}

void Trajectory::calcPath(void){

    const Geodesic& geod = Geodesic::WGS84();


    geod.Inverse(this->startPoint.getDecLatitude(), this->startPoint.getDecLongitude(),this->endPoint.getDecLatitude(), this->endPoint.getDecLongitude(), this->distance);
    cout<<"distance: "<<this->distance<<endl;


    cout<<this->endPoint.getDecLatitude()<<" , "<<this->endPoint.getDecLongitude()<<endl;

     for (int i = 0; i < this->distance; i=i+this->quantumStep) {
         geod.Direct(this->startPoint.getDecLatitude(), this->startPoint.getDecLongitude(), this->azimut, i, this->lat, this->longt);
            this->endPoint.setDecLatitude(lat);
            this->endPoint.setDecLongitude(longt);



            path.push_back(endPoint);
            cout<<this->lat<<" , "<<this->longt<<endl;

    }
     cout<<"======================================="<<endl;
     for (int i = 0; i < path.size(); ++i) {
         cout<<this->path[i].getDecLatitude()<<","<<path[i].getDecLongitude()<<endl;
     }
}
