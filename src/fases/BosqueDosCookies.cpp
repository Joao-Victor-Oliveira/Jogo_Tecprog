#include <fases/BosqueDosCookies.h>

using namespace Fases;

BosqueDosCookies::BosqueDosCookies(bool recuperar):
Fase(),
ct()
{
    if(!recuperar)
        criarEntidades(&ct);
    else 
        recuperarEntidades(&ct);
}

BosqueDosCookies::~BosqueDosCookies(){
}

void BosqueDosCookies::salvarFase(){
    deleteSave();
    std::ofstream ofs("../../salvamento/Fase.txt");
        if (ofs.is_open()) {
            ofs << 0 << std::endl;
            ofs.close();
            
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a fase." << std::endl;
        }
    salvar();
}