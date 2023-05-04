#include "../../../include/ente/menus/MenuState.h"


    Menu* MenuState::menu = nullptr;

    MenuState::MenuState(){
    }
    
    MenuState::~MenuState(){
        opcoes.clear();
    }

    void MenuState::draw(){
        int tam = opcoes.size();
        for(int i=0;i<tam;i++){
            opcoes[i]->setPos(sf::Vector2f(100,100+100*i));
            opcoes[i]->draw();
        }
    }

    void MenuState::add(MenuItem& agregado){
        opcoes.push_back(&agregado);
    };
    
    void MenuState::executar(){
        indice.setMax(opcoes.size());
        while (gg->aberto())
        {
            sf::Event evento;
            while (gg->adicionarEvento(evento))
            {
                if (evento.type == sf::Event::KeyPressed)
                {
                    if (evento.key.code == sf::Keyboard::Up)
                        indice.operator++();
                    else if (evento.key.code == sf::Keyboard::Down)
                        indice.operator--();
                    else if(evento.key.code== sf::Keyboard::Enter)
                        opcoes[indice.cont]->executar();
                }
            }

            draw();
            gg->mostrar();
            gg->limpar();
        }
    }