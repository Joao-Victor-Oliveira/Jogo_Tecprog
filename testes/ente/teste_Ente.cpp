#include <gtest/gtest.h>
#include <stdafx.h>
#include <ente/Ente.h>

class EnteTeste : public Ente {
public:
    void executar() override {}
    void draw() override {}
    const Gerenciadores::GerenciadorGrafico* GetGG() const {return gg;}
};
// Testa se o ID dos Entes é incrementado corretamente
TEST(EnteTest, TestIncrementoID) {
  EnteTeste e1;
  EnteTeste e2;
  EnteTeste e3;
  EXPECT_EQ(e2.getID(), e1.getID()+1);
  EXPECT_EQ(e3.getID(), e2.getID()+1);
}

// Testa se o GerenciadorGrafico é configurado corretamente
TEST(EnteTest, TestSetGerenciadorGrafico) {
  Ente::setGG(Gerenciadores::GerenciadorGrafico::getInstance());
  EnteTeste e1;
  EnteTeste e2;
  EXPECT_EQ(e1.GetGG(),e2.GetGG());
}

// Testa se o ID retornado é o mesmo do construtor
TEST(EnteTest, TestGetID) {
  EnteTeste e1;
  EnteTeste e2;
  EXPECT_EQ(e1.getID(), e1.getID());
  EXPECT_EQ(e2.getID(), e2.getID());
}

