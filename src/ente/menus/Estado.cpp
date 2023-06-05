#include <ente/menus/Estado.h>
#include <iostream>
#include <unistd.h>
    sf::Font Estado::fonte;

    Estado::Estado(const int op):tam(op){
        for(int i=0;i<tam;i++)
            opcoes.push_back(new sf::Text);
    }
    
    Estado::~Estado(){
        for(int i=0;i<tam;i++){
            if(opcoes[i])
                delete opcoes[i];
            else
                printf("warning: Estado error memória\n");
        }
        opcoes.clear();
    }

    void Estado::draw(){
        if(!gg)
            setGG(Gerenciadores::GerenciadorGrafico::getInstance());
        
        for(int i=0;i<tam;i++)
            gg->desenhar(*opcoes[i]);
    }
    
    void Estado::loop(){
        indice.setMax(tam);
        while (gg->aberto())
        {
            sf::Event evento;
            while (gg->adicionarEvento(evento))
            {
                if (evento.type == sf::Event::KeyPressed)
                {
                    if (evento.key.code == sf::Keyboard::Down)
                        indice.operator++();
                    else if (evento.key.code == sf::Keyboard::Up)
                        indice.operator--();
                    else if(evento.key.code== sf::Keyboard::Enter){
                        comando = indice.cont;
                        gg->limpar();
                        return;
                    }
                }
                if (evento.type == sf::Event::Closed){
                        gg->fechar();
                        gg->limpar();
                        return;
                }
            }
            destacar(indice.cont);
            draw();
            gg->mostrar();
            gg->limpar();
        }
    }

    void Estado::setfonte(const char* s){
        try {
        if (!fonte.loadFromFile(s)) {
            throw std::runtime_error("Erro ao carregar a fonte");
        }
        } catch (const std::exception& erro) {
        std::cerr << "Erro: abrindo a fonte do Menu " << erro.what() << std::endl;
        }
    }

    void Estado::destacar(const int indice){
        for(int i=0;i<tam;i++)
            opcoes[i]->setOutlineThickness(0);

        opcoes[indice]->setOutlineThickness(24);
    }

    