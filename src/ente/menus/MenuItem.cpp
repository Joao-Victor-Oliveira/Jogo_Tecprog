#include "../../../include/ente/menus/MenuItem.h"
    
    sf::Font MenuItem::fonte;

    MenuItem::MenuItem(std::string s){
        setNome(s);
        m_nome.setCharacterSize(24);
        m_nome.setOutlineColor(sf::Color::Red);
        m_nome.setOutlineThickness(0);
        m_nome.setFont(fonte);
    }

    MenuItem::~MenuItem(){}

    void MenuItem::setPos(sf::Vector2f pos){
        m_nome.setPosition(pos);
    }


    const sf::Text& MenuItem::getNome()const{
        return m_nome;
    }

    void MenuItem::setNome(const std::string s){
        m_nome.setString(s);
    }

    void MenuItem::draw(){
        gg->desenhar(m_nome);
    }

    void MenuItem::destacar(){
        m_nome.setOutlineThickness(12);
    }

    void MenuItem::setfonte(const char* s){
        try {
        if (!fonte.loadFromFile(s)) {
            throw std::runtime_error("Erro ao carregar a fonte");
        }
        
        } catch (const std::exception& erro) {
        std::cerr << "Erro: abrindo a fonte do Menu " << erro.what() << std::endl;
        }
    }
