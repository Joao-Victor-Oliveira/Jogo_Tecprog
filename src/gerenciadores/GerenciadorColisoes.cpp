#include <gerenciadores/GerenciadorColisoes.h>
using namespace Gerenciadores;


GerenciadorColisoes::GerenciadorColisoes(Entidades::Jogador* p):pli(NULL),plo(NULL),pPl(NULL){pPl=p;}
GerenciadorColisoes::~GerenciadorColisoes(){}
    

void GerenciadorColisoes::setLista(Listas::ListaEntidade<Entidades::Inimigo>* li){pli=li;}
void GerenciadorColisoes::setLista(Listas::ListaEntidade<Entidades::Obstaculo>* lo){plo=0;}
void GerenciadorColisoes::setLista(Listas::ListaEntidade<Entidades::Inimigo>* li,Listas::ListaEntidade<Entidades::Obstaculo>* lo){pli=li;plo=lo;}
void GerenciadorColisoes::setLista(Listas::ListaEntidade<Entidades::Obstaculo>* lo,Listas::ListaEntidade<Entidades::Inimigo>* li){pli=li;plo=lo;}
void GerenciadorColisoes::setProjeteis(Listas::ListaEntidade<Entidades::Projetil>* v){plp = v;}

#define ERRO 0.5
void GerenciadorColisoes::colidir(){
    int tam1 = pli->getTamanho(),tam2 = plo->getTamanho(),tam3 = plp->getTamanho();
    
    for(int i=0;i<tam1;i++){
        if(pli->operator[](i)->getAtivo()){
            //inimigo // obstaculo
            for(int j=0;j<tam2;j++){
                if(pli->operator[](i)->getAtivo()){
                sf::Vector2f deslocamento = verificaColisao(pli->operator[](i)->getPosicao(),plo->operator[](j)->getPosicao(),  
                                                            pli->operator[](i)->getTamanho(),plo->operator[](j)->getTamanho());
                if(deslocamento.x || deslocamento.y)
                    pli->operator[](i)->colid(plo->operator[](j),deslocamento);
                }
            }
            //inimigo // inimigo
            for(int k=i+1;k<tam1;k++){
                if(pli->operator[](k)->getAtivo()){
                sf::Vector2f deslocamento = verificaColisao(pli->operator[](i)->getPosicao(),pli->operator[](k)->getPosicao(),  
                                                            pli->operator[](i)->getTamanho(),pli->operator[](k)->getTamanho());
                if(deslocamento.x || deslocamento.y)
                    pli->operator[](i)->colid(pli->operator[](k),deslocamento);
                }
            }
            //jogador // inimimigo
            sf::Vector2f deslocamento = verificaColisao(pli->operator[](i)->getPosicao(),pPl->getPosicao(),  
                                                        pli->operator[](i)->getTamanho(),pPl->getTamanho());
            if(deslocamento.x || deslocamento.y)
                    pli->operator[](i)->colid(pPl,deslocamento);
        }
    }
    
    //jogador // obstaculo
    for(int j=0;j<tam2;j++){
        if(!plo->operator[](j)->getAtivo())
            continue; 
        sf::Vector2f deslocamento = verificaColisao(pPl->getPosicao(),plo->operator[](j)->getPosicao(),  
                                                    pPl->getTamanho(),plo->operator[](j)->getTamanho());
        if(deslocamento.x || deslocamento.y)
            pPl->colid(plo->operator[](j),deslocamento);
    //projetil // obstaculo
        for(int k=0;k<tam3;k++){
            if(plp->operator[](k)->ativo){
                sf::Vector2f deslocamento = verificaColisao(plp->operator[](k)->getPosicao(),plo->operator[](j)->getPosicao(),  
                                                            plp->operator[](k)->getTamanho(),plo->operator[](j)->getTamanho());
                if(deslocamento.x || deslocamento.y)
                    plp->operator[](k)->colid(plo->operator[](j),deslocamento);
            }
        }
    //obstaculo // obstaculo
        for(int k=j+1;k<tam2;k++){
            if(!(plo->operator[](k)->getEstatico() && plo->operator[](j)->getEstatico()) && 
                plo->operator[](k)->getAtivo()){
                sf::Vector2f deslocamento = verificaColisao(plo->operator[](k)->getPosicao(),plo->operator[](j)->getPosicao(),  
                                                            plo->operator[](k)->getTamanho(),plo->operator[](j)->getTamanho());
                if(deslocamento.x || deslocamento.y)
                    plo->operator[](j)->colid(plo->operator[](k),deslocamento);
            }
        }
    }
    //projetil // jogador
    for(int k=0;k<tam3;k++){
        if(plp->operator[](k)->ativo){
            sf::Vector2f deslocamento = verificaColisao(plp->operator[](k)->getPosicao(),pPl->getPosicao(),  
                                                        plp->operator[](k)->getTamanho(),pPl->getTamanho());
            if(deslocamento.x || deslocamento.y)
                plp->operator[](k)->colid(pPl,deslocamento);
        }
    }
}

sf::Vector2f GerenciadorColisoes::verificaColisao(sf::Vector2f pos1,sf::Vector2f pos2,sf::Vector2f tam1,sf::Vector2f tam2){
    sf::Vector2f distancia((std::fabs(pos1.x-pos2.x)),(std::fabs(pos1.y-pos2.y)));
    sf::Vector2f distancia_min((tam1+tam2)/2.f);
    if(distancia.x<= distancia_min.x+ERRO && distancia.y <= distancia_min.y+ERRO){
        return sf::Vector2f(distancia_min.x-distancia.x,distancia_min.y-distancia.y);
    }
    else
        return sf::Vector2f(0,0);
}
