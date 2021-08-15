#include "../lib/Brasil.h"
#include "../lib/Fase.h"

#define VEL_MAX 100.0f
#define PULO 210.0f
#define ACCEL 1000.0f
#define GRAV 4000.0f

Brasil::Brasil(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Jogador(pos, caminhoTextura, tam, vel)
{
}

Brasil::~Brasil()
{
}

void Brasil::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(textura, posicao, tamanho);
	g.centralizar(posicao);
}



void Brasil::atualizar(float deltaT)
{
	tzinho = deltaT;
	velocidade.x = 0.0f;
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if (((pressionados >> GerenciadorComandos::esquerda1) % 2) == 1) //verifica se o bit relativo ao comando estah setado
	{
		velocidade.x -= ACCEL;
		direcao_projetil = -1;
	}
	if (((pressionados >> GerenciadorComandos::direita1) % 2))
	{
		velocidade.x += ACCEL;
		direcao_projetil = 1;
	}
	if (((pressionados >> GerenciadorComandos::pular1) % 2) && pode_pular)
	{
		pode_pular = false;
		velocidade.y = -sqrtf(2.0 * GRAV * PULO);
	}
	velocidade.y += GRAV * deltaT;

	this->mover(velocidade * deltaT);

	if(((pressionados >> GerenciadorComandos::atirar1)%2) && pode_atirar)
	{
		atirar();
	}
	if(tiroamigo){
		if(!pode_atirar)
		{
			if(!tiroamigo->getExiste() || abs(tiroamigo->getPosicao().x - getPosicao().x) >= tiroamigo->getAlcance())
			{
				fase->remover(tiroamigo);
				delete tiroamigo;
				tiroamigo = NULL;
				pode_atirar = true;
			}
		}
	}
}