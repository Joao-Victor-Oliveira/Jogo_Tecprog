#pragma once
#include "Fase.h"
#include "CriadorEntidades.h"
#include "criadores/CriadorCastelo.h"

namespace Fases{

class CasteloAssombrado:public Fase{
    private:
    CriadorCastelo ct;
    public:
    CasteloAssombrado(){criarEntidades(&ct);}
    ~CasteloAssombrado(){}
};

}   