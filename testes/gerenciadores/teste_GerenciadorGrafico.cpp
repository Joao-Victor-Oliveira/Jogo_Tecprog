#include <gtest/gtest.h>
#include <gerenciadores/GerenciadorGrafico.h>


/// @brief 
/// @param  
/// @param  
TEST(GerenciadorGraficoTest, Singleton) {
    auto gerenciador1 = Gerenciadores::GerenciadorGrafico::getInstance();
    auto gerenciador2 = Gerenciadores::GerenciadorGrafico::getInstance();

    ASSERT_EQ(gerenciador1, gerenciador2);
}

TEST(GerenciadorGraficoTest, DesenharObjeto) {
    auto gerenciador = Gerenciadores::GerenciadorGrafico::getInstance();

    sf::RectangleShape objeto(sf::Vector2f(50, 50));
    objeto.setPosition(100, 100);
    objeto.setFillColor(sf::Color::Red);

    gerenciador->desenhar(objeto);
    gerenciador->mostrar();

    ASSERT_TRUE(gerenciador->aberto());
}

TEST(GerenciadorGraficoTest, DesenharTexto) {
    auto gerenciador = Gerenciadores::GerenciadorGrafico::getInstance();

    sf::Font fonte;
    fonte.loadFromFile("../../imagens/Lobster-Regular.ttf");

    sf::Text texto("Teste de Texto", fonte, 20);
    texto.setPosition(200, 200);
    texto.setFillColor(sf::Color::Blue);

    gerenciador->desenhar(texto);
    gerenciador->mostrar();

    ASSERT_TRUE(gerenciador->aberto());
}

TEST(GerenciadorGraficoTest, Argumentos_inválidos){
    auto gerenciador = Gerenciadores::GerenciadorGrafico::getInstance();
    sf::Drawable* ptr=nullptr;
    sf::Text* ptr2=nullptr;

    EXPECT_THROW(gerenciador->desenhar(*ptr),std::invalid_argument);
    EXPECT_THROW(gerenciador->desenhar(*ptr2),std::invalid_argument);
}
