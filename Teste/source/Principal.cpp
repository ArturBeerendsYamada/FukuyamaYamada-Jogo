#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal():
    janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "exercicio 1")},
    amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png"){
        janela->setPosition({0, 0});
}

Principal::~Principal(){
    delete janela;
}

int Principal::executar(){
    sf::Event event;
    while (janela->isOpen()){
        while (janela->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				janela->close();
		}
        janela->clear();
        amigo.atualizar();
        amigo.desenhar(janela);
        janela->display();
    }
    return 0;
}