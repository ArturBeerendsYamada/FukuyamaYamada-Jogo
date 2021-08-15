#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

#define GRAV 4000.0
#define PULO 300.0

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsColisao::inimigo;
}
Inimigo::~Inimigo()
{
}

void Inimigo::atualizar(float deltaT)
{
	mover(velocidade * deltaT);
}


void Inimigo::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsColisao::solido || outro->getIdColisao() == IdsColisao::ourico_tcheco)
	{
		if (direcao == ABAIXO)
		{
			this->mover(Vetor2F(0.0f, interY));
			//pode_pular = true;
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
			//pode_pular = true;
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