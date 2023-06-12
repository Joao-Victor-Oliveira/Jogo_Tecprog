#include <ente/entidades/inimigos/Rosquinha.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

#define VX 5.0

Rosquinha::Rosquinha(sf::Vector2f pos):Inimigo("../../imagens/inimigos/Rosquinha.png",pos,sf::Vector2f(30.f,30.f),1),
irritado((rand()%4==3)?1:0),
vx((irritado)?VX*2:VX)
{
    if(irritado)
        corpo.setFillColor(sf::Color::Red);
    (rand()%2)?setVelocidade(sf::Vector2f(vx,0.f)):setVelocidade(sf::Vector2f(-1*vx,0.f));
    num_vidas = 1;
}
Rosquinha::Rosquinha(sf::Vector2f pos, bool irrit):
Inimigo("../../imagens/inimigos/Rosquinha.png",pos,sf::Vector2f(30.f,30.f),1),
irritado(irrit),
vx((irritado)?VX*2:VX)
{
    if(irritado)
        corpo.setFillColor(sf::Color::Red);
    (rand()%2)?setVelocidade(sf::Vector2f(vx,0.f)):setVelocidade(sf::Vector2f(-1*vx,0.f));
    num_vidas = 1;
}


Rosquinha::~Rosquinha(){

}

void Rosquinha::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(pObs->getSolido()){
        if(deslocamento.y<=deslocamento.x){
            if(pObs->getPosicao().y >= getPosicao().y){
                move(sf::Vector2f(0.f,deslocamento.y*-1));
                velocidade.y =-17.f;
            }
            else{
                move(sf::Vector2f(0.f,deslocamento.y));
                velocidade.y =5.f;
            }
        }
        else{
            (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
            velocidade.x *= -1;
        }
    }
}

void Rosquinha::colid(Inimigo* pIni,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(velocidade.y >=0 ){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            velocidade.y =-17.f;
        }
        else{
            move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =8.f;
        }
    }
    else{
        (velocidade.x <=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x *= -1;
    }
}

void Rosquinha::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(posicao.y < pJog->getPosicao().y){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            velocidade.y =-17.f;
            pJog->danar_se(dano);
        }
        else{
            move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =8.f;
            danar_se(1);
            pJog->setVelocidade(sf::Vector2f(0.f,-12.f));
        }
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x *= -1;
        pJog->danar_se(dano);
    }
}

void Rosquinha::salvar(){
    salvarPosição("../../salvamento/Rosquinha.txt");
    std::ofstream ofs("../../salvamento/Rosquinha.txt",std::ios::app);
        if (ofs.is_open()) {
            ofs << irritado << std::endl;
            ofs.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a posição." << std::endl;
        }
}

void Rosquinha::setIrritado(const bool ir){irritado =ir; }