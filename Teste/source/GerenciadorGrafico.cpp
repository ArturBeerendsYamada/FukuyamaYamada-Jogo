#include "../lib/GerenciadorGrafico.h"
#include <iostream>

GerenciadorGrafico::GerenciadorGrafico():
    janela{new sf::RenderWindow(sf::VideoMode(800,600), "Game")},
    camera{sf::Vector2f(400.f,300.f),sf::Vector2f(1600.f,1200.f)}
{
    janela->setView(camera);
}

GerenciadorGrafico::~GerenciadorGrafico(){
    delete janela;

    for (auto i = texturas.begin(); i != texturas.end(); ++i){
        delete i->second;
    }
}

void GerenciadorGrafico::mostrar() const{
    janela->display();
}

void GerenciadorGrafico::limpar(int r, int g, int b){
    janela->clear(sf::Color(r,g,b));
}

void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor2F posicao){
    if (texturas.count(caminho) == 0){
        std::cout << "OPA! Imagem nao carregada em " << caminho << std::endl;
        exit(121);
    }

    sf::Texture* text = texturas[caminho];

    sf::Sprite sprite;

    text->setSmooth(true);

    sprite.setTexture(*text);
    sprite.setOrigin(sf::Vector2f(100.0, 100.0));
    sprite.setScale(sf::Vector2f((200.0/text->getSize().x),(200.0/text->getSize().y)));
    sprite.setPosition(posicao.x, posicao.y);
    janela->setView(camera);
    janela->draw(sprite);
}

bool GerenciadorGrafico::carregarTextura(const std::string& caminho){
    if (texturas.count(caminho) == 1) return true;
    else{
        sf::Texture* text = new sf::Texture();
        if(!text->loadFromFile(caminho)){
            std::cout << "OPA! Imagem nao encontrada em " << caminho << std::endl;
            exit(120);
        }

        texturas.emplace(caminho, text);
        return true;
    }
}

void GerenciadorGrafico::centralizar(const Vetor2F centro){
    camera.setCenter(sf::Vector2f(centro.x, centro.y));
}

sf::RenderWindow* GerenciadorGrafico::getJanela() const{
    return janela;
}

std::map<const std::string, sf::Texture*> GerenciadorGrafico::getTextura(){
    return texturas;
}

