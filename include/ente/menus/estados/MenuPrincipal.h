#include "../MenuState.h"

class MenuPrincipal:public MenuState{
    private:
    public:
    MenuPrincipal();
    ~MenuPrincipal();

    void executar();
    void setTextos();
};