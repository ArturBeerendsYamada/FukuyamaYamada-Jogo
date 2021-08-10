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

float tzinho = 0.0f;

void Jogador::atualizar(float deltaT)
{
	tzinho = deltaT;
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

void Jogador::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsCollisao::solido)
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
	else if (outro->getIdColisao() == IdsCollisao::inimigo)
	{
		if (direcao == ABAIXO)
		{
			this->mover(Vetor2F(0.0f, interY / 2.0));
			pode_pular = true;
			velocidade.y = 0.0f;
		}
		else
		{
			this->setVida(false);
		}
	}
	else if (outro->getIdColisao() == IdsCollisao::mina || outro->getIdColisao() == IdsCollisao::projetil)
	{
		this->setVida(false);
	}
	else if (outro->getIdColisao() == IdsCollisao::arame_farpado)
	{
		this->mover(Vetor2F(-velocidade.x*tzinho*0.8, -velocidade.y*tzinho*0.8));
	}
	else if (outro->getIdColisao() == IdsCollisao::ourico_tcheco)
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
				this->mover(Vetor2F(-interX/2.0, 0.0f));
			else
				this->mover(Vetor2F(interX/2.0, 0.0f));
		}
	}
}