#include <listas/ListaObstaculos.h>
using namespace Listas;

ListaObstaculos::ListaObstaculos(){

}

ListaObstaculos::~ListaObstaculos(){

}

void ListaObstaculos::adicionar(Entidades::Obstaculo* elem){
    obstaculos.push_back(elem);
}

void ListaObstaculos::remover(const int indice){
    if(!obstaculos[indice])
        obstaculos.remover(obstaculos[indice]);
}

Entidades::Obstaculo* ListaObstaculos::operator[](const int i){
        return obstaculos[i];
}

void ListaObstaculos::percorrer(){
    int tam = obstaculos.getTamanho();
    for(int i=0;i<tam;i++){
        obstaculos[i]->executar();
    }
}

void ListaObstaculos::draw(){
    int tam = obstaculos.getTamanho();
    for(int i=0;i<tam;i++){
        obstaculos[i]->draw();
    }
}

bool ListaObstaculos::vazia(){return obstaculos.empty();}

const int ListaObstaculos::getTamanho(){return obstaculos.getTamanho();}