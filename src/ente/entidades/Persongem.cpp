#include <ente/entidades/Persongem.h>
using namespace Entidades;

Personagem::Personagem(const std::string s,const sf::Vector2f pos,const sf::Vector2f tam):Entidade(s,pos,tam),num_vidas(3){

}

Personagem::~Personagem(){
    
}

void Personagem::operator+=(const int num){
    num_vidas+=num;
}

void Personagem::operator-=(const int num){
    num_vidas-=num;
}

const int Personagem::getVidas(){
    return num_vidas;
}

void Personagem::danar_se(const int dano){
    num_vidas-=1;
}

void Personagem::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        (velocidade.y >=0 )?move(sf::Vector2f(0.f,deslocamento.y*-1)):move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}
void Personagem::colid(Inimigo* pIni,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        (velocidade.y >=0 )?move(sf::Vector2f(0.f,deslocamento.y*-1)):move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}
void Personagem::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        (velocidade.y >=0 )?move(sf::Vector2f(0.f,deslocamento.y*-1)):move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}

void Personagem::salvarVidas(std::string s){
    std::ofstream ofs(s, std::ios::app);  // Abre o arquivo em modo de anexação
        if (ofs.is_open()) {
            ofs << num_vidas << std::endl;
            ofs.close();
            std::cout << "Posição salva com sucesso." << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar a posição." << std::endl;
        }
}

void Personagem::setVidas(const int v){
    num_vidas=v;
}