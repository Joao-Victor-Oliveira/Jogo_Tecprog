#include "../../../include/ente/menus/MenuComponent.h"
    
    sf::Texture MenuComponent::textura;

    MenuComponent::MenuComponent(std::string s){
        setNome(s);
        m_nome.setCharacterSize(24);
    };

    MenuComponent::~MenuComponent() {};

    const sf::Text& MenuComponent::getNome()const{
        return m_nome;
    }

    void MenuComponent::setNome(std::string s){
        m_nome.setString(s);
    }

    void MenuComponent::setPos(sf::Vector2f pos){
        m_nome.setPosition(pos);
    }

    void MenuComponent::draw(){
        gg->desenhar(m_nome);
    }

    void MenuComponent::setTextura(){
        try {
        if (!textura.loadFromFile("../../../Lobster-Regular.ttf")) {
            throw std::runtime_error("Erro ao carregar a textura");
        }
        
        } catch (const std::exception& erro) {
        std::cerr << "Erro: abrindo a textura do Menu " << erro.what() << std::endl;
        }
    }