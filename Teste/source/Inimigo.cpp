#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

#define GRAV 4000.0
#define PULO 300.0

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsCollisao::inimigo;
	pode_pular = false;
}
Inimigo::~Inimigo()
{
}

void Inimigo::inicializar()
{
}
void Inimigo::atualizar(float deltaT)
{
	velocidade.y += GRAV * deltaT;
	if (pode_pular)
	{
		pode_pular = false;
		velocidade.y = -sqrtf(2.0 * GRAV * PULO);
	}
	mover(velocidade * deltaT);
}

void Inimigo::colidir(Entidade* outro)
{
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if (interY < 0.0f && interX < 0.0f)
	{
		if (interX > interY)
		{
			if (deltaX > 0.0f)
			{
				if (outro->getIdColisao() == IdsCollisao::jogador)
				{
					//printf("morte pela esquerda\n");
					this->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->naColisao(ESQUERDA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					this->mover(Vetor2F(interX, 0.0f));
				}
				else if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->naColisao(ESQUERDA, this);
				}
				this->naColisao(DIREITA, outro);
			}
			else
			{
				if (outro->getIdColisao() == IdsCollisao::jogador)
				{
					//printf("morte pela direita\n");
					this->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->naColisao(DIREITA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					this->mover(Vetor2F(-interX, 0.0f));
				}
				else if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->naColisao(DIREITA, this);
				}
				this->naColisao(ESQUERDA, outro);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				if (outro->getIdColisao() == IdsCollisao::jogador)
				{
					//printf("morte por cima\n");
					this->mover(Vetor2F(0.0f, interY / 2.0));
					outro->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->naColisao(ACIMA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					this->mover(Vetor2F(0.0f, interY));
				}
				else if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(0.0f, interY / 2.0));
					outro->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->naColisao(ACIMA, this);
				}
				this->naColisao(ABAIXO, outro);
			}
			else
			{
				if (outro->getIdColisao() == IdsCollisao::jogador)
				{
					//printf("Pulo por inimigo :D\n");
					this->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->mover(Vetor2F(0.0f, interY / 2.0));
					outro->naColisao(ABAIXO, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					this->mover(Vetor2F(0.0f, -interY));
				}
				else if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->mover(Vetor2F(0.0f, interY / 2.0));
					outro->naColisao(ABAIXO, this);
				}
				this->naColisao(ACIMA, outro);
			}
		}
	}
}

void Inimigo::naColisao(Vetor2F direcao, Entidade* outro)
{
	if (outro->getIdColisao() == IdsCollisao::solido)
	{
		if (direcao == ABAIXO)
		{
			pode_pular = true;
			velocidade.y = 0;
		}
		else if (direcao == ACIMA)
		{
			velocidade.y = 0.0f;
		}
		else
		{
			velocidade.x = 0.0f;
		}
	}
	else if (outro->getIdColisao() == IdsCollisao::inimigo)
	{
		if (direcao == ABAIXO)
		{
			pode_pular = true;
			velocidade.y = 0;
		}
	}
	else if (outro->getIdColisao() == IdsCollisao::jogador)
	{
		this->setVida(false);
	}
}