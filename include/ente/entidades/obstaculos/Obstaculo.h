#include "../Entidade.h"

namespace Entidades{

class Obstaculo: public Entidade{
    protected:
    //Jogador* jg;
    public:
    Obstaculo(const std::string s= "",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const int d=0);

    ~Obstaculo();
};
}