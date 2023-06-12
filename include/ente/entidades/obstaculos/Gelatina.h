#include "Obstaculo.h"

namespace Entidades{

class Gelatina:public Obstaculo{
    private:
    const float consistencia;
    public:
    Gelatina(const sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Gelatina();

    void interagir(Jogador* pJog);
    void executar();
    void salvar();
};

}