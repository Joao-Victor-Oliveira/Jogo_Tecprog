#include <gtest/gtest.h>
#include <stdafx.h>
#include <ente/menus/Menu.h>
#include <ente/menus/Estado.h>
#include <csignal>

void segfault_handler(int sig) {
  throw std::runtime_error("Segmentation fault");
}

class MenuTest:public Estado{
    public:
    void executar()override{};
    void setTextos()override{};
};
    
    //Estado nulo e gg nulo
TEST(MenuTest, SegfaultTest){
    signal(SIGSEGV, segfault_handler);
    
    Ente::setGG(NULL);
    Menu m;
    m.setEstado(NULL);
    EXPECT_NO_THROW(m.executar());
}
    
    //Estado genérico
TEST(MenuTest, SegfaultTest2){
    Menu m;
    Ente::setGG( Gerenciadores::GerenciadorGrafico::getInstance());
    MenuTest* mt=nullptr;
    m.setEstado(dynamic_cast <Estado*> (mt));
    EXPECT_NO_THROW(m.executar());
}
