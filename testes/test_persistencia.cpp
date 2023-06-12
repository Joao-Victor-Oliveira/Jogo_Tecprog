#include <ente/entidades/inimigos/Rosquinha.h>
#include <fstream>
#include <gtest/gtest.h>
#include <stdafx.h>
#include <Ranking.h>

#include <listas/ListaEntidade.h>
#include <fases/criadores/CriadorBosque.h>
#include <ente/entidades/Jogador.h>

#include <filesystem>

using namespace Fases;
using namespace Listas;
using namespace Entidades;


TEST(Persistencia, posicao){
    try {
        for (const auto& entry : std::filesystem::directory_iterator("../../salvamento/")) {
            if (entry.is_regular_file()) {
                std::filesystem::remove(entry.path());
                std::cout << "Arquivo excluído: " << entry.path() << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Erro ao excluir arquivos do diretório: " << e.what() << std::endl;
    }

    ListaEntidade<Inimigo> li;
    li.adicionar(new Rosquinha(sf::Vector2f(300.f,300.f)));
    li.salvar();
    CriadorBosque bc;

    std::ifstream ifs("../../salvamento/Rosquinha.txt");
    EXPECT_FLOAT_EQ(bc.recuperarPos(ifs).x,300.f);
}

TEST(Persistencia, jogador){
    try {
        for (const auto& entry : std::filesystem::directory_iterator("../../salvamento/")) {
            if (entry.is_regular_file()) {
                std::filesystem::remove(entry.path());
                std::cout << "Arquivo excluído: " << entry.path() << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Erro ao excluir arquivos do diretório: " << e.what() << std::endl;
    }
    Jogador* player = new Jogador;
    player->danar_se(9);
    player->setPosicao(sf::Vector2f(200.f,200.f));
    player->salvar();
    delete player;
    
    Jogador jog;
    jog.recuperar();
    EXPECT_EQ(jog.getVidas(),1);
    EXPECT_FLOAT_EQ(jog.getPosicao().x,200.f);
    EXPECT_FLOAT_EQ(jog.getPosicao().y,200.f);
}