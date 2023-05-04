#pragma once
#include "MenuItem.h"

class Menu;

class MenuState: public MenuComponent {
    protected:
    std::vector<MenuItem*> opcoes;
    static Menu* menu;

    class Contador{
        private:
        int max;
        public:
        int cont;
        Contador(){cont=0;max=0;}
        ~Contador(){}
        void setMax(int max){this->max=max;}
        void operator++(){(cont==max)?cont=0:cont++;}
        void operator--(){(cont==0)?cont=max:cont--;}
    };

    Contador indice;

    public:
    MenuState();
    virtual ~MenuState();

    void add(MenuItem& agregado);
    virtual void draw();
    virtual void executar();
};