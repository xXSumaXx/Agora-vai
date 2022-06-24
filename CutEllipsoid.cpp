#include "CutEllipsoid.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int xc_, int yc_, int zc_, int rx_, int ry_, int rz_){
    this -> xcenter = xc_;
    this -> ycenter = yc_;
    this -> zcenter = zc_;
    this -> rx = rx_;
    this -> ry = ry_;
    this -> rz = rz_;
}

void CutEllipsoid::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    double dist;
    if(rx == 0){
        for(int j = ycenter - ry; j <= ycenter + ry; j++){
            for(int k = zcenter - rz; k <= zcenter + rz; k++){
                dist = pow(j - ycenter, 2)/pow(ry, 2) + pow(k - zcenter, 2)/pow(rz, 2);
                if(dist <= 1){
                    s.cutVoxel(xcenter,j,k);
                }
             }
         }
    }else if(ry == 0){
        for(int i = xcenter - rx; i <= xcenter + rx; i++){
            for(int k = zcenter - rz; k <= zcenter + rz; k++){
                dist = pow(i - xcenter, 2)/pow(rx, 2) + pow(k - zcenter, 2)/pow(rz, 2);
                if(dist <= 1){
                    s.cutVoxel(i,ycenter,k);
                }
            }
         }

    }else if(rz == 0){
        for(int i = xcenter - rx; i <= xcenter + rx; i++){
            for(int j = ycenter - ry; j <= ycenter + ry; j++){
                dist = pow(i - xcenter, 2)/pow(rx, 2) + pow(j - ycenter, 2)/pow(ry, 2);
                if(dist <= 1){
                    s.cutVoxel(i,j,zcenter);
                }
            }
         }
    }else{
        for(int i = xcenter - rx; i < xcenter + rx; i++){
            for(int j = ycenter - ry; j < ycenter + ry; j++){
                for(int k = zcenter - rz; k < zcenter + rz; k++){
                    dist = pow(i - xcenter,2)/pow(rx, 2) + pow(j - ycenter,2)/pow(ry, 2) + pow(k - zcenter,2)/pow(rz, 2);
                    if (dist <= 1){
                        s.cutVoxel(i,j,k);
                    }
                }
            }
        }
    }
}
