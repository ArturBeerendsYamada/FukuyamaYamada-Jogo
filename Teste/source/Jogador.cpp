#include "../lib/Jogador.h"
#include <iostream>
#include <math.h>
using namespace std;

#define VEL_MAX 100.0f
#define PULO 400.0f
#define ACCEL 1000.0f
#define GRAV 4000.0f

Jogador::Jogador(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsCollisao::jogador;
	gerenciador_comandos_jogador = GerenciadorComandos::getComandos();
	pode_pular = false;
	vida = true;
}
Jogador::~Jogador()
{
}

void Jogador::inicializar()
{
}

void Jogador::setPular(const bool p)
{
	pode_pular = p;
}
bool Jogador::getPular()
{
	return pode_pular;
}

void Jogador::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(textura, posicao, tamanho);
	g.centralizar(posicao);
}

void Jogador::atualizar(float deltaT)
{
	velocidade.x = 0.0f;
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if (((pressionados >> GerenciadorComandos::esquerda1) % 2) == 1) //verifica se o bit relativo ao comando estah setado
	{
		velocidade.x -= ACCEL;
	}
	if (((pressionados >> GerenciadorComandos::direita1) % 2))
	{
		velocidade.x += ACCEL;
	}
	if (((pressionados >> GerenciadorComandos::pular1) % 2) && pode_pular)
	{
		pode_pular = false;
		velocidade.y = -sqrtf(2.0 * GRAV * PULO);
	}
	velocidade.y += GRAV * deltaT;

	//if (((pressionados >> GerenciadorComandos::atirar1) % 2))
	//{
	//	velocidade.y += ACCEL * deltaT;
	//}
	this->mover(velocidade * deltaT);
}

void Jogador::colidir(Entidade* outro)
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
				if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					//printf("morte pela direita\n");
					this->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->naColisao(ESQUERDA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					//printf("parede pela direita\n");
					this->mover(Vetor2F(interX, 0.0f));
				}
				this->naColisao(DIREITA, outro);
			}
			else
			{
				if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					//printf("morte pela esquerda\n");
					this->mover(Vetor2F(-interX / 2.0, 0.0f));
					outro->mover(Vetor2F(interX / 2.0, 0.0f));
					outro->naColisao(DIREITA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					//printf("parede pela esquerda\n");
					this->mover(Vetor2F(-interX, 0.0f));
				}
				this->naColisao(ESQUERDA, outro);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					//printf("pulo por inimigo :D\n");
					this->mover(Vetor2F(0.0f, interY / 2.0));
					outro->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->naColisao(ACIMA, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					//printf("chao abaixo\n");
					this->mover(Vetor2F(0.0f, interY));
					this->setPular(true);
				}
				this->naColisao(ABAIXO, outro);
			}
			else
			{
				if (outro->getIdColisao() == IdsCollisao::inimigo)
				{
					//printf("morte por cima\n");
					this->mover(Vetor2F(0.0f, -interY / 2.0));
					outro->mover(Vetor2F(0.0f, interY / 2.0));
					outro->naColisao(ABAIXO, this);
				}
				else if (outro->getIdColisao() == IdsCollisao::solido)
				{
					//printf("teto acima\n");
					this->mover(Vetor2F(0.0f, -interY));
				}
				this->naColisao(ACIMA, outro);
			}
		}
	}
}

void Jogador::naColisao(Vetor2F direcao, Entidade* outro)
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
		else
		{
			this->setVida(false);
		}
	}
}