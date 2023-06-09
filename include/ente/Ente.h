#pragma once
#include <gerenciadores/GerenciadorGrafico.h>
#include <stdafx.h>

class Ente{
    private:
    static int counter; //exclusivo para criação do id
    const int id; //NAO USAR (boa pratica)
    protected:
    static Gerenciadores::GerenciadorGrafico* gg;//singleton
    
    public:
    Ente();
    ~Ente();
    
    static void setGG(Gerenciadores::GerenciadorGrafico* g);

    const int getID() const; //NAO USAR

    virtual void executar()=0;
    virtual void draw()=0;
};
