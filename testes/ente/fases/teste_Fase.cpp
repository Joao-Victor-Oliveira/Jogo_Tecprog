#include <fases/Fase.h>
#include <fases/CriadorEntidades.h>
#include <gtest/gtest.h>
using namespace Fases;
using namespace Entidades;
#include <csignal>
#include <stdexcept>
using namespace Listas;


void segfault_handler2(int sig) {
  throw std::runtime_error("Segmentation fault");
}

class CriadorTeste:public CriadorEntidades{
    public:
    CriadorTeste(){}
    virtual ~CriadorTeste(){}
    void criarInimigos(ListaEntidade<Entidades::Inimigo>* li){for(int i=0;i<10;i++)add(li,new Inimigo);}          
    void criarObstaculos(ListaObstaculos* lo){for(int i=0;i<10;i++)add(lo,new Obstaculo);}
};

TEST(CriadorEntidadesTest, Add) {
    CriadorTeste criador;
    ListaEntidade<Entidades::Inimigo> ListaEntidade<Entidades::Inimigo>;
    ListaObstaculos listaObstaculos;

    Inimigo* inimigo = new Inimigo();
    Obstaculo* obstaculo = new Obstaculo();

    EXPECT_NO_THROW(criador.add(&ListaEntidade<Entidades::Inimigo>, inimigo));
    EXPECT_NO_THROW(criador.add(&listaObstaculos, obstaculo));

    delete obstaculo;
    delete inimigo;
}

TEST(CriadorEntidadesTest, ListaNula){
    CriadorTeste criador;
    ListaEntidade<Entidades::Inimigo>* ListaEntidade<Entidades::Inimigo>=NULL;
    ListaObstaculos* listaObstaculos=NULL;

    Inimigo* inimigo = new Inimigo();
    Obstaculo* obstaculo = new Obstaculo();
    EXPECT_THROW(criador.add(ListaEntidade<Entidades::Inimigo>, inimigo),std::invalid_argument);
    EXPECT_THROW(criador.add(listaObstaculos, obstaculo),std::invalid_argument);
}

TEST(CriadorEntidadesTest, EntidadeNula){
    CriadorTeste criador;
    ListaEntidade<Entidades::Inimigo> ListaEntidade<Entidades::Inimigo>;
    ListaObstaculos listaObstaculos;

    Inimigo* inimigo = NULL;
    Obstaculo* obstaculo = NULL;

    EXPECT_THROW(criador.add(&ListaEntidade<Entidades::Inimigo>, inimigo),std::invalid_argument);
    EXPECT_THROW(criador.add(&listaObstaculos, obstaculo),std::invalid_argument);
}


TEST(FaseTest,Execucao){
    signal(SIGSEGV, segfault_handler2);
    Ente::setGG(Gerenciadores::GerenciadorGrafico::getInstance());
    Fase teste01(new CriadorTeste),teste02;
    EXPECT_NO_THROW(teste01.executar());
    EXPECT_NO_THROW(teste02.executar());
}
