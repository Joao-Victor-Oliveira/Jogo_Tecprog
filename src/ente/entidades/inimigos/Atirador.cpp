#include <ente/entidades/inimigos/Atirador.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Listas::ListaEntidade<Projetil>* Atirador::plp(NULL);

Atirador::Atirador(sf::Vector2f pos):
Inimigo("../../imagens/inimigos/Atirador.png",pos,sf::Vector2f(24.f,60.f)),
bala(NULL)
{
    num_vidas = 3;
}

Atirador::~Atirador(){

}
#define VY -22.f
void Atirador::executar(){
    if(!bala){
        bala = new Projetil(1,"../../imagens/inimigos/Projetil.png",sf::Vector2f(-20.f,-20.f),sf::Vector2f(15,15),sf::Vector2f(0.f,0.f));
        plp->adicionar(bala);
    }
    
    if(jogador1 && relogio.getElapsedTime().asSeconds()>2){
        float distx = jogador1->getPosicao().x - getPosicao().x;
        float disty = jogador1->getPosicao().y - getPosicao().y;

        if(std::fabs(distx) < 300){
            float deltaS = VY*VY/(2*GRAVIDADE);

            float tempoQueda = std::sqrt(2*(deltaS+disty)/GRAVIDADE);
            float tempoSubida = std::fabs(VY/GRAVIDADE);
            float velocidadex = distx/(tempoQueda+tempoSubida);

            disparar(velocidadex);
            relogio.restart();
        }
    }
    move(velocidade);
    velocidade.y += GRAVIDADE;
}

void Atirador::disparar(const float vel){
    bala->setVelocidade(sf::Vector2f(vel,VY));
    bala->setPosicao(getPosicao());
    bala->ativo = true;
}

void Atirador::setListaProjetil(Listas::ListaEntidade<Projetil>* lp){plp=lp;}

void Atirador::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pJog->getPosicao().y > getPosicao().y){
            pJog->move(sf::Vector2f(0.f,deslocamento.y));
            pJog->danar_se(dano);
        }
        else{
            pJog->move(sf::Vector2f(0.f,deslocamento.y*-1));
            danar_se(1);
            pJog->setVelocidade(sf::Vector2f(0.f,-18.f));
        }
        velocidade.y =0.f;
    }
    else{
        if(pJog->getPosicao().x > getPosicao().x)
            pJog->move(sf::Vector2f(deslocamento.x+10,0.f));
        else
            pJog->move(sf::Vector2f(deslocamento.x*-1-10,0.f));
        velocidade.x=0.f;
        pJog->danar_se(dano);
    }
}