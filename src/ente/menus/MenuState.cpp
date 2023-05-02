#include "../../../include/ente/menus/MenuState.h"
    Menu* MenuState::menu = nullptr;

    MenuState::MenuState(std::string s):MenuComponent(s){
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

    void MenuState::add(MenuComponent& agregado){
        opcoes.push_back(&agregado);
    }

    void MenuState::setMenu(Menu* m){
        menu = m;
    }
    
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
                    {
                        /*
                        MenuState* aux = dynamic_cast<MenuState*> opçoes[indice.cont];
                        if(aux!=NULL)
                            menu->setEstado(aux);
                        else
                            opcoes[indice]->executar();
                        break;
                        */
                    }
                }
            }

            draw();
            gg->mostrar();
            gg->limpar();
        }
    }