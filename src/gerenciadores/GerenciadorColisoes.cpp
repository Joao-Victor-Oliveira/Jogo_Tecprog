#include <gerenciadores/GerenciadorColisoes.h>
using namespace Gerenciadores;


GerenciadorColisoes::GerenciadorColisoes():pli(NULL),plo(NULL){}
GerenciadorColisoes::~GerenciadorColisoes(){}
    

void GerenciadorColisoes::setLista(Listas::ListaInimigos* li){pli=li;}
void GerenciadorColisoes::setLista(Listas::ListaObstaculos* lo){plo=0;}
void GerenciadorColisoes::setLista(Listas::ListaInimigos* li,Listas::ListaObstaculos* lo){pli=li;plo=lo;}
void GerenciadorColisoes::setLista(Listas::ListaObstaculos* lo,Listas::ListaInimigos* li){pli=li;plo=lo;}

#define ERRO 0.2
void GerenciadorColisoes::percorrer(){
    int tam = pli->getTamanho(),tam2 = plo->getTamanho();
    for(int i=0;i<tam;i++){
        //Inimigo com obstaculo
        for(int j=0;j<tam2;j++){
            sf::Vector2f ini(pli->operator[](i)->getPosicao()+pli->operator[](i)->getVelocidade()), obs(plo->operator[](j)->getPosicao());
            sf::Vector2f distancia((std::abs(ini.x-obs.x)),(std::abs(ini.y-obs.y)));

            sf::Vector2f distancia_min(pli->operator[](i)->getTamanho()+plo->operator[](j)->getTamanho());
            if(distancia.x<= distancia_min.x-ERRO && distancia.y <= distancia_min.x-ERRO)
                pli->operator[](i)->colid(plo->operator[](j));
        }
    }
}