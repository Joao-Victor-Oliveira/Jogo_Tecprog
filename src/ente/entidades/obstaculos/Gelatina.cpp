#include <ente/entidades/obstaculos/Gelatina.h>
#include <ente/entidades/Jogador.h>
using namespace Entidades;

Gelatina::Gelatina(const sf::Vector2f pos):
Obstaculo("../../imagens/obstaculos/gelatina.png",pos,sf::Vector2f(50,30),0),
consistencia(0.2)
{
    estatico = false;
    sf::Color corRosa(255, 0, 255); // Cor rosa original
    corRosa.r = 255; // Aumenta o valor do canal vermelho
    corRosa.g = 100; // Aumenta o valor do canal verde
    corRosa.b = 200; // Aumenta o valor do canal azul
    corRosa.a = 200; // Define a opacidade (50%)

    // Use a cor com opacidade para preencher o objeto
    corpo.setFillColor(corRosa); // Define a cor com componente alfa de 128

}

Gelatina::~Gelatina(){}

void Gelatina::interagir(Jogador* pJog){
    pJog->setImpulso(pJog->getImpulso()*consistencia);
}

void Gelatina::executar(){
    move(velocidade);
    gravidade();
}