#include "Lista.h"
#include <ente/entidades/inimigos/Inimigo.h>

namespace Listas{
class ListaInimigos{
    private:
    Lista<Entidades::Inimigo> inimigos;
    public:
    ListaInimigos();
    ~ListaInimigos();

    void adicionar(Entidades::Inimigo* elem);
    void remover(const int indice);

    Entidades::Inimigo* operator[](const int i);

    void percorrer();

    void draw();
};
}