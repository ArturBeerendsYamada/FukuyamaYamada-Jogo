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
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	Entidade* temp = static_cast<Entidade*>(new Jogador(Vetor2F(0.0f, 0.0f), "Brasil_Countryball.png", Vetor2F(800.f, 800.f), Vetor2F(150.f, 150.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 600.0f), "Italia_Countryball.png", Vetor2F(0.f, 0.f), Vetor2F(150.f, 150.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(0.0f, 600.0f), "Japan_Countryball.png", Vetor2F(100.f, 00.f), Vetor2F(150.f, 150.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 0.0f), "Alemanha_Countryball.png", Vetor2F(0.f, 0.f), Vetor2F(150.f, 150.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(1000.0f, 1000.0f), "Russia_Countryball.png", Vetor2F(00.f, 00.f), Vetor2F(150.f, 150.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	ListaBolas.inicializarEntidades(*gerenciadorGrafico);

	executar();
}

void Fase_teste::executar()
{
	sf::Time t;
	sf::Event event;
	//unsigned int win_lose_continue = 0;

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
		gerenciador_colisoes_fase_teste->verificarColisoes();
		ListaBolas.desenharEntidades(*gerenciadorGrafico);
		gerenciadorGrafico->mostrar();

		if(gerenciador_comandos_fase_teste->comandosFuncionalidades()==GerenciadorComandos::comeco)
		{
			gerenciadorGrafico->getJanela()->close();
		}
	}
}