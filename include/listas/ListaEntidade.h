#include "Lista.h"
#include <ente/entidades/Entidade.h>

namespace Listas{
    template<class TIPO>
    class ListaEntidade{
    private:
    Lista<Entidades::Entidade> entidades;
    public:
    ListaEntidade(){
        TIPO* aux = new TIPO;
        if(!dynamic_cast <Entidade*> (aux))
            printf("conversao invalida");
        delete aux;
    }
    ~ListaEntidade(){}

    void adicionar(TIPO* elem){
        entidades.push_back()
    }

    void remover(TIPO* elem){
        entidades.remover(static_cast<Entidades*> elem)
    }

    const int getTamanho(){
        return entidades.getTamanho();
    }

    TIPO* operator[](const int i){
        return static_cast<TIPO*> entidades[i];
    }

    void percorrer(){
        Lista<Entidades::Entidade>::Iterador * it = entidades.getPrimeiro();
        while(it != NULL){
            it->getConteudo()->executar();
            it++;
        }
    }

    void draw(){
        Lista<Entidades::Entidade>::Iterador * it = entidades.getPrimeiro();
        while(it != NULL){
            it->getConteudo()->draw();
            it++;
        }
    }
    bool vazia(){
        return entidades.empty();
    }

    }

}