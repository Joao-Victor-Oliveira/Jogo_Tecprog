#pragma once
#include "Fase.h"
#include "CriadorEntidades.h"
#include "criadores/CriadorTeste.h"

namespace Fases{

class FaseTeste:public Fase{
    private:
    CriadorTeste ct;
    public:
    FaseTeste();
    ~FaseTeste();
};

}   