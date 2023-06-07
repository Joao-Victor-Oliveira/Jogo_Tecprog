#include <fases/CriadorEntidades.h>
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/inimigos/Cookie.h>
#include <ente/entidades/inimigos/Rosquinha.h>
#include <ente/entidades/inimigos/Fastasma.h>
#include <ente/entidades/obstaculos/Plataforma.h>
#include <ente/entidades/obstaculos/FioDental.h>
#include <ente/entidades/obstaculos/Pirulitos.h>
#include <ente/entidades/obstaculos/Gelatina.h>

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
            if(aux != '#'){}
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
    Entidades::Cookie::setListaProjetil(lp);
}

void CriadorEntidades::criarCookies(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'A'){}
            else{
                if(v[contVetor]==contEntidades){
                    add(li,new Entidades::Cookie(sf::Vector2f((j + 1)*30+ 12, (i+1)*30+ 15)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}

void CriadorEntidades::criarRosquinhas(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'D'){}
            else{
                if(v[contVetor]==contEntidades){
                    add(li,new Entidades::Rosquinha(sf::Vector2f((j + 1)*30+ 15, (i+1)*30+ 15)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}

void CriadorEntidades::criarFantasmas(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'D'){}
            else{
                if(v[contVetor]==contEntidades){
                    add(li,new Entidades::Fantasma(sf::Vector2f((j + 1)*30+ 30, (i+1)*30+ 30)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}


void CriadorEntidades::criarFioDental(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'f'){}
            else{
                if(v[contVetor]==contEntidades){
                    add(lo,new Entidades::FioDental(sf::Vector2f((j + 1)*30+ 15, (i+1)*30+ 15)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}

void CriadorEntidades::criarPirulitos(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'p'){}
            else{
                if(v[contVetor]==contEntidades){
                    int aux = rand()%3 +1;
                    add(lo,new Entidades::Pirulitos(aux*2,sf::Vector2f((j + 1)*30+ 15*(aux+1), (i+1)*30+ 15)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}












void CriadorEntidades::preencher(int v[],const int max,const int quantidade){
    int i=0,j=0;

    for(i=0;i<quantidade;i++){
        v[i] = rand() % max;
        for(j=0;j<i;j++){
            if(v[j]==v[i]){
                i--;
                break;
            }
        }
    }
    sort(v,quantidade);
}

void CriadorEntidades::sort(int v[], const int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        aux = v[i];
        v[i] = v[minIndex];
        v[minIndex] = aux;
    }
}