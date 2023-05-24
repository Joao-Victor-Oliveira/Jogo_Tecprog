#include <fases/Fase.h>

using namespace Fases;

Fase::Fase(CriadorEntidades* ce):listaI(),listaO(){
    if(ce){
        ce->criarInimigos(&listaI);
        ce->criarObstaculos(&listaO);
            //foi feito pra receber um new static_cast<CriadorEntidades*> new alguma_coisa derivada do CriadorEntidades, então é importante nesse caso
        delete ce;
    }
    player = new Entidades::Jogador;
    gc = new Gerenciadores::GerenciadorColisoes(player);
    gc->setLista(&listaI,&listaO);
}

Fase::~Fase(){
    delete gc;
    delete player;
}

void Fase::executar(){
    if(!gg)
        setGG(Gerenciadores::GerenciadorGrafico::getInstance());
    if(listaI.vazia() && listaO.vazia())
        printf("sem entidades\n");
}   

void Fase::loop(){
    while (gg->aberto())
    {
        sf::Event evento;
        while (gg->adicionarEvento(evento))
        {
            if (evento.type == sf::Event::Closed){
                gg->limpar();
                return;
            }
        }
        draw();
        listaI.percorrer();
        listaO.percorrer();
        player->executar();
        gc->colidir();
        gg->mostrar();
        sf::sleep(sf::milliseconds(25));
        gg->limpar();
    }
}

void Fase::draw(){
    player->draw();
    listaI.draw();
    listaO.draw();
}
