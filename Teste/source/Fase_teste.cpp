
#include "Fase_teste.h"

#include <iostream>
using namespace std;

Fase_teste::Fase_teste()
{
}
Fase_teste::~Fase_teste()
{
	ListaBolas.destruirPersonagens();
	delete gerenciadorGrafico;
}

void Fase_teste::inicializar()
{
	gerenciadorGrafico = new GerenciadorGrafico;

	ListaBolas.inserir(new Personagem(Vetor2F(0.0f, 0.0f), Vetor2F(5, 5), "Brasil_Countryball.png"));
	ListaBolas.inserir(new Personagem(Vetor2F(400.0f, 300.0f), Vetor2F(10, 0), "Italia_Countryball.png"));
	ListaBolas.inserir(new Personagem(Vetor2F(200.0f, 200.0f), Vetor2F(0, 5), "Japan_Countryball.png"));
	ListaBolas.inserir(new Personagem(Vetor2F(800.0f, 600.0f), Vetor2F(0, 0), "Alemanha_Countryball.png"));
	ListaBolas.inserir(new Personagem(Vetor2F(400.0f, 0.0f), Vetor2F(5, 5), "Russia_Countryball.png"));

	ListaBolas.inicializarPersonagens(*gerenciadorGrafico);

	executar();
}

void Fase_teste::executar()
{
	sf::Event event;

	relogio.restart();

	while (gerenciadorGrafico->getJanela()->isOpen())
	{
		while (gerenciadorGrafico->getJanela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gerenciadorGrafico->getJanela()->close();
		}

		//sf::Time t = relogio.getElapsedTime();
		float scaler = 0.001;
		gerenciadorGrafico->limpar();
		ListaBolas.atualizarPersonagens(/*t.asSeconds()*/ scaler);
		ListaBolas.desenharPersonagens(*gerenciadorGrafico);
		gerenciadorGrafico->mostrar();

		relogio.restart();
	}
}