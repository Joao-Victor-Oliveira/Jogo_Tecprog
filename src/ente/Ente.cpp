#include "../../include/ente/Ente.h"

using namespace gerenciadores;
int Ente::counter(0);

GerenciadorGrafico* Ente::gg = nullptr;


Ente::Ente():id(counter++){
}

Ente::~Ente(){

}

const int Ente::getID()const{
    return id;
}

void Ente::setGG(GerenciadorGrafico* g){
    gg = g;
}