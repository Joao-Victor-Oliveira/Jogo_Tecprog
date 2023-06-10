#include <fases/Fase.h>
#include <Ranking.h>

using namespace Fases;

Fase::Fase():listaI(),listaO(),listaP(),
vidas()
{
    player = new Entidades::Jogador;
    Entidades::Entidade::setJogador(player);
    gc = new Gerenciadores::GerenciadorColisoes(player);
    gc->setLista(&listaI,&listaO);
    gc->setProjeteis(&listaP);

    
    if(!font_vidas.loadFromFile("../../imagens/04B_30__.TTF"))
        printf("n achou a fonte");

    vidas.setFont(font_vidas);
    vidas.setPosition(1170.f,660.f);
    vidas.setCharacterSize(40);
    vidas.setFillColor(sf::Color::Yellow);
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
    relogio.restart();
    while (gg->aberto())
    {
        sf::Event evento;
        while (gg->adicionarEvento(evento))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                gg->limpar();
                return;
            }
        }
        draw();
        gc->colidir();
        percorrer();
        gg->mostrar();
        sf::sleep(sf::milliseconds(25));
        gg->limpar();
        if(player->getVidas()<=0 || !listaI.ativa()){
            (player->getVidas()<=0)?encerar(0):encerar(1);
            break;
        }

    }
}

void Fase::draw(){
    player->draw();
    listaI.draw();
    listaO.draw();
    listaP.draw();
    gg->desenhar(vidas);
}

void Fase::percorrer(){
    listaI.percorrer();
    listaO.percorrer();
    listaP.percorrer();
    player->executar();

    std::string aux = std::to_string(player->getVidas());
    aux += "x";
    vidas.setString(aux);
}

void Fase::criarEntidades(CriadorEntidades* ce){
    if(ce){
        ce->listaProjeteis(&listaP);
        ce->criarInimigos(&listaI);
        ce->criarObstaculos(&listaO);
    }
}

void Fase::encerar(const bool ganhou){
    if(!ganhou){
        return;
    }
    else{
        pontuar();
        Ranking r;
        r.salvar(r.getNome(),player->getPontos());
        return;
    }
}

void Fase::pontuar(){
    player->incrementarPontos(player->getVidas()*200);
    player->incrementarPontos(10000 - (relogio.getElapsedTime().asSeconds()*4));
}