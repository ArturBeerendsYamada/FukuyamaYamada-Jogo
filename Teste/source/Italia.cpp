#include "../lib/Italia.h"
#include "../lib/Fase.h"
#include <iostream>

#define GRAV 4000.0
#define PULO 300.0

Italia::Italia(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    pode_pular = true;
    idColisao = IdsColisao::inimigo;
}

Italia::~Italia(){}

void Italia::atualizar(float deltaT)
{
    velocidade.y += GRAV * deltaT;
	if (pode_pular)
	{
		pode_pular = false;
		velocidade.y = -sqrtf(2.0 * GRAV * PULO);
	}
	mover(velocidade * deltaT);
}

void Italia::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsColisao::solido || outro->getIdColisao() == IdsColisao::ourico_tcheco)
	{
		if (direcao == ABAIXO)
		{
			this->mover(Vetor2F(0.0f, interY));
			pode_pular = true;
			velocidade.y = 0.0f;
		}
		else if (direcao == ACIMA)
		{
			this->mover(Vetor2F(0.0f, -interY));
			velocidade.y = 0.0f;
		}
		else
		{
			if (direcao == ESQUERDA)
				this->mover(Vetor2F(-interX, 0.0f));
			else
				this->mover(Vetor2F(interX, 0.0f));
			velocidade.x = 0.0f;
		}
	}
	else if (outro->getIdColisao() == IdsColisao::inimigo)
	{
		if (direcao == ABAIXO)
		{
			pode_pular = true;
			velocidade.y = 0;
		}
	}
	else if (outro->getIdColisao() == IdsColisao::jogador)
	{
		if(direcao==ACIMA)
			this->mover(Vetor2F(0.0f, -interY/2.0));
		this->setVida(false);
	}
	else if (outro->getIdColisao() == IdsColisao::projetilAmigo)
	{
		this->setVida(false);
	}
}
