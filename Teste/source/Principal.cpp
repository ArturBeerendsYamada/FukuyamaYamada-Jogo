//#include "../headers/Principal.h"
#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal()//:
    //janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "TheBallGame")}
    //amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png")
    {
        //janela->setPosition({0, 0});
        ListaBolas.inserir( new Personagem(Vetor2F(0.0f, 0.0f), Vetor2F(5,5), "Brasil_Countryball.png"));
        ListaBolas.inserir( new Personagem(Vetor2F(400.0f, 300.0f), Vetor2F(10,0), "Italia_Countryball.png"));
        ListaBolas.inserir( new Personagem(Vetor2F(200.0f, 200.0f), Vetor2F(0,5), "Japan_Countryball.png"));
        ListaBolas.inserir( new Personagem(Vetor2F(800.0f, 600.0f), Vetor2F(0,0), "Alemanha_Countryball.png"));
        ListaBolas.inserir( new Personagem(Vetor2F(400.0f, 0.0f), Vetor2F(5,5), "Russia_Countryball.png"));

        ListaBolas.inicializarPersonagens(gerenciadorGrafico);
    }

Principal::~Principal(){
    //delete janela;

    ListaBolas.destruirPersonagens();
}

int Principal::executar(){
    sf::Event event;

    relogio.restart();

    while (gerenciadorGrafico.getJanela()->isOpen()){
        while (gerenciadorGrafico.getJanela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gerenciadorGrafico.getJanela()->close();
		}

        sf::Time t= relogio.getElapsedTime();

        gerenciadorGrafico.limpar();
        ListaBolas.atualizarPersonagens(t.asSeconds());
        ListaBolas.desenharPersonagens(gerenciadorGrafico);
        gerenciadorGrafico.mostrar();

        relogio.restart();
    }
    return 0;
}
