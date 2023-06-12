#include <fases/CasteloAssombrado.h>
using namespace Fases;

CasteloAssombrado::CasteloAssombrado(bool recuperar)
{
    if(!recuperar)
        criarEntidades(&ct);
    else
        recuperarEntidades(&ct);
}

CasteloAssombrado::~CasteloAssombrado(){}


void CasteloAssombrado::salvarFase(){
    deleteSave();
    std::ofstream ofs("../../salvamento/Fase.txt");
        if (ofs.is_open()) {
            ofs << 1 << std::endl;
            ofs.close();
            
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a Fase" << std::endl;
        }
    salvar();
}