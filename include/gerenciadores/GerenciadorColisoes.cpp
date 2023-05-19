#include <gerenciadores/GerenciadorColisao.h>
using namespace gerenciadores;

GerenciadorColisao::GerenciadorColisao(Lista::ListaInimigos* listainimigos, Lista::ListaObstaculos* listaobstaculos)://Lista:: ListaJogador* listajogador);){
listainimigos(listainimigos),listaobstaculos(listaobstaculos){//listajogador(listajogador)
}

GerenciadorColisao::~GerenciadorColisao(){
    if(listainimigos){
        delete(listainimigos);
    }
    if(listaobstaculos){
        delete(listaobstaculos);
    }
    //if(listajogador){
    //    delete(listajogador);
    //}
}

const sf:: Vector2f GerenciadorColisao::calculaColisao(Entidades::Entidade* entd1, Entidades::Entidade* entd2){//Entidades::Entidade* entd3);
    sf::Vector2f pos1 = entd1->getPos();
    sf::Vector2f pos2 = entd2->getPos();
    //sf::Vector2f pos2 = entd3->getPos();

    sf::Vector2f tam1 = entd1->getTam();
    sf::Vector2f tam2 = entd2->getTam();
    //sf::Vector2f tam2 = entd3->getTam();

    sf::Vector2f distanciaDosCorpos(//comparacao entre 2 corpos(
        fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
        fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
    );
    //distancia minima para que 2 corpos estejam lado a lado sem convergir
    sf::Vector2f distMinima(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
    //retorna se ha colisao em x ou y, havera se for negativo
    return sf::Vector2f(distanciaDosCorpos.x - distMinima.x, distanciaDosCorpos.y - distMinima.y);
}

void GerenciadorColisao::executar(){

}