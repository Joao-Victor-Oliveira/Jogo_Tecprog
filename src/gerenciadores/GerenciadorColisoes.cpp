#include <gerenciadores/GerenciadorColisoes.h>
using namespace Gerenciadores;


GerenciadorColisoes::GerenciadorColisoes(Entidades::Jogador* p):pli(NULL),plo(NULL),pPl(NULL){pPl=p;}
GerenciadorColisoes::~GerenciadorColisoes(){}
    

void GerenciadorColisoes::setLista(Listas::ListaInimigos* li){pli=li;}
void GerenciadorColisoes::setLista(Listas::ListaObstaculos* lo){plo=0;}
void GerenciadorColisoes::setLista(Listas::ListaInimigos* li,Listas::ListaObstaculos* lo){pli=li;plo=lo;}
void GerenciadorColisoes::setLista(Listas::ListaObstaculos* lo,Listas::ListaInimigos* li){pli=li;plo=lo;}

#define ERRO 1
void GerenciadorColisoes::colidir(){
    int tam = pli->getTamanho(),tam2 = plo->getTamanho();
    for(int i=0;i<tam;i++){
        //Inimigo com obstaculo
        for(int j=0;j<tam2;j++){
            sf::Vector2f ini(pli->operator[](i)->getPosicao()), obs(plo->operator[](j)->getPosicao());
            sf::Vector2f distancia((std::abs(ini.x-obs.x)),(std::abs(ini.y-obs.y)));

            sf::Vector2f distancia_min(pli->operator[](i)->getTamanho()+plo->operator[](j)->getTamanho());
            distancia_min /= 2.f;
            if(distancia.x<= distancia_min.x-ERRO && distancia.y <= distancia_min.y-ERRO)
                pli->operator[](i)->colid(plo->operator[](j),distancia_min,distancia);
        }
        //Inimigo com Inimigo
        for(int k=i+1;k<tam;k++){
            sf::Vector2f ini(pli->operator[](i)->getPosicao()), ini2(pli->operator[](k)->getPosicao());
            sf::Vector2f distancia((std::abs(ini.x-ini2.x)),(std::abs(ini.y-ini2.y)));
            sf::Vector2f distancia_min(pli->operator[](i)->getTamanho()+pli->operator[](k)->getTamanho());
            distancia_min /= 2.f;
            
            if(distancia.x<= distancia_min.x-ERRO && distancia.y <= distancia_min.y-ERRO)
                pli->operator[](i)->colid(pli->operator[](k),distancia_min,distancia);
        }
        sf::Vector2f pla(pPl->getPosicao()), ini(pli->operator[](i)->getPosicao());
        sf::Vector2f distancia((std::abs(pla.x-ini.x)),(std::abs(pla.y-ini.y)));
        sf::Vector2f distancia_min(pPl->getTamanho()+pli->operator[](i)->getTamanho());
        distancia_min /=2.f;
        if(distancia.x<= distancia_min.x-ERRO && distancia.y <= distancia_min.y-ERRO)
                pli->operator[](i)->colid(pPl,distancia_min,distancia);

    }

    //Jogador obstaculo
    for(int j=0;j<tam2;j++){
        sf::Vector2f pla(pPl->getPosicao()+pPl->getVelocidade()), obs(plo->operator[](j)->getPosicao());
        sf::Vector2f distancia((std::abs(pla.x-obs.x)),(std::abs(pla.y-obs.y)));
        sf::Vector2f distancia_min(pPl->getTamanho()+plo->operator[](j)->getTamanho());

        distancia_min /= 2.f;
        if(distancia.x<= distancia_min.x-ERRO && distancia.y <= distancia_min.y-ERRO)
            pPl->colid(plo->operator[](j),distancia_min,distancia);
    }
    
}