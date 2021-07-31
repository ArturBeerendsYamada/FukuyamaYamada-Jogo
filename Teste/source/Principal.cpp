#include "../headers/Principal.h"
//#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal():
    janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "TheBallGame")}
    //amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png")
    {
        janela->setPosition({0, 0});
        ListaBolas.inserir( new Personagem(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5,5), "Brasil_Countryball.png"));
        ListaBolas.inserir( new Personagem(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(10,0), "Italia_Countryball.png"));
        ListaBolas.inserir( new Personagem(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(0,5), "Japan_Countryball.png"));
        ListaBolas.inserir( new Personagem(sf::Vector2f(800.0f, 600.0f), sf::Vector2f(0,0), "Alemanha_Countryball.png"));
        ListaBolas.inserir( new Personagem(sf::Vector2f(400.0f, 0.0f), sf::Vector2f(5,5), "Russia_Countryball.png"));
    }

Principal::~Principal(){
    delete janela;

    ListaBolas.destruirPersonagens();
}

int Principal::executar(){
    sf::Event event;
    
    relogio.restart();

    while (janela->isOpen()){
        while (janela->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				janela->close();
		}
        
        sf::Time t= relogio.getElapsedTime();

        janela->clear();
        ListaBolas.atualizarPersonagens(t.asSeconds());
        ListaBolas.desenharPersonagens(janela);
        janela->display();

        relogio.restart();
    }
    return 0;
}
