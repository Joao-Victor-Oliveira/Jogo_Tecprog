#include "../Persongem.h"

namespace Entidades{
class Inimigo: public Personagem{
    protected:
    //Jogador* jg;
    int dano;
    public:
    Inimigo(const std::string s= "",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const int d=0);
    ~Inimigo();
    virtual void causar_dano();
};
}