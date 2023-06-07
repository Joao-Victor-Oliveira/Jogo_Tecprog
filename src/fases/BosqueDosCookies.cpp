#include <fases/BosqueDosCookies.h>

using namespace Fases;

BosqueDosCookies::BosqueDosCookies():
Fase(),
ct()
{
    criarEntidades(&ct);
}

BosqueDosCookies::~BosqueDosCookies(){
}