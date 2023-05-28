#include <ente/entidades/Entidade.h>
using namespace Entidades;
#include <ente/entidades/obstaculos/Obstaculo.h> 
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/Jogador.h>

Jogador* Entidade::jogador1(NULL);

Entidade::Entidade(const std::string caminho, const sf::Vector2f pos,const sf::Vector2f tam):velocidade(0.f,0.f),posicao(pos){
    try {
        if (!texture.loadFromFile(caminho)) {
            throw std::runtime_error("Não foi possível carregar a textura:"+caminho+'\n');
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        corpo.setFillColor(sf::Color::Red);
    }
    //corpo.setTexture(&texture);
    corpo.setSize(tam);
    corpo.setOrigin(tam/2.f);
    corpo.setPosition(pos);
}

Entidade::~Entidade(){}
    
void Entidade::setVelocidade(sf::Vector2f vel){velocidade = vel;}
void Entidade::setPosicao(sf::Vector2f pos){posicao=pos;}
void Entidade::setTamanho(sf::Vector2f tam){corpo.setSize(tam);}

const sf::Vector2f Entidade::getVelocidade()const{return velocidade;}
const sf::Vector2f Entidade::getPosicao()const{return posicao;}
const sf::Vector2f Entidade::getTamanho()const{return corpo.getSize();}


void Entidade::executar(){
    move(velocidade);
    (velocidade.y >=10 )?velocidade.y+= GRAVIDADE:velocidade.y+= GRAVIDADE;
}


void Entidade::draw(){gg->desenhar(corpo);}

void Entidade::move(const sf::Vector2f d){
    posicao +=d;
    corpo.setPosition(posicao);
}

void Entidade::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pObs->getPosicao().y > getPosicao().y)
            move(sf::Vector2f(0.f,deslocamento.y*-1));
        else
            move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        if(pObs->getPosicao().x > getPosicao().x)
            move(sf::Vector2f(deslocamento.x*-1,0.f));
        else
            move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}
void Entidade::colid(Inimigo* pIni,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pIni->getPosicao().y > getPosicao().y)
            move(sf::Vector2f(0.f,deslocamento.y*-1));
        else
            move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        if(pIni->getPosicao().x > getPosicao().x)
            move(sf::Vector2f(deslocamento.x*-1,0.f));
        else
            move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}
void Entidade::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pJog->getPosicao().y > getPosicao().y)
            move(sf::Vector2f(0.f,deslocamento.y*-1));
        else
            move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        if(pJog->getPosicao().x > getPosicao().x)
            move(sf::Vector2f(deslocamento.x*-1,0.f));
        else
            move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}

void Entidade::setJogador(Jogador* jg){jogador1=jg;}