#include <fases/CriadorEntidades.h>
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/inimigos/Cookie.h>
#include <ente/entidades/inimigos/Rosquinha.h>
#include <ente/entidades/inimigos/Fastasma.h>
#include <ente/entidades/obstaculos/Plataforma.h>
#include <ente/entidades/obstaculos/FioDental.h>
#include <ente/entidades/obstaculos/Gelatina.h>

using namespace Fases;
using namespace Listas;

CriadorEntidades::CriadorEntidades():
num_entidades(0)
{
}

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
                            add(lo,new Entidades::Plataforma(sf::Vector2f((j+cont/2.f + 1 )*30,i*30+45),cont,1));
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

int CriadorEntidades::gerar(const int min,const int max){
    return rand()%(max-min)+min;
}

void CriadorEntidades::recuperarRosquinhas(Listas::ListaEntidade<Entidades::Inimigo>* li) {
    std::ifstream ifs("../../salvamento/Rosquinha.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); 
            if(posicao == sf::Vector2f(-1.f,-1.f))
            break;
            int irritado;
            ifs>>irritado;
            Entidades::Rosquinha* aux = new Entidades::Rosquinha(posicao,irritado);
            add(li,aux);
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de rosquinhas." << std::endl;
    }
}




void CriadorEntidades::recuperarFioDental(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    std::ifstream ifs("../../salvamento/FioDental.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); if(posicao == sf::Vector2f(-1.f,-1.f))break;
            add(lo,new Entidades::FioDental(posicao));
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de rosquinhas." << std::endl;
    }
}

sf::Vector2f CriadorEntidades::recuperarPos(std::ifstream& ifs) {
    float x, y;
    if (ifs >> x >> y) {
        return sf::Vector2f(x, y);
    } else {
        return sf::Vector2f(-1.f,-1.f);
    }
}


int CriadorEntidades::recuperarVidas(std::ifstream& ifs) {
    int vida;
    if (ifs >> vida) {
        return vida;
    } else {
        std::cerr << "Erro ao ler a vida do arquivo." << std::endl;
        return 0;
    }
}

void CriadorEntidades::recuperarPlataformas(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    std::ifstream ifs("../../salvamento/Plataforma.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); if(posicao == sf::Vector2f(-1.f,-1.f))break;
            int comp,alt;
            ifs >>comp >> alt;
            add(lo,new Entidades::Plataforma(posicao,comp,alt));
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de rosquinhas." << std::endl;
    }
}
