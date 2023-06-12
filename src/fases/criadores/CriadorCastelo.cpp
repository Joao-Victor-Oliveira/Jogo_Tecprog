#include <fases/criadores/CriadorCastelo.h>
#include <ente/entidades/inimigos/Fastasma.h>
#include <ente/entidades/obstaculos/Gelatina.h>


char mFase2[22][41] = {//5 F //10 D -- //6 f //10 g
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','F','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','F'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','g','*','*','*','*','*','*','*','*','*','g','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','g','*','*','*','f','*','*','*','g','*','*','D','f'},
    {'*','*','*','*','*','*','*','D','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','F','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','g','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','*','*','*','D','*','*','*','*','*','*','f','*'},
    {'*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#'},
    {'#','#','#','#','#','#','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','#','#','*','*','*','*','*','*','*'},
    {'#','#','#','#','#','#','g','*','*','f','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','g','*','f'},
    {'#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#'},
    {'#','#','#','#','#','#','*','*','*','*','*','*','F','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','F','*','*','#','#','#','#'},
    {'#','#','#','#','#','#','f','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#'},
    {'#','#','#','#','#','#','*','*','*','*','*','*','*','*','g','*','*','g','*','*','*','*','*','g','*','D','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#'}
};

using namespace Fases;

#define FDMIN 3
#define FDMAX 5

#define RMIN 7
#define RMAX 10

#define FMIN 4
#define FMAX 6

#define GMIN 6
#define GMAX 10


CriadorCastelo::CriadorCastelo():
num_Fantasmas(gerar(FMIN,FMAX)),
num_Gelatinas(gerar(GMIN,GMAX))
{
    num_Rosquinhas = gerar(RMIN,RMAX);
    num_FioDental = gerar(FDMIN,FDMAX);
}

CriadorCastelo::~CriadorCastelo(){}

void CriadorCastelo::criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li){
    int *v =  (int*) malloc(num_Fantasmas*sizeof(int));
    preencher(v,FMAX,num_Fantasmas);
    criarFantasmas(li,mFase2,v,num_Fantasmas);
    free(v);


    v =  (int*) malloc(num_Rosquinhas*sizeof(int));
    preencher(v,RMAX,num_Rosquinhas);
    criarRosquinhas(li,mFase2,v,num_Rosquinhas);
    free(v);

}

void CriadorCastelo::criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    criarLimites(lo,mFase2);
    
    int *v =  (int*) malloc(num_FioDental*sizeof(int));
    preencher(v,FDMAX,num_FioDental);
    criarFioDental(lo,mFase2,v,num_FioDental);
    free(v);

    v =  (int*) malloc(num_Gelatinas*sizeof(int));
    preencher(v,GMAX,num_Gelatinas);
    criarGelatinas(lo,mFase2,v,num_Gelatinas);
    free(v);
}

void CriadorCastelo::criarFantasmas(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'F'){}
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

void CriadorCastelo::criarGelatinas(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n){
    int contEntidades=0;
    int contVetor=0;
    for(int i=0;i<22;i++)
        for(int j=0;j<41;j++){
            char aux = fase[i][j];
            if(aux != 'g'){}
            else{
                if(v[contVetor]==contEntidades){
                    add(lo,new Entidades::Gelatina(sf::Vector2f((j + 1)*30+ 25, (i+1)*30+ 15)));
                    contVetor++;
                    if(contVetor>=n)
                        return;   
                }
                contEntidades++;
            }
        }   
}

void CriadorCastelo::recuperarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li){
   recuperarFantasmas(li);
   recuperarRosquinhas(li);
}


void CriadorCastelo::recuperarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    recuperarFioDental(lo);
    recuperarPlataformas(lo);
    recuperarGelatinas(lo);
}


void CriadorCastelo::recuperarGelatinas(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    std::ifstream ifs("../../salvamento/Gelatina.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); 
                if(posicao == sf::Vector2f(-1.f,-1.f))
                    break;
            add(lo,new Entidades::Gelatina(posicao));
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de Gelatinas." << std::endl;
    }
}

void CriadorCastelo::recuperarFantasmas(Listas::ListaEntidade<Entidades::Inimigo>* li){
    std::ifstream ifs("../../salvamento/Fantasma.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); 
            if(posicao == sf::Vector2f(-1.f,-1.f))
                break;
            Entidades::Fantasma* aux = new Entidades::Fantasma(posicao);
            int vidas;
            ifs>>vidas;
            aux->setVidas(vidas);
            add(li,aux);
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de Fantasmas." << std::endl;
    }
}