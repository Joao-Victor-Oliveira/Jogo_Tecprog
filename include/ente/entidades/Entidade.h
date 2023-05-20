#pragma once
#include <ente/Ente.h>

namespace Entidades{
class Entidade: public Ente{
    protected:
    sf::RectangleShape corpo;
    sf::Vector2f velocidade;
    sf::Vector2f posicao;

    public:
    Entidade(const std::string caminho="../../default.png", const sf::Vector2f pos=sf::Vector2f(0.f,0.f));
    ~Entidade();
    
    void setVelocidade(sf::Vector2f vel);
    void setPosicao(sf::Vector2f pos);
    void setTamanho(sf::Vector2f tam);

    const sf::Vector2f getVelocidade()const;
    const sf::Vector2f getPosicao()const;
    const sf::Vector2f getTamanho()const;


    virtual void executar(); 
    virtual void draw(); //Não sei se vou usar o virtual , qualquer coisa lembrar de tirar
};
}
