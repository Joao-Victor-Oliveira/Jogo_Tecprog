#include "gtest/gtest.h"
#include <listas/Lista.h>

TEST(ListaTest, PushBack) {
    Listas::Lista<int> lista;
    lista.push_back(new int(1));
    lista.push_back(new int(2));
    lista.push_back(new int(3));
    EXPECT_EQ(3u, lista.getTamanho());
}

TEST(ListaTest, PushFront) {
    Listas::Lista<int> lista;
    lista.push_front(new int(1));
    lista.push_front(new int(2));
    lista.push_front(new int(3));
    EXPECT_EQ(3u, lista.getTamanho());
}

TEST(ListaTest, PopBack) {
    Listas::Lista<int> lista;
    lista.push_back(new int(1));
    lista.push_back(new int(2));
    lista.push_back(new int(3));
    EXPECT_EQ(3, *lista.pop_back());
    EXPECT_EQ(2u, lista.getTamanho());
    EXPECT_EQ(2, *lista.pop_back());
    EXPECT_EQ(1u, lista.getTamanho());
    EXPECT_EQ(1, *lista.pop_back());
    EXPECT_EQ(0u, lista.getTamanho());
}

TEST(ListaTest, PopFront) {
    Listas::Lista<int> lista;
    lista.push_back(new int(1));
    lista.push_back(new int(2));
    lista.push_back(new int(3));
    EXPECT_EQ(1, *lista.pop_front());
    EXPECT_EQ(2u, lista.getTamanho());
    EXPECT_EQ(2, *lista.pop_front());
    EXPECT_EQ(1u, lista.getTamanho());
    EXPECT_EQ(3, *lista.pop_front());
    EXPECT_EQ(0u, lista.getTamanho());
}

TEST(ListaTest, Remover) {
    Listas::Lista<int> lista;
    int* alvo1 = new int(1);
    int* alvo2 = new int(2);
    int* alvo3 = new int(3);
    lista.push_back(alvo1);
    lista.push_back(alvo2);
    lista.push_back(alvo3);
    EXPECT_TRUE(lista.remover(alvo2));
    EXPECT_EQ(2u, lista.getTamanho());
    EXPECT_EQ(alvo1, lista[0]);
    EXPECT_EQ(alvo3, lista[1]);
}

TEST(ListaTest, GetTamanho) {
    Listas::Lista<int> lista;
    lista.push_back(new int(1));
    lista.push_back(new int(2));
    lista.push_back(new int(3));
    EXPECT_EQ(3u, lista.getTamanho());
}

TEST(ListaTest, Empty) {
    Listas::Lista<int> lista;
    EXPECT_TRUE(lista.empty());
    lista.push_back(new int(1));
    EXPECT_FALSE(lista.empty());
    lista.pop_back();
    EXPECT_TRUE(lista.empty());
}

TEST(ListaTeste, TesteOperatorPosicaoValida) {
    Listas::Lista<int> lista;
    lista.push_back(new int(10));
    lista.push_back(new int(20));
    lista.push_back(new int(30));
    EXPECT_EQ(20, *(lista[1]));
}

TEST(ListaTeste, TesteOperatorPosicaoInvalida) {
    Listas::Lista <int> teste;
    EXPECT_THROW(teste.operator[](2),std::invalid_argument);
}
