#include "../MenuState.h"

class MenuFases;

class MenuPrincipal:public MenuState{
    private:
    MenuFases* pFases;
    public:
    MenuPrincipal();
    ~MenuPrincipal();

    void executar();
    void setTextos();
};