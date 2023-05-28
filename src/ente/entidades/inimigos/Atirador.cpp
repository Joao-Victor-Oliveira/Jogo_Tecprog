#include <ente/entidades/inimigos/Atirador.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Atirador::Atirador(sf::Vector2f pos):
Inimigo("../../imagens/default.png",pos,sf::Vector2f(30.f,60.f)),
bala(1,"../../imagens/default.png",sf::Vector2f(-20.f,-20.f),sf::Vector2f(15,15),sf::Vector2f(0.f,0.f))
{
    corpo.setFillColor(sf::Color::Red);
}

Atirador::~Atirador(){

}
#define VY -20.f
bool count=false;
void Atirador::executar(){
    if(!count){
        bala.registrar();
        count = true;
    }
    if(jogador1 && !bala.ativo){
        float distx = jogador1->getPosicao().x - getPosicao().x;
        float disty = jogador1->getPosicao().y - getPosicao().y;

        if(std::fabs(distx) < 300){
            float deltaS = VY*VY/(2*GRAVIDADE);

            float tempoQueda = std::sqrt(2*(deltaS+disty)/GRAVIDADE);
            float tempoSubida = std::fabs(VY/GRAVIDADE);
            float velocidadex = distx/(tempoQueda+tempoSubida);

            disparar(velocidadex);
        }
    }
    move(velocidade);
    velocidade.y += GRAVIDADE;
}

void Atirador::disparar(const float vel){
    bala.setVelocidade(sf::Vector2f(vel,VY));
    bala.setPosicao(getPosicao());
    bala.ativo = true;
}