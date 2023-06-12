#include <ente/entidades/obstaculos/Pirulitos.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Pirulitos::Pirulitos(const int np,const sf::Vector2f pos):
Obstaculo("../../imagens/obstaculos/espinho.png",pos,sf::Vector2f(np*15,30),true),
num_Pirulitos(np)
{       
    texture.setRepeated(true);
    desenho.setTexture(texture);
    desenho.setScale(sf::Vector2f(1.f, 1.f));
    desenho.setOrigin(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f);
    
    estatico =0;
}   

Pirulitos::~Pirulitos(){

}

void Pirulitos::interagir(Jogador* pJog){
    pJog->danar_se(1);
}

void Pirulitos::executar(){
    move(velocidade);
    gravidade();
}

void Pirulitos::draw(){
    sf::Vector2f aux = corpo.getPosition();
    desenho.setPosition(aux);

    for(int i=0;i<num_Pirulitos;i++){
        gg->desenhar(desenho);
        aux.x += 15;
        desenho.setPosition(aux);
    }
}

void Pirulitos::salvar(){
    salvarPosição("../../salvamento/Pirulitos.txt");

    std::ofstream ofs("../../salvamento/Pirulitos.txt",std::ios::app);
        if (ofs.is_open()) {
            ofs << num_Pirulitos << std::endl;
            ofs.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a posição." << std::endl;
        }
}