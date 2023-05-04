#pragma once
#include "MenuComponent.h"

class MenuItem:public MenuComponent{
    private:
    sf::Text m_nome;
    static sf::Font fonte;
    public:
    MenuItem(std::string s="");
    ~MenuItem();

    const sf::Text& getNome()const;
    void setNome(std::string s);
    
    static void setfonte(const char* s);

    void setPos(const sf::Vector2f pos);
    void draw();
    void destacar();

    virtual void executar()=0;
};