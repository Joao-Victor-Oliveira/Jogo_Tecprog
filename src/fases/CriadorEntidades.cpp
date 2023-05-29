#include <fases/CriadorEntidades.h>
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/inimigos/Atirador.h>

using namespace Fases;
using namespace Listas;

CriadorEntidades::CriadorEntidades(){}

CriadorEntidades::~CriadorEntidades(){printf("Foram criadas %d entidades\n", num_entidades);}

void CriadorEntidades::add(ListaEntidade<Entidades::Inimigo>* li ,Entidades::Inimigo* i){
    num_entidades++;
    if(!li || !i)
        throw std::invalid_argument("argumento nulo");
    else
        li->adicionar(i);
}

void CriadorEntidades::add(Listas::ListaEntidade<Entidades::Obstaculo>* lo,Entidades::Obstaculo* o){
    num_entidades++;
    if(!lo || !o)
        throw std::invalid_argument("argumento nulo");
    else
        lo->adicionar(o);
}

void CriadorEntidades::criarLimites(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41]){
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1000,705),sf::Vector2f(2000,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(15,1000),sf::Vector2f(30,2000)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1275,1000),sf::Vector2f(30,2000)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1000,15),sf::Vector2f(2000,30)));

    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux == '*'){}
            else{
                if(aux == '#')
                    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(j*30+45,i*30+45),sf::Vector2f(30,30)));
            }
    }
}

void CriadorEntidades::listaProjeteis(Listas::ListaEntidade<Entidades::Projetil>* lp){
    Entidades::Atirador::setListaProjetil(lp);
}

/* Exemplo
void Criarinimigos(ListaEntidade<Entidades::Inimigo>* li){
    add(li,new inimigo1);
    for(int i=0,i<5,i++){add(li,new inimigo2);}
}

CriarObjetos analogo a CriarInimigos
*/