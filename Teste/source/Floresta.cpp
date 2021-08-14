#include "../lib/Floresta.h"



void Floresta::inicializar(GerenciadorGrafico* gg)
{
	gg->inicializarBackground("Floresta.jpg", Vetor2F(6000.0f, 1000.0f));
	gerenciador_grafico_fase_teste = gg;
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;



	Entidade* temp = NULL;
	Italia* ini = NULL;
	Japao* jap = NULL;
	BotaoBombas* bot = NULL;

	srand(time(NULL));
	//gera alguns inimigos aleatorios
	float pos_x = 5*TILE, pos_y = 0;
	do{
		pos_y = (float)((rand()%300));
		ini = (new Italia(Vetor2F(pos_x, pos_y), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.0f, 0.0f)));
		adicionarInimigo(ini);
		pos_x += (float)(rand()%500)+100;
	}while(pos_x<14*TILE);

	//gera algumas minas aleatorias
	pos_x = 5*TILE;
	pos_y = 8*TILE+TILE/2;
	do{
		temp = static_cast<Entidade*>(new Mina(Vetor2F(pos_x, pos_y), "Mina.png", Vetor2F(TILE/2, TILE/2), Vetor2F(0.0f, 0.0f)));
		adicionar(temp);
		pos_x += (float)(rand()%300)+150;
	}while(pos_x<15*TILE);

	pos_x = 25*TILE;
	pos_y = 5*TILE;
	do{
		temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(pos_x, pos_y), "OuricoTcheco.png", Vetor2F(TILE, TILE), Vetor2F(0.0f, 0.0f)));
		adicionar(temp);
		pos_y -= (rand()%100)+100;
	}while(pos_y>0);

	int i, k;
	int matriz[10][60] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 3, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 6, 0, 0, 0, 0, 0, 0 },
		{ 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 7, 0, 2, 0, 0, 0, 0, 1, 1, 7, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 1, 0, 6, 0, 0, 0, 0, 0, 5, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	};//  0				 5				10			   15			  20			 25			    30			   35			  40			 45			 	50			   55
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 60; k++)
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
					bot = new BotaoBombas(Vetor2F(k * TILE, i * TILE+TILE/2), "Botao.png", Vetor2F(TILE/2, TILE/2), Vetor2F(0.f, 0.f), true);
					adicionar(static_cast<Entidade*>(bot));
					break;

				case 6:
					ini = (new Italia(Vetor2F(k * TILE, i * TILE), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(ini);
					break;

				case 7:
					jap = (new Japao(Vetor2F(k * TILE, i * TILE), "Japan_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(static_cast<Inimigo*>(jap));
					jap->setFase(this);
					break;

				case 8:
					ini =(new Italia(Vetor2F(k * TILE, i * TILE), "Alemanha_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(ini);
					break;

				default:
					break;
			}
		}
	}

	j = (new Brasil(Vetor2F(TILE, 6*TILE), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));
	j->setFase(this);

	al = new Alemanha(Vetor2F(-800.0f, 1000.0f ), "Alemanha_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f));
    adicionarInimigo(static_cast<Inimigo*>(al));

    bot->setAlemanha(al);



	ListaEntidades.inicializarEntidades(*gg);
}

int Floresta::reiniciaFase()
{
	return IdsMenu::fase1_abre;
}

int Floresta::proximaFase()
{
	return IdsMenu::fase2_abre;
}

void Floresta::limpar()
{
	gerenciador_grafico_fase_teste->limpar(0xa2, 0xda, 0xff);
}