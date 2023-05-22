#include <fases/Fase.h>

using namespace Fases;

Fase::Fase(CriadorEntidades* ce):listaI(),listaO(){
    if(ce){
        ce->criarInimigos(&listaI);
        ce->criarObstaculos(&listaO);
            //foi feito pra receber um new static_cast<CriadorEntidades*> new alguma_coisa derivada do CriadorEntidades, então é importante nesse caso
        delete ce;
    }
    gc = new Gerenciadores::GerenciadorColisoes();
    gc->setLista(&listaI,&listaO);
}

Fase::~Fase(){
    delete gc;
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
        gg->mostrar();
        listaI.percorrer();
        listaO.percorrer();
        gc->colidir();
        gg->limpar();
        sf::sleep(sf::milliseconds(25));
    }
}

void Fase::draw(){
    listaI.draw();
    listaO.draw();
}
