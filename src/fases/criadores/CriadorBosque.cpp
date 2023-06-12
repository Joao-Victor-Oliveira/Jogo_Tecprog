#include <fases/criadores/CriadorBosque.h>
#include <ente/entidades/inimigos/Cookie.h>
#include <ente/entidades/obstaculos/Pirulitos.h>

using namespace Fases;


char mFase1[22][41] = {//9 A //8 D -- //6 f //5 p
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','D','*','*','*','D','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','*','*','*','*','*','*','*','f','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','A','*','*','*','*','*','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*','*','A','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','D','*','*','*','*','*','*','f','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*','*','f','*','*'},
    {'*','*','#','#','#','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','*','*','*','*','*','*','*','*','#','#','#','#','*','*','*','*','*','*','#','#','#'},
    {'*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','f','*','*','*','*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','*','*','*','*'},
    {'*','*','*','*','*','*','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','p','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','f','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','*','*','*','*'},
    {'*','*','*','*','*','p','*','*','*','*','*','*','*','A','*','*','*','*','*','*','*','#','#','*','*','*','*','*','*','*','*','*','#','#','#','#','#','*','*','*','*'},
    {'*','*','*','*','*','#','#','#','*','p','*','*','*','*','*','*','*','p','*','*','#','#','#','#','p','*','*','*','D','*','f','#','#','#','#','#','#','*','*','*','*'}
};



#define CMIN 5
#define CMAX 9

#define RMIN 6
#define RMAX 8

#define FDMAX 6
#define FDMIN 3

#define PMAX 5
#define PMIN 3

CriadorBosque::CriadorBosque():
num_Cookies(gerar(CMIN,CMAX)),
num_Pirulitos(gerar(PMIN,PMAX))
{
    num_Rosquinhas = gerar(RMIN,RMAX);
    num_FioDental = gerar(FDMIN,FDMAX);
}

CriadorBosque::~CriadorBosque(){}


void CriadorBosque::criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li){
    int *v =  (int*) malloc(num_Rosquinhas*sizeof(int));
    preencher(v,RMAX,num_Rosquinhas);
    criarRosquinhas(li,mFase1,v,num_Rosquinhas);
    free(v);

    v =  (int*) malloc(num_Cookies*sizeof(int));
    preencher(v,CMAX,num_Cookies);
    criarCookies(li,mFase1,v,num_Cookies);
    free(v);
}


void CriadorBosque::criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    criarLimites(lo,mFase1);

    int *v =  (int*) malloc(num_FioDental*sizeof(int));
    preencher(v,FDMAX,num_FioDental);
    criarFioDental(lo,mFase1,v,num_FioDental);
    free(v);

    v =  (int*) malloc(num_Pirulitos*sizeof(int));
    preencher(v,PMAX,num_Pirulitos);
    criarPirulitos(lo,mFase1,v,num_Pirulitos);
    free(v);
}

void CriadorBosque::criarCookies(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n){
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

void CriadorBosque::criarPirulitos(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n){
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


void CriadorBosque::recuperarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li){
    recuperarRosquinhas(li);
    recuperarCookies(li);
}

void CriadorBosque::recuperarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    recuperarPlataformas(lo);
    recuperarFioDental(lo);
    recuperarPirulitos(lo);
}

void CriadorBosque::recuperarCookies(Listas::ListaEntidade<Entidades::Inimigo>* li){
    std::ifstream ifs("../../salvamento/Cookie.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); if(posicao == sf::Vector2f(-1.f,-1.f))
                break;
            int tem_bala,vidas;
            ifs>>vidas >>tem_bala;
            sf::Vector2f posicao_bala = recuperarPos(ifs);
            sf::Vector2f vel = recuperarPos(ifs);
            Entidades::Cookie* cookie = new Entidades::Cookie(posicao);
            cookie->setVidas(vidas);
            if(!tem_bala)
                add(li,new Entidades::Cookie(posicao));
            else{
                Entidades::Projetil* bala = new Entidades::Projetil(1,"../../imagens/inimigos/Projetil.png",posicao_bala,sf::Vector2f(15,15),vel);
                bala->ativo = true;
                cookie->setBala(bala);
                add(li,cookie);
            }
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de rosquinhas." << std::endl;
    }
}


void CriadorBosque::recuperarPirulitos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    std::ifstream ifs("../../salvamento/Pirulitos.txt");
    if (ifs.is_open()) {
        while (ifs) {
            sf::Vector2f posicao = recuperarPos(ifs); if(posicao == sf::Vector2f(-1.f,-1.f))break;
            int np;
            ifs >> np;
            add(lo,new Entidades::Pirulitos(np,posicao));
        }
        ifs.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de rosquinhas." << std::endl;
    }
}