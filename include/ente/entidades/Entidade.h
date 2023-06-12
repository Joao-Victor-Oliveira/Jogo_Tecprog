#pragma once
#include <ente/Ente.h>

#define GRAVIDADE 1

namespace Entidades{
class Jogador;class Inimigo;class Obstaculo;
class Entidade: public Ente{
    protected:
    sf::RectangleShape corpo;
    sf::Vector2f velocidade;
    sf::Vector2f posicao;
    sf::Texture texture;
    static Jogador* jogador1;
    bool ativo;

    public:
    Entidade(const std::string caminho="../../imagens/default.png", const sf::Vector2f pos=sf::Vector2f(0.f,0.f),const sf::Vector2f tam= sf::Vector2f(0.f,0.f));
    ~Entidade();
    
    void setVelocidade(sf::Vector2f vel);
    void setPosicao(sf::Vector2f pos);
    void setTamanho(sf::Vector2f tam);

    const sf::Vector2f getVelocidade()const;
    const sf::Vector2f getPosicao()const;
    const sf::Vector2f getTamanho()const;


    virtual void executar()=0; 
    virtual void draw();

    void move (const sf::Vector2f d);

    virtual void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    virtual void colid(Inimigo* pIni,sf::Vector2f deslocamento);
    virtual void colid(Jogador* pJog,sf::Vector2f deslocamento);

    static void setJogador(Jogador* jg);

    const bool getAtivo()const;

    void gravidade();

    virtual void salvar() =0;

    void salvarPosição(std::string s);
};
}
