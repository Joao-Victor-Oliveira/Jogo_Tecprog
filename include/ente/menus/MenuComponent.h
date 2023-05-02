#pragma once
#include "../Ente.h"


class MenuComponent:public Ente{
    protected:
    sf::Text m_nome;
    static sf::Texture textura;

    public:
    
    MenuComponent(std::string s = "");

    virtual ~MenuComponent();
    
    const sf::Text& getNome()const;
    void setNome(std::string s);
    void setPos(sf::Vector2f pos);
    static void setTextura();

    virtual void draw();
    virtual void executar() = 0;
};