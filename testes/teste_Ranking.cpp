#include <gtest/gtest.h>
#include <stdafx.h>
#include <Ranking.h>

#include <fstream>

void limparArquivo(const std::string& arquivo) {
    std::ofstream ofs(arquivo, std::ios::trunc);
    ofs.close();
}

class RankingTest: public Ranking{
    public:
    RankingTest(){
        arquivo = std::string("ranking teste.txt");
    }
    ~RankingTest(){
        limparArquivo(arquivo);
    }
};


TEST(RankingTeste, SalvarRecuperar) {
    // Crie uma instância da classe Ranking
    RankingTest ranking;

    // Salve alguns dados no ranking
    ranking.salvar("Joao", 100);
    ranking.salvar("Maria", 200);

    // Recupere os dados do ranking
    std::multimap<int, std::string> dados;
    ranking.recuperar(dados);

    // Verifique se os dados foram recuperados corretamente
    ASSERT_EQ(dados.size(), 2);
    ASSERT_EQ(dados.count(100), 1);
    ASSERT_EQ(dados.count(200), 1);
}


