#include <fases/Fase.h>
#include <Ranking.h>

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;


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
                pause.loop();
                int i = pause.getComando();
                if(i==2)
                    return;
                else if(pause.getComando() == 1)
                    salvarFase();
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

void Fase::recuperarEntidades(CriadorEntidades* ce){
    if(ce){
        ce->listaProjeteis(&listaP);
        player->recuperar();
        ce->recuperarInimigos(&listaI);
        ce->recuperarObstaculos(&listaO);
    }
};

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

void Fase::salvar(){
    listaI.salvar();
    listaO.salvar();
    player->salvar();
    printf("Jogo salvo\n");
}

void Fase::deleteSave(){
    try {
        for (const auto& entry : fs::directory_iterator("../../salvamento/")) {
            if (entry.is_regular_file()) {
                fs::remove(entry.path());
                std::cout << "Arquivo excluído: " << entry.path() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao excluir arquivos do diretório: " << e.what() << std::endl;
    }
}