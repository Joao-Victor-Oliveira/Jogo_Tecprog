#include "Lista.h"
#include <ente/entidades/obstaculos/Obstaculo.h>

namespace Listas{
class ListaObstaculos{
    private:
    Lista<Entidades::Obstaculo> obstaculos;
    public:
    ListaObstaculos();
    ~ListaObstaculos();

    void adicionar(Entidades::Obstaculo* elem);
    void remover(const int indice);

    Entidades::Obstaculo* operator[](const int i);

    void percorrer();

    void draw();
};
}