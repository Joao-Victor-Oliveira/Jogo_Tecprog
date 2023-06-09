#include <ente/entidades/Jogador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Entidades;



#define VIDAS 10

Jogador::Jogador():
Personagem("../../imagens/Jogador.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)),
pontos(0),pulando(false),coliE(false),coliD(false),danado(false),
impulso(10.f,-20.f)
{
    pontos =0;
    num_vidas =VIDAS;
    corpo.setOutlineColor(sf::Color::White);
}

Jogador::~Jogador(){
    pontos =0;
    num_vidas=VIDAS;
}

void Jogador::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(pObs->getSolido()){
        if(deslocamento.y-2<=deslocamento.x){
            if(pObs->getPosicao().y >= getPosicao().y){
                move(sf::Vector2f(0.f,deslocamento.y*-1));
                pulando = false;
            }
            else
                move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =0.f;
        }
        else{
            if(pObs->getPosicao().x >= getPosicao().x ){
                move(sf::Vector2f(deslocamento.x*-1-10,0.f));
                if(deslocamento.x > 0.1)
                    coliD = true;
            }
            else{
                move(sf::Vector2f(deslocamento.x+10,0.f));
                if(deslocamento.x > 0.1)
                    coliE = true;
            }
            velocidade.x=0.f;
        }
    }

    pObs->interagir(this);
}

void Jogador::colid(Jogador* pJog,sf::Vector2f deslocamento){
}


void Jogador::executar(){
    velocidade.x=0;
    gravidade();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(!pulando){
            velocidade.y = impulso.y;
            pulando =true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(!coliE)
            velocidade.x = impulso.x*-1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(!coliD)
            velocidade.x = impulso.x;
    }
    coliD = false; coliE= false;
    if(danado && relogio.getElapsedTime().asSeconds()>2){
        danado=0; 
        corpo.setOutlineThickness(0);
    }
    move(velocidade);
    resetImpulso();
}

void Jogador::danar_se(const int dano){
    if(dano<=0)
        num_vidas-= dano;
    else if(relogio.getElapsedTime().asSeconds()>2 || num_vidas == VIDAS)
    {
        danado = true;
        if(num_vidas<=0)
            printf("jog morto\n");
        num_vidas-= dano;
        relogio.restart();
        corpo.setOutlineThickness(5);
    }
}

void Jogador::setImpulso(const sf::Vector2f imp){
    impulso = imp;
}

const sf::Vector2f Jogador::getImpulso()const{
    return impulso;
}

void Jogador::resetImpulso(){
    impulso = sf::Vector2f(10.f,-20.f);
}

void Jogador::incrementarPontos(const int p){
    pontos +=p;
}

const int Jogador::getPontos(){return pontos;}


void Jogador::salvar(){
    salvarPosição("../../salvamento/Jogador.txt");
    salvarVidas("../../salvamento/Jogador.txt");
    std::ofstream ofs("../../salvamento/Jogador.txt",std::ios::app);
        if (ofs.is_open()) {
            ofs << pontos << std::endl;
            ofs.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a posição." << std::endl;
        }
}


void Jogador::recuperar(){
    std::ifstream ifs("../../salvamento/Jogador.txt");
    if (ifs.is_open()) {
        while (ifs) {
            ifs>> posicao.x >> posicao.y >> num_vidas >> pontos;
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de Jogador." << std::endl;
    }
}