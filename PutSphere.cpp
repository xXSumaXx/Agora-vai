#include "PutSphere.h"

PutSphere::PutSphere(int xc_, int yc_, int zc_, int radius_, float r_, float g_, float b_, float a_){
    this -> xcenter = xc_;
    this -> ycenter = yc_;
    this -> zcenter = zc_;
    this -> radius = radius_;
    this -> r = r_;
    this -> g = g_;
    this -> b = b_;
    this -> a = a_;
}

void PutSphere::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    double dist = radius*radius;
    for(int i = xcenter - radius; i < xcenter + radius; i++){
        for(int j = ycenter - radius; j < ycenter + radius; j++){
            for(int k = zcenter - radius; k < zcenter + radius; k++){
                if(static_cast<double>(i - xcenter)*static_cast<double>(i - xcenter) + static_cast<double>(j - ycenter)*static_cast<double>(j - ycenter) + static_cast<double>(k - zcenter)*static_cast<double>(k - zcenter) < dist){
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
