#include <ente/entidades/inimigos/Cookie.h>
#include <ente/entidades/Jogador.h>
#include <iomanip>
using namespace Entidades;

Listas::ListaEntidade<Projetil>* Cookie::plp(NULL);

Cookie::Cookie(sf::Vector2f pos):
Inimigo("../../imagens/inimigos/Cookie.png",pos,sf::Vector2f(24.f,60.f)),
bala(NULL),
range(500)
{
    num_vidas = 3;
    pontos = 200;
}

Cookie::~Cookie(){

}
#define VY -18.f
void Cookie::executar(){
    if(!bala){
        bala = new Projetil(1,"../../imagens/inimigos/Projetil.png",sf::Vector2f(-20.f,-20.f),sf::Vector2f(15,15),sf::Vector2f(0.f,0.f));
        plp->adicionar(bala);
    }
    
    if(jogador1 && relogio.getElapsedTime().asSeconds()>2){
        float distx = jogador1->getPosicao().x - getPosicao().x;
        float disty = jogador1->getPosicao().y - getPosicao().y;

        if(std::fabs(distx) < range){
            float deltaS = VY*VY/(2*GRAVIDADE);

            float tempoQueda = std::sqrt(2*(deltaS+disty)/GRAVIDADE);
            float tempoSubida = std::fabs(VY/GRAVIDADE);
            float velocidadex = distx/(tempoQueda+tempoSubida);

            disparar(velocidadex);
            relogio.restart();
        }
    }
    move(velocidade);
    velocidade.y += GRAVIDADE;
}

void Cookie::disparar(const float vel){
    bala->setVelocidade(sf::Vector2f(vel,VY));
    bala->setPosicao(getPosicao());
    bala->ativo = true;
}

void Cookie::setListaProjetil(Listas::ListaEntidade<Projetil>* lp){plp=lp;}

void Cookie::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pJog->getPosicao().y > getPosicao().y){
            pJog->move(sf::Vector2f(0.f,deslocamento.y));
            pJog->danar_se(dano);
        }
        else{
            pJog->move(sf::Vector2f(0.f,deslocamento.y*-1));
            danar_se(1);
            pJog->setVelocidade(sf::Vector2f(0.f,-18.f));
        }
        velocidade.y =0.f;
    }
    else{
        if(pJog->getPosicao().x > getPosicao().x)
            pJog->move(sf::Vector2f(deslocamento.x+10,0.f));
        else
            pJog->move(sf::Vector2f(deslocamento.x*-1-10,0.f));
        velocidade.x=0.f;
        pJog->danar_se(dano);
    }
}



void Cookie::salvar(){
    salvarPosição("../../salvamento/Cookie.txt");
    salvarVidas("../../salvamento/Cookie.txt");

    std::ofstream ofs("../../salvamento/Cookie.txt",std::ios::app);
    if (ofs.is_open()) {
            bool tem_bala=false;
            if(bala){
                if(bala->ativo){
                    tem_bala = true;
                    ofs << tem_bala << std::endl;
                    bala->salvarPosição("../../salvamento/Cookie.txt");
                    sf::Vector2f vel = bala->getVelocidade();
                     ofs << std::fixed << std::setprecision(2) << vel.x << " " << vel.y<< std::endl;
                    ofs.close();
                }
                else{
                    ofs << 0 << std::endl;
                    ofs << -1.00 << " " << -1.00<<std::endl;
                    ofs << -1.00 << " " << -1.00<<std::endl;
                    ofs.close();
                }    
            }
            else{
                ofs << 0 << std::endl;
                ofs << -1.00 << " " << -1.00<<std::endl;
                ofs << -1.00 << " " << -1.00<<std::endl;
                ofs.close();
            }
    } else {
            std::cerr << "Erro ao abrir o arquivo para salvar projetil." << std::endl;
    }
}


void Cookie::setBala(Projetil* b){
    bala=b;
    plp->adicionar(bala);
}