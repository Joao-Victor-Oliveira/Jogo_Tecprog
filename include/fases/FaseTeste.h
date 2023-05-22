#pragma once
#include "Fase.h"
#include "CriadorEntidades.h"

namespace Fases{

class FaseTeste:public Fase{
    public:
    FaseTeste(CriadorEntidades* ce):Fase(ce){}
    ~FaseTeste(){}
};

}