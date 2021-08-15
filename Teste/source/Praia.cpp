#include "../lib/Praia.h"

Praia::Praia():
Fase()
{}

Praia::~Praia(){
}


void Praia::inicializar(GerenciadorGrafico* gg)
{
	gg->inicializarBackground("Praia.png", Vetor2F(6000.0f, 1000.0f));
	gerenciador_grafico_Fase = gg;
	gerenciador_comandos_Fase = GerenciadorComandos::getComandos();
	gerenciador_colisoes_Fase = new GerenciadorColisoes;



	Entidade* temp = NULL;
	Inimigo* ini = NULL;
	Japao* jap = NULL;
	BotaoBombas* bot = NULL;

	srand(time(NULL));

	//gera alguns inimigos normais aleatorios
	float pos_x = 26*TILE, pos_y = 8*TILE;
	int n = rand()%3+2;
	do{
		pos_y = (float)((rand()%1600)-800);
		ini = (new Italia(Vetor2F(pos_x, pos_y), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.0f, 0.0f)));
		adicionarInimigo(ini);
		pos_x = (26+(rand()%2))*TILE;
		n--;
	}while(n);

	//gera algumas minas aleatorias
	pos_x = 10*TILE;
	pos_y = 8*TILE+TILE/2;
	do{
		temp = static_cast<Entidade*>(new Mina(Vetor2F(pos_x, pos_y), "Mina.png", Vetor2F(TILE/2, TILE/2), Vetor2F(0.0f, 0.0f)));
		adicionar(temp);
		pos_x += (float)(rand()%300)+150;
	}while(pos_x<18*TILE);

	pos_x = 38*TILE;
	pos_y = 4*TILE+TILE/2;
	do{
		temp = static_cast<Entidade*>(new Mina(Vetor2F(pos_x, pos_y), "Mina.png", Vetor2F(TILE/2, TILE/2), Vetor2F(0.0f, 0.0f)));
		adicionar(temp);
		pos_x += (float)(rand()%200);
	}while(pos_x<43*TILE);

	pos_x = 19*TILE;
	pos_y = 8*TILE;
	jap = (new Japao(-1, Vetor2F(pos_x, pos_y), "Japan_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
	adicionarInimigo(static_cast<Inimigo*>(jap));
	jap->setFase(this);
	n--;
	//gera alguns inimigos de projetil aleatorios
	pos_x = 43*TILE;
	pos_y = 4*TILE;
	do{
		jap = (new Japao(-1, Vetor2F(pos_x, pos_y), "Japan_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
		adicionarInimigo(static_cast<Inimigo*>(jap));
		jap->setFase(this);
		pos_x += (float)(rand()%300);
	}while(pos_x<52*TILE);

	//gera alguns arames farpados aleatorios
	pos_x = 23*TILE;
	pos_y = (rand()%2+1)*TILE;
	do{
		temp = static_cast<Entidade*>(new ArameFarpado(Vetor2F(pos_x, pos_y), "ArameFarpado.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
		adicionar(temp);
		pos_y += 300.0f;
	}while(pos_y<9*TILE);

	pos_x = 46*TILE;
	pos_y = 8*TILE;
	do{
		temp = static_cast<Entidade*>(new ArameFarpado(Vetor2F(pos_x, pos_y), "ArameFarpado.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
		adicionar(temp);
		pos_x += 300.0f+rand()%100;
	}while(pos_x<54*TILE);


	int i, k;
	int matriz[10][60] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 1, 1, 1, 0, 6, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};//  0				 5				10			   15			  20			 25			    30			   35			  40			 45			 	50			   55
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 60; k++)
		{
			switch (matriz[i][k])
			{
				case 1:
					temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(k * TILE, i * TILE), "Bloco_Praia.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
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
					ini = (new Italia(Vetor2F(k * TILE, i * TILE), "Italia_Countryball.png", Vetor2F(TILE, TILE), Vetor2F(0.f, 0.f)));
					adicionarInimigo(ini);
					break;

				default:
					break;
			}
		}
	}

	j = (new Brasil(Vetor2F(TILE, 6*TILE), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_Fase->adicionarEntidade(static_cast<Entidade*>(j));
	j->setFase(this);

	al = new Alemanha(Vetor2F(-800.0f, 500.0f ), "Alemanha_Countryball.png", Vetor2F(6*TILE, 6*TILE), Vetor2F(150.f, 0.f));
    adicionarInimigo(static_cast<Inimigo*>(al));

    bot->setAlemanha(al);



	ListaEntidades.inicializarEntidades(*gg);
}

int Praia::reiniciaFase()
{
	return IdsMenu::fase2_abre;
}

void Praia::limpar()
{
	gerenciador_grafico_Fase->limpar(0xd3, 0xed, 0xee);
}

int Praia::proximaFase()
{
	return IdsMenu::menu_abre;
}