#include <fases/FaseTeste.h>

using namespace Fases;

FaseTeste::FaseTeste():
Fase(),
ct()
{
    criarEntidades(&ct);
}

FaseTeste::~FaseTeste(){
}