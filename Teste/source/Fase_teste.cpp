#include "../lib/Fase_teste.h"


#include <iostream>
using namespace std;

Fase_teste::Fase_teste()
{
	printf("nova fase de testes\n");
}
Fase_teste::~Fase_teste()
{
	printf("deletando fase teste\n");
	ListaBolas.destruirEntidades();
	delete gerenciador_colisoes_fase_teste;
	delete j;
}

void Fase_teste::inicializar(GerenciadorGrafico* gg)
{
	printf("iniciando fase de testes\n");

	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	Entidade* temp;

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(1200.0f, 0.0f), "Russia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(0.0f, 1200.0f), "Praia.jpg", Vetor2F(1000.f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);


	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 600.0f), "Italia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	j = (new Jogador(Vetor2F(0.0f, 1000.0f), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));

	temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(1000.0f, 1400.0f), "Floresta.jpg", Vetor2F(1000.f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(1000.0f, 600.0f), "Japan_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 0.0f), "Alemanha_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaBolas.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	ListaBolas.inicializarEntidades(*gg);
}

int Fase_teste::executar(GerenciadorGrafico* gg)
{
	sf::Time t;

	t = relogio.restart();
	gg->limpar();
	ListaBolas.atualizarEntidades(t.asSeconds());
	gerenciador_colisoes_fase_teste->verificarColisoes();
	ListaBolas.desenharEntidades(*gg);
	gg->mostrar();

	if (j->getVida() == false)
	{
		return IdsMenu::fase0_abre;
	}
	if (gerenciador_comandos_fase_teste->comandosFuncionalidades() == GerenciadorComandos::Comandos::comeco)
	{
		return IdsMenu::menu_abre;
	}
	return IdsMenu::fase0_continua;
}