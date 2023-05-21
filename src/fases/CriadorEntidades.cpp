#include <fases/CriadorEntidades.h>
using namespace Fases;
using namespace Listas;

CriadorEntidades::CriadorEntidades(){}

CriadorEntidades::~CriadorEntidades(){printf("Foram criadas %d entidades\n", num_entidades);}

void CriadorEntidades::add(ListaInimigos* li ,Entidades::Inimigo* i){
    num_entidades++;
    if(!li || !i)
        throw std::invalid_argument("argumento nulo");
    else
        li->adicionar(i);
}

void CriadorEntidades::add(Listas::ListaObstaculos* lo,Entidades::Obstaculo* o){
    num_entidades++;
    if(!lo || !o)
        throw std::invalid_argument("argumento nulo");
    else
        lo->adicionar(o);
}

/* Exemplo
void Criarinimigos(ListaInimigos* li){
    add(li,new inimigo1);
    for(int i=0,i<5,i++){add(li,new inimigo2);}
}

CriarObjetos analogo a CriarInimigos
*/