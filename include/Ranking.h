#pragma once
#include <stdafx.h>

class Ranking{
    protected:
    std::string arquivo;
    sf::Font fonte;
    public:
    Ranking();
    ~Ranking();

    void salvar(const std::string& nome, int pontos);
    
    void recuperar(std::multimap<int,std::string>& dados);

    void mostrar();

    std::string getNome();
};