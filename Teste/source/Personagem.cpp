#include "../headers/Personagem.h"
//#include "../lib/Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, const char* caminhoTextura) : posicao{pos}, v{vel}, text{nullptr}{
    if(caminhoTextura){

        text = new sf::Texture();
        text->loadFromFile(caminhoTextura);
    }

    corpo.setTexture(text);
    corpo.setSize(sf::Vector2f(200.0f,200.0f));
    corpo.setOrigin(corpo.getSize()/ 2.0f);
}

Personagem::~Personagem(){
    if (text)
        delete text;
}

void Personagem::atualizar(float t){
    posicao += v*t;
    corpo.setPosition(posicao);
}

void Personagem::desenhar(sf::RenderWindow* janela){
    janela->draw(corpo);

    //sf::RectangleShape help;
    //sf::Texture tex;
    //tex.loadFromFile("Brasil_Countryball.png");
    //help.setTexture(&tex);
    //help.setSize(sf::Vector2f(sf::Vector2f(100, 100)));
    //help.setPosition(sf::Vector2f(200, 200));

    //janela->draw(help);

}
