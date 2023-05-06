#include <gtest/gtest.h>
#include <gerenciadores/GerenciadorGrafico.h>


/// @brief 
/// @param  
/// @param  
TEST(GerenciadorGraficoTest, Singleton) {
    auto gerenciador1 = gerenciadores::GerenciadorGrafico::getInstance();
    auto gerenciador2 = gerenciadores::GerenciadorGrafico::getInstance();

    ASSERT_EQ(gerenciador1, gerenciador2);
}

TEST(GerenciadorGraficoTest, DesenharObjeto) {
    auto gerenciador = gerenciadores::GerenciadorGrafico::getInstance();

    sf::RectangleShape objeto(sf::Vector2f(50, 50));
    objeto.setPosition(100, 100);
    objeto.setFillColor(sf::Color::Red);

    gerenciador->desenhar(objeto);
    gerenciador->mostrar();

    ASSERT_TRUE(gerenciador->aberto());
}

TEST(GerenciadorGraficoTest, DesenharTexto) {
    auto gerenciador = gerenciadores::GerenciadorGrafico::getInstance();

    sf::Font fonte;
    fonte.loadFromFile("../../Lobster-Regular.ttf");

    sf::Text texto("Teste de Texto", fonte, 20);
    texto.setPosition(200, 200);
    texto.setFillColor(sf::Color::Blue);

    gerenciador->desenhar(texto);
    gerenciador->mostrar();

    ASSERT_TRUE(gerenciador->aberto());
}
