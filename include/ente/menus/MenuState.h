#pragma once
#include "MenuComponent.h"

class MenuState: public MenuComponent{
    protected:
    
    static sf::Font fonte;
    std::vector<sf::Text*> opcoes;
    const int tam;
    int comando;

    class Contador{
        private:
        int max;
        public:
        int cont;
        Contador(){cont=0;max=0;}
        ~Contador(){}
        void setMax(int max){this->max=max-1;}
        void operator++(){(cont==max)?cont=0:cont++;}
        void operator--(){(cont==0)?cont=max:cont--;}
    };

    Contador indice;

    public:
    MenuState(const int op=0);
    virtual ~MenuState();
    void destacar(const int indice);

    static void setfonte(const char* s);

    virtual void draw();
    virtual void executar()=0;

    virtual void loop();
    virtual void setTextos()=0;
};