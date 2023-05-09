#include <listas/ListaInimigos.h>
using namespace Listas;

ListaInimigos::ListaInimigos(){

}

ListaInimigos::~ListaInimigos(){

}

void ListaInimigos::adicionar(Entidades::Inimigo* elem){
    inimigos.push_back(elem);
}
void ListaInimigos::remover(const int indice){
    if(!inimigos[indice])
        inimigos.remover(inimigos[indice]);
}

Entidades::Inimigo* ListaInimigos::operator[](const int i){
        return inimigos[i];
}

void ListaInimigos::percorrer(){
    int tam = inimigos.getTamanho();
    for(int i=0;i<tam;i++){
        inimigos[i]->executar();
    }
}

void ListaInimigos::draw(){
    int tam = inimigos.getTamanho();
    for(int i=0;i<tam;i++){
        inimigos[i]->draw();
    }
}