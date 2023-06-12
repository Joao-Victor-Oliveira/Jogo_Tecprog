#include <fases/CasteloAssombrado.h>
#include <fases/BosqueDosCookies.h>
#include <fases/criadores/CriadorBosque.h>
#include <gtest/gtest.h>
using namespace Fases;
using namespace Entidades;
#include <csignal>
#include <stdexcept>
#include <ente/entidades/inimigos/Rosquinha.h>
#include <ente/entidades/obstaculos/Plataforma.h>
#include <listas/ListaEntidade.h>
#include <fases/criadores/CriadorCastelo.h>

using namespace Listas;


void segfault_handler2(int sig) {
  throw std::runtime_error("Segmentation fault");
}


TEST(CriadorEntidadesTest, Add) {
    CriadorCastelo criador;
    CriadorBosque criador2;
    ListaEntidade<Inimigo> li;
    ListaEntidade<Obstaculo> lo;

    Inimigo* inimigo = new Rosquinha();
    Obstaculo* obstaculo = new Plataforma();

    EXPECT_NO_THROW(criador.add(&li, inimigo));
    EXPECT_NO_THROW(criador.add(&lo, obstaculo));

    EXPECT_NO_THROW(criador2.add(&li, inimigo));
    EXPECT_NO_THROW(criador2.add(&lo, obstaculo));

    delete obstaculo;
    delete inimigo;
}

TEST(CriadorEntidadesTest, ListaNula){
    CriadorCastelo criador;

    ListaEntidade<Inimigo>* li =NULL;
    ListaEntidade<Obstaculo>* lo =NULL;

    Inimigo* inimigo = new Rosquinha();
    Obstaculo* obstaculo = new Plataforma();
    EXPECT_THROW(criador.add(li, inimigo),std::invalid_argument);
    EXPECT_THROW(criador.add(lo, obstaculo),std::invalid_argument);
}

TEST(CriadorEntidadesTest, EntidadeNula){
    CriadorCastelo criador;
    ListaEntidade<Inimigo> li;
    ListaEntidade<Obstaculo> lo;

    Inimigo* inimigo = NULL;
    Obstaculo* obstaculo = NULL;

    EXPECT_THROW(criador.add(&li, inimigo),std::invalid_argument);
    EXPECT_THROW(criador.add(&lo, obstaculo),std::invalid_argument);
}


TEST(FaseTest,Execucao){
    signal(SIGSEGV, segfault_handler2);
    Ente::setGG(Gerenciadores::GerenciadorGrafico::getInstance());
    CasteloAssombrado teste01(0),teste02(1);

    EXPECT_NO_THROW(teste01.executar());
    EXPECT_NO_THROW(teste02.executar());
}