#include "Floresta.h"

void Floresta::inicializar(GerenciadorGrafico* gg)
{
	//gg->inicializarBackground("Floresta.jpg", Vetor2F(2000.0f, 700.0f));
	gerenciador_grafico_fase_teste = gg;
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	Entidade* temp = NULL;
	Japao* jap = NULL;
	int i, k;
	int matriz[7][20] = {
		{ 1, 0, 0, 0, 6, 2, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 8, 8, 8, 0, 4, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
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

	j = (new Jogador(Vetor2F(TILE, 0.0f), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));

	j->setFase(this);

	//temp = new ProjetilAmigo(Vetor2F(10000.0f, 10000.0f), "projetilAmigo.png", Vetor2F(50.0f, 50.0f), Vetor2F(200.0f, 0), true);
	//adicionar(temp);

	for (i = 0; i < ((rand() % 3)+1); i++)
	{
		temp = static_cast<Entidade*>(new Inimigo(Vetor2F(300.0f, rand() % 5 * TILE), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
		adicionarInimigo(static_cast<Inimigo*>(temp));
	}

	ListaEntidades.inicializarEntidades(*gg);
}

int Floresta::reiniciaFase()
{
	return IdsMenu::fase1_abre;
}