#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "Interpretador.h"

int main(){
    Sculptor *Dino;
    Interpretador tradutor;
    std::vector<FiguraGeometrica*> figuras;
    figuras = tradutor.parse("sculptor.txt");
    Dino = new Sculptor(tradutor.getDx(), tradutor.getDy(), tradutor.getDz());
    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*Dino);
    }
    Dino -> writeOFF((char*)"Dino.off");
    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }
    delete Dino;
    return 0;
}
