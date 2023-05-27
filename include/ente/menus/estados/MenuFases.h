#pragma once
#include "../MenuState.h"
#include <fases/Fase.h>
class MenuPrincipal;

class MenuFases:public MenuState{
    private:
    MenuPrincipal* pMP; 
    Fases::Fase* pFase;
    public:
    MenuFases(MenuPrincipal* mp=NULL);
    ~MenuFases();

    void executar();
    void setTextos();
};