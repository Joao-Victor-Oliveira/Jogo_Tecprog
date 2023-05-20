#pragma once
#include "FMFase.h"

namespace Fases{

class Fase:public Ente, public FMFase{
    protected:
    
    public:
    void executar();
    void draw();
    };

}