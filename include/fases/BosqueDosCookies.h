#pragma once
#include "Fase.h"
#include "CriadorEntidades.h"
#include "criadores/CriadorBosque.h"

namespace Fases{

class BosqueDosCookies:public Fase{
    private:
    CriadorBosque ct;
    public:
    BosqueDosCookies();
    ~BosqueDosCookies();
};

}   