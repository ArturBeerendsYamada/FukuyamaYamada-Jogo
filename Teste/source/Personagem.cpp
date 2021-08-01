#include "../headers/Personagem.h"
//#include "../lib/Personagem.h"

Personagem::Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) : posicao{pos}, v{vel}, caminho{caminhoTextura}{
}

Personagem::~Personagem(){

}

void Personagem::inicializar(GerenciadorGrafico &g){
    g.carregarTextura(caminho);
}

void Personagem::atualizar(float t){
    posicao += v*t;
}

void Personagem::desenhar(GerenciadorGrafico &g){
    g.desenhar(caminho, posicao);

    //sf::RectangleShape help;
    //sf::Texture tex;
    //tex.loadFromFile("Brasil_Countryball.png");
    //help.setTexture(&tex);
    //help.setSize(sf::Vector2f(sf::Vector2f(100, 100)));
    //help.setPosition(sf::Vector2f(200, 200));

    //janela->draw(help);

}
