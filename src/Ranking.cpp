#include <Ranking.h>
#include <gerenciadores/GerenciadorGrafico.h>


Ranking::Ranking() : arquivo("../../Ranking.txt") {
    try {
        std::ifstream arquivoIn(arquivo);

        if (!arquivoIn.is_open()) {
            throw std::runtime_error("Falha ao abrir o arquivo " + arquivo);
        }
        arquivoIn.close();
    } catch (const std::exception& e) {
        std::ofstream arquivoOut(arquivo);
        if(!arquivoOut.is_open())
            std::cout << "Erro: " << e.what() << std::endl;
    }
    if(!fonte.loadFromFile("../../imagens/04B_30__.TTF"));
        
}

Ranking::~Ranking() {}

void Ranking::salvar(const std::string& nome, int pontos) {
    std::multimap<int, std::string> dados;
    recuperar(dados);
    dados.insert(std::make_pair(pontos, nome));

    if (dados.size() > 10) {
        auto it = dados.end();
        std::advance(it, -10);
        dados.erase(dados.begin(), it);
    }

    std::ofstream arquivoOut(arquivo);

    if (arquivoOut.is_open()) {
        for (auto it = dados.rbegin(); it != dados.rend(); ++it) {
            arquivoOut << it->second << " " << it->first << std::endl;
        }
        arquivoOut.close();
    } else {
        std::cout << "Erro ao abrir o arquivo " << arquivo << std::endl;
    }
}

void Ranking::recuperar(std::multimap<int, std::string>& dados) {
    std::ifstream arquivoIn(arquivo);

    if (arquivoIn.is_open()) {
        dados.clear();
        std::string nome;
        int pontos;
        while (arquivoIn >> nome >> pontos) {
            dados.insert(std::make_pair(pontos, nome));
        }
        arquivoIn.close();
    } else {
        std::cout << "Erro ao abrir o arquivo " << arquivo << std::endl;
    }
}

void Ranking::mostrar() {
    std::multimap<int, std::string> dados;
    recuperar(dados);

    Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getInstance();

    sf::Text texto;
    texto.setFont(fonte);
    texto.setCharacterSize(20);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(100, 100);

    std::string rankingStr = "Ranking:\n";
    for (auto it = dados.rbegin(); it != dados.rend(); ++it) {
        rankingStr += it->second + " - " + std::to_string(it->first) + " pontos\n";
    }
    texto.setString(rankingStr);

    while (gg->aberto()) {
        gg->limpar();
        gg->desenhar(texto);
        gg->mostrar();

        sf::Event evento;
        while (gg->adicionarEvento(evento)) {
            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) {
                return;
            }
        }
    }
}





std::string Ranking::getNome() {
    Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getInstance();

    std::string nome;

    while (gg->aberto()) {
        gg->limpar();

        sf::Text texto; texto.setFont(fonte);
        texto.setString(nome);
        texto.setCharacterSize(50);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(200, 200);
        gg->desenhar(texto);
        gg->mostrar();

        sf::Event evento;
        while (gg->adicionarEvento(evento)) {
            if (evento.type == sf::Event::TextEntered) {
                if (evento.text.unicode == '\b' && !nome.empty()) {
                    nome.pop_back();
                } else if (evento.text.unicode < 128 && evento.text.unicode != '\b') {
                    nome += static_cast<char>(evento.text.unicode);
                }
            } else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
                return nome;
            }
        }

        sf::sleep(sf::milliseconds(15));
    }

    return "";
}

