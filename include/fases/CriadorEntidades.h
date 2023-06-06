#pragma once
#include <listas/ListaEntidade.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <ente/entidades/Projetil.h>

namespace Fases{

class CriadorEntidades{
    private:
    int num_entidades;    
    public:
    void add(Listas::ListaEntidade<Entidades::Inimigo>* li,Entidades::Inimigo* i);
    void add(Listas::ListaEntidade<Entidades::Obstaculo>* lo,Entidades::Obstaculo* o);
    
    CriadorEntidades();
    // muito importante ser virtual, pois irei destruir por polimorfismo
    virtual ~CriadorEntidades();

    virtual void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li)=0;                
    virtual void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo)=0;

    virtual void criarLimites(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41]);

    void listaProjeteis(Listas::ListaEntidade<Entidades::Projetil>* lp);

    void criarAtiradores(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n);
    void criarSaltadores(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n);
    void criarFantasmas(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n);

    void criarPote(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n);
    void criarEspinhos(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n);
    


    void preencher(int v[],const int max,const int quantidade);
    void sort(int v[],const int n);
};

}

