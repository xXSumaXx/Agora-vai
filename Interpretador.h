#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "FiguraGeometrica.h"

class Interpretador{
    public:
        Interpretador();
        std::vector<FiguraGeometrica*> parse(std::string filename);
        int getDx();
        int getDy();
        int getDz();

    protected:
        int dx,dy,dz;
        float r,g,b,a;
    private:
};

#endif
