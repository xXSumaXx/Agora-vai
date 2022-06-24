#include "Interpretador.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

Interpretador::Interpretador(){
}

std::vector<FiguraGeometrica*> Interpretador:: parse(std::string filename){
    std::vector<FiguraGeometrica*> figuras;
    std::string s, token;
    std::ifstream fin;
    std::stringstream ss;
    fin.open(filename.c_str());

    if(!fin.is_open()){
        std::cout << "Falha:" << filename << " Arquivo inexistente" << std::endl;
        exit(0);
    }

    while(fin.good()){
        getline(fin,s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;

            if(ss.good()){
                if(token.compare("dim") == 0){
                    ss >> dx >> dy >> dz;
                } else if(token.compare("putVoxel") == 0){
                    int x0,y0,z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figuras.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));

                } else if(token.compare("cutVoxel") == 0){
                    int x0,y0,z0;
                    ss >> x0 >> y0 >> z0;
                    figuras.push_back(new CutVoxel(x0,y0,z0));

                } else if(token.compare("putBox") == 0){
                    int x0,y0,z0,x1,y1,z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figuras.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

                } else if(token.compare("cutBox") == 0){
                    int x0,y0,z0,x1,y1,z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figuras.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

                } else if(token.compare("putSphere") == 0){
                    int xc,yc,zc,radius;
                    ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
                    figuras.push_back(new PutSphere(xc,yc,zc,radius,r,g,b,a));

                } else if(token.compare("cutSphere") == 0){
                    int xc,yc,zc,radius;
                    ss >> xc >> yc >> zc >> radius;
                    figuras.push_back(new CutSphere(xc,yc,zc,radius));

                } else if(token.compare("putEllipsoid") == 0){
                    int xc,yc,zc,rx,ry,rz;
                    ss >> xc >> yc >> zc >> rx >> ry>> rz >> r >> g >> b >> a;
                    figuras.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));

                } else if(token.compare("cutEllipsoid") == 0){
                    int xc,yc,zc,rx,ry,rz;
                    ss >> xc >> yc >> zc >> rx >> ry>> rz;
                    figuras.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));

                }
            }
        }
    }
    fin.close();
    std::cout << "Deu bom!" << std::endl;
    return(figuras);
}

int Interpretador::getDx(){
    return dx;
}

int Interpretador::getDy(){
    return dy;
}

int Interpretador::getDz(){
    return dz;
}

