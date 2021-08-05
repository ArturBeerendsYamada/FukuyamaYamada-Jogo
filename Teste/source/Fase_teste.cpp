#include "../lib/Fase_teste.h"

#include <iostream>
using namespace std;

Fase_teste::Fase_teste()
{
}
Fase_teste::~Fase_teste()
{
	ListaBolas.destruirEntidades();
	delete gerenciadorGrafico;
}

void Fase_teste::inicializar()
{
	gerenciadorGrafico = new GerenciadorGrafico;
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	ListaBolas.inserir(static_cast<Entidade*>(new Jogador(Vetor2F(0.0f, 0.0f), "Brasil_Countryball.png", Vetor2F(200.f, 200.f))));
	ListaBolas.inserir(static_cast<Entidade*>(new Personagem(Vetor2F(400.0f, 300.0f), "Italia_Countryball.png", Vetor2F(100.f, 0.f))));
	ListaBolas.inserir(static_cast<Entidade*>(new Personagem(Vetor2F(200.0f, 200.0f), "Japan_Countryball.png", Vetor2F(0.f, 500.f))));
	ListaBolas.inserir(static_cast<Entidade*>(new Personagem(Vetor2F(800.0f, 600.0f), "Alemanha_Countryball.png", Vetor2F(0.f, 0.f))));
	ListaBolas.inserir(static_cast<Entidade*>(new Personagem(Vetor2F(400.0f, 0.0f), "Russia_Countryball.png", Vetor2F(200.f, 200.f))));

	ListaBolas.inicializarEntidades(*gerenciadorGrafico);

	executar();
}

void Fase_teste::executar()
{
	sf::Time t;
	sf::Event event;

	relogio.restart();

	while (gerenciadorGrafico->getJanela()->isOpen())
	{
		while (gerenciadorGrafico->getJanela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gerenciadorGrafico->getJanela()->close();
		}

		t = relogio.restart();
		//float scaler = 0.001;
		gerenciadorGrafico->limpar();
		ListaBolas.atualizarEntidades(t.asSeconds());
		ListaBolas.desenharEntidades(*gerenciadorGrafico);
		gerenciadorGrafico->mostrar();

		if(gerenciador_comandos_fase_teste->comandosFuncionalidades()==GerenciadorComandos::comeco)
		{
			gerenciadorGrafico->getJanela()->close();
		}
	}
}