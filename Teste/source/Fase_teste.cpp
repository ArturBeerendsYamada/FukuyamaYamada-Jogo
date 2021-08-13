#include "../lib/Fase_teste.h"

#include <iostream>
#include <list>
using namespace std;


Fase_teste::Fase_teste()
{
	gerenciador_grafico_fase_teste = NULL;
	gerenciador_comandos_fase_teste = NULL;
	gerenciador_colisoes_fase_teste = NULL;
	j = NULL;
	al = NULL;
}
Fase_teste::~Fase_teste()
{
	ListaEntidades.destruirEntidades();
	delete gerenciador_colisoes_fase_teste;
	delete j;
}

void Fase_teste::inicializar(GerenciadorGrafico* gg)
{
	//gg->inicializarBackground("Floresta.jpg", Vetor2F(2000.0f, 700.0f));
	gerenciador_grafico_fase_teste = gg;
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	Entidade* temp = NULL;
	BotaoBombas* bot = NULL;
	Japao* jap = NULL;
	int i, k;
	int matriz[7][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
		{ 1, 4, 0, 3, 0, 0, 1, 1, 1, 4, 4, 4, 4, 1, 1, 0, 0, 8, 5, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
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
					temp = static_cast<Entidade*>(new Mina(Vetor2F(k * TILE, i * TILE + TILE/2), "Mina.png", Vetor2F(TILE / 2, TILE / 2), Vetor2F(0.f, 0.f)));
					adicionar(temp);
					break;

				case 5:
					bot = new BotaoBombas(Vetor2F(k * TILE, i * TILE+TILE/2), "Botao.png", Vetor2F(TILE/2, TILE/2), Vetor2F(0.f, 0.f), true);
					adicionar(static_cast<Entidade*>(bot));
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

	j = (new Jogador(Vetor2F(TILE, TILE), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));
	j->setFase(this);

	al = new Alemanha(Vetor2F(22 * TILE, 5 * TILE), "Alemanha_Countryball.png", Vetor2F(4*TILE, 4*TILE), Vetor2F(0.f, 0.f));
    adicionarInimigo(static_cast<Inimigo*>(al));

	bot->setAlemanha(al);


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

	printf("oi\n");
	system("pause");
	if(al->getVida() == false){
		gerenciador_grafico_fase_teste->mostrarTexto("Venceu ! ! !", j->getPosicao());
		return IdsMenu::menu_abre;
	}
	if (j->getVida() == false || j->getPosicao().y > 15000.f)
	{
		//j->setVida(true);
		//j->setPosicao(Vetor2F(0.0f, 1000.0f));
		gerenciador_grafico_fase_teste->mostrarTexto("Perdeu ! ! !", j->getPosicao());
		return reiniciaFase();
	}
	if (gerenciador_comandos_fase_teste->comandosFuncionalidades() == GerenciadorComandos::Comandos::comeco)
	{
		return IdsMenu::menu_abre;
	}
	return IdsMenu::fase_continua;
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

int Fase_teste::reiniciaFase()
{
	return IdsMenu::fase0_abre;
}