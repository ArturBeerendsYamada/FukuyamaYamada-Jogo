#include "../lib/OuricoTcheco.h"

#define GRAV 4000.0

OuricoTcheco::OuricoTcheco(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel) :
	Obstaculo(pos, textu, tam, vel)
{
	idColisao = IdsColisao::ourico_tcheco;
}

OuricoTcheco::~OuricoTcheco()
{}

void OuricoTcheco::atualizar(float deltaT)
{
	velocidade.y += GRAV * deltaT;
	mover(velocidade * deltaT);
}

void OuricoTcheco::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsColisao::solido)
	{
		if (direcao == ABAIXO)
		{
			this->mover(Vetor2F(0.0f, interY));
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
	else if (outro->getIdColisao() == IdsColisao::jogador)
	{
		if (direcao == ESQUERDA)
			this->mover(Vetor2F(-interX/2.0, 0.0f));
		else if(direcao == DIREITA)
			this->mover(Vetor2F(interX/2.0, 0.0f));
	}
	else if(outro->getIdColisao() == IdsColisao::ourico_tcheco)
	{
		if (direcao == ESQUERDA)
			this->mover(Vetor2F(-interX/2.0, 0.0f));
		else if(direcao == DIREITA)
			this->mover(Vetor2F(interX/2.0, 0.0f));
		else if (direcao == ABAIXO)
		{
			this->mover(Vetor2F(0.0f, interY));
			velocidade.y = 0.0f;
		}
		else if (direcao == ACIMA)
		{
			this->mover(Vetor2F(0.0f, -interY));
			velocidade.y = 0.0f;
		}
	}
}