#include <ente/entidades/Entidade.h>
using namespace Entidades;

Entidade::Entidade(const std::string caminho, const sf::Vector2f pos):velocidade(0.f,0.f),posicao(pos){
    sf::Texture texture;
    try {
        if (!texture.loadFromFile(caminho)) {
            throw std::runtime_error("Não foi possível carregar a textura:"+caminho+'\n');
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        corpo.setFillColor(sf::Color::Red);
    }
    
    corpo.setTexture(&texture);
}

Entidade::~Entidade(){}
    
void Entidade::setVelocidade(sf::Vector2f vel){velocidade = vel;}
void Entidade::setPosicao(sf::Vector2f pos){posicao=pos;}
void Entidade::setTamanho(sf::Vector2f tam){corpo.setSize(tam);}

const sf::Vector2f Entidade::getVelocidade()const{return velocidade;}
const sf::Vector2f Entidade::getPosicao()const{return posicao;}
const sf::Vector2f Entidade::getTamanho()const{return corpo.getSize();}

void Entidade::executar(){posicao+=velocidade;}
void Entidade::draw(){gg->desenhar(corpo);}