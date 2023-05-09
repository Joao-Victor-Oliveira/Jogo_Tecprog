#pragma once
#include <ente/Ente.h>

class Entidade: public Ente{
    private:
    sf::RectangleShape corpo;
    sf::Vector2f velocidade;
    sf::Vector2f posicao;

    public:
    Entidade(std::string caminho="", float px, float py);
    ~Entidade();
    
    void setVelocidade(sf::Vector2f vel);
    void setPosicao(sf::Vector2f pos);

    const sf::Vector2f getVelocidade()const;
    const sf::Vector2f getPosicao()const;

    virtual void executar(); 
    virtual void draw(); //Não sei se vou usar o virtual , qualquer coisa lembrar de tirar
};