#include <fases/CriadorEntidades.h>
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/inimigos/Atirador.h>
#include <ente/entidades/obstaculos/Plataforma.h>

using namespace Fases;
using namespace Listas;

CriadorEntidades::CriadorEntidades(){}

CriadorEntidades::~CriadorEntidades(){printf("Foram criadas %d entidades\n", num_entidades);}

void CriadorEntidades::add(ListaEntidade<Entidades::Inimigo>* li ,Entidades::Inimigo* i){
    num_entidades++;
    if(!li || !i)
        throw std::invalid_argument("argumento nulo");
    else
        li->adicionar(i);
}

void CriadorEntidades::add(Listas::ListaEntidade<Entidades::Obstaculo>* lo,Entidades::Obstaculo* o){
    num_entidades++;
    if(!lo || !o)
        throw std::invalid_argument("argumento nulo");
    else
        lo->adicionar(o);
}

void CriadorEntidades::criarLimites(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41]){
    add(lo,new Entidades::Plataforma(sf::Vector2f(645,0),43,2));
    add(lo,new Entidades::Plataforma(sf::Vector2f(645,720),43,2));
    add(lo,new Entidades::Plataforma(sf::Vector2f(0,360),2,24));
    add(lo,new Entidades::Plataforma(sf::Vector2f(1290,360),2,24));
    
    int cont =0;
    
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux == '*'){}
            else{
                if(aux == '#'){
                    for(cont++;1;cont++){
                        if(j+cont < 41 && fase[i][j+cont]=='#'){
                            fase[i][j+cont]= 'a';
                        }
                        else{
                            add(lo,new Entidades::Plataforma(sf::Vector2f((j+cont/2.f)*30+45,i*30+45),cont,1));
                            break;
                        }
                    }
                    cont =0;
                }
            }
        }
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++)
            if(fase[i][j]== 'a')
                fase[i][j]='#';

}

void CriadorEntidades::listaProjeteis(Listas::ListaEntidade<Entidades::Projetil>* lp){
    Entidades::Atirador::setListaProjetil(lp);
}

/* Exemplo
void Criarinimigos(ListaEntidade<Entidades::Inimigo>* li){
    add(li,new inimigo1);
    for(int i=0,i<5,i++){add(li,new inimigo2);}
}

CriarObjetos analogo a CriarInimigos
*/