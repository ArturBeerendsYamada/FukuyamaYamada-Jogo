#include "../lib/Fase_teste.h"

#include <iostream>
#include <list>
using namespace std;

#define TILE 100.0f

Fase_teste::Fase_teste()
{
	gerenciador_grafico_fase_teste = NULL;
	gerenciador_comandos_fase_teste = NULL;
	gerenciador_colisoes_fase_teste = NULL;
	j = NULL;
}
Fase_teste::~Fase_teste()
{
	ListaEntidades.destruirEntidades();
	delete gerenciador_colisoes_fase_teste;
	delete j;
}

void Fase_teste::inicializar(GerenciadorGrafico* gg)
{
	gg->inicializarBackground("Floresta.jpg", Vetor2F(2000.0f, 700.0f));
	gerenciador_grafico_fase_teste = gg;
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	Entidade* temp = NULL;
	Japao* jap = NULL;
	int i, k;
	int matriz[7][20] = {
		{ 0, 0, 0, 0, 0, 2, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 3, 0, 0, 3, 0, 5, 0, 0, 0, 0, 7, 0, 8, 0, 4, 4 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	};
	for (i = 0; i < 7; i++)
	{
		for (k = 0; k < 20; k++)
		{
			switch (matriz[i][k])
			{
				case 1:
					temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(k * TILE, i * TILE), "Bloco.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionar(temp);
					break;

				case 2:
					temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(k * TILE, i * TILE), "OuricoTcheco.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionar(temp);
					break;

				case 3:
					temp = static_cast<Entidade*>(new ArameFarpado(Vetor2F(k * TILE, i * TILE), "ArameFarpado.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionar(temp);
					break;

				case 4:
					temp = static_cast<Entidade*>(new Mina(Vetor2F(k * TILE, i * TILE + 50.0f), "Mina.png", Vetor2F(TILE / 2, TILE / 2), Vetor2F(0.f, 0.f)));
					adicionar(temp);
					break;

				case 5:
					temp = static_cast<Entidade*>(new Inimigo(Vetor2F(k * TILE, i * TILE), "Russia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(static_cast<Inimigo*>(temp));
					break;

				case 6:
					temp = static_cast<Entidade*>(new Inimigo(Vetor2F(k * TILE, i * TILE), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(static_cast<Inimigo*>(temp));
					break;

				case 7:
					jap = (new Japao(Vetor2F(k * TILE, i * TILE), "Japan_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(static_cast<Inimigo*>(jap));
					jap->setFase(this);
					break;

				case 8:
					temp = static_cast<Entidade*>(new Inimigo(Vetor2F(k * TILE, i * TILE), "Alemanha_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(static_cast<Inimigo*>(temp));
					break;

				default:
					break;
			}
		}
	}

	j = (new Jogador(Vetor2F(0.0f, 0.0f), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));

	j->setFase(this);

	//temp = new ProjetilAmigo(Vetor2F(10000.0f, 10000.0f), "projetilAmigo.png", Vetor2F(50.0f, 50.0f), Vetor2F(200.0f, 0), true);
	//adicionar(temp);

	for (i = 0; i < ((rand() % 3)+1); i++)
	{
		temp = static_cast<Entidade*>(new Inimigo(Vetor2F(200.0f, rand() % 5 * TILE), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
		adicionarInimigo(static_cast<Inimigo*>(temp));
	}

	ListaEntidades.inicializarEntidades(*gg);
}

int Fase_teste::executar(GerenciadorGrafico* gg)
{
	sf::Time t;
	t = relogio.restart();
	gg->limpar(0xa2, 0xda, 0xff);
	gg->desenharBackground();
	ListaEntidades.atualizarEntidades(t.asSeconds());
	gerenciador_colisoes_fase_teste->verificarColisoes();
	ListaEntidades.desenharEntidades(*gg);
	gg->mostrar();
	verificarInimigos();

	if (j->getVida() == false)
	{
		//j->setVida(true);
		//j->setPosicao(Vetor2F(0.0f, 1000.0f));
		return IdsMenu::fase0_abre;
	}
	if (gerenciador_comandos_fase_teste->comandosFuncionalidades() == GerenciadorComandos::Comandos::comeco)
	{
		return IdsMenu::menu_abre;
	}
	return IdsMenu::fase0_continua;
}

void Fase_teste::adicionar(Entidade* e)
{
	ListaEntidades.inserir(e);
	gerenciador_colisoes_fase_teste->adicionarEntidade(e);
}


void Fase_teste::inicializarTextura(Entidade* e)
{
	e->inicializarTextura(gerenciador_grafico_fase_teste);
}


void Fase_teste::remover(Entidade* e)
{
	gerenciador_colisoes_fase_teste->removerEntidade(e);
	ListaEntidades.removerEntidades(e);
}

GerenciadorGrafico* Fase_teste::getGerenciadorGrafico()
{
	return gerenciador_grafico_fase_teste;
}

void Fase_teste::verificarInimigos()
{
	std::set<Inimigo*>::iterator itr1;
	std::list<Inimigo*> mortos;
	for (itr1 = inimigos.begin(); itr1 != inimigos.end(); itr1++)
	{
		Inimigo* ini = *itr1;
		if (!ini->getVida())
		{
			mortos.push_back(ini);
		}
	}

	std::list<Inimigo*>::iterator itr2;
	for (itr2 = mortos.begin(); itr2 != mortos.end(); itr2++)
	{
		Inimigo* morto = *itr2;
		remover(static_cast<Entidade*>(morto));
		inimigos.erase(morto);
		delete morto;
	}
	/*Era para imprimir nada e acaba imprimindo o endereço do ultimo termo:
	for(itr2 = mortos.begin(); itr2 != mortos.end(); ++itr2)
	{
		std::cout << *itr2 << " . " <<std::endl;
	}
	*/
}

void Fase_teste::adicionarInimigo(Inimigo* ini)
{
	adicionar(static_cast<Entidade*>(ini));
	inimigos.insert(ini);
}