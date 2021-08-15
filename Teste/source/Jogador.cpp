#include "../lib/Jogador.h"
#include "../lib/ProjetilAmigo.h"
#include "../lib/Fase.h"
#include <iostream>
#include <math.h>
using namespace std;

#define VEL_MAX 100.0f
#define PULO 210.0f
#define ACCEL 1000.0f
#define GRAV 4000.0f

Jogador::Jogador(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsColisao::jogador;
	gerenciador_comandos_jogador = GerenciadorComandos::getComandos();
	pode_pular = false;
	pode_atirar = true;
	direcao_projetil = 1;
	vida = true;
	tzinho = 0.0f;
}
Jogador::~Jogador()
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

/*
void Jogador::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(textura, posicao, tamanho);
	g.centralizar(posicao);
}
*/

void Jogador::atualizar(float deltaT)
{
	deltaT = deltaT;
/*	tzinho = deltaT;
	velocidade.x = 0.0f;
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if (((pressionados >> GerenciadorComandos::esquerda1) % 2) == 1) //verifica se o bit relativo ao comando estah setado
	{
		//if(tiroamigo)
		//	tiroamigo->setFrente(false);
		velocidade.x -= ACCEL;
		direcao_projetil = -1;
	}
	if (((pressionados >> GerenciadorComandos::direita1) % 2))
	{
		//if(tiroamigo)
		//	tiroamigo->setFrente(true);
		velocidade.x += ACCEL;
		direcao_projetil = 1;
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
*/
}

void Jogador::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsColisao::solido)
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
	else if (outro->getIdColisao() == IdsColisao::inimigo || outro->getIdColisao() == IdsColisao::japao || outro->getIdColisao() == IdsColisao::italia)
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
	else if (outro->getIdColisao() == IdsColisao::mina || outro->getIdColisao() == IdsColisao::projetilInimigo || outro->getIdColisao() == IdsColisao::alemanha)
	{
		this->setVida(false);
	}
	else if (outro->getIdColisao() == IdsColisao::arame_farpado)
	{
		this->mover(Vetor2F(-velocidade.x*tzinho*0.8, -velocidade.y*tzinho*0.8));
	}
	else if (outro->getIdColisao() == IdsColisao::ourico_tcheco)
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
	else if (outro->getIdColisao() == IdsColisao::botao)
    {
        if (direcao == ABAIXO)
        {
            this->mover(Vetor2F(0.0f, interY));
            pode_pular = true;
            velocidade.y = 0.0f;
        }
	}
}

void Jogador::atirar()
{
	Vetor2F velocidade_projetil(direcao_projetil*1500.0f, 0.0f);

	tiroamigo = new ProjetilAmigo(Vetor2F(posicao.x, posicao.y), "projetilAmigo.png", Vetor2F(20.0f, 20.0f), velocidade_projetil, true);
	fase->adicionar(static_cast<Entidade*>(tiroamigo));
	fase->inicializarTextura(static_cast<Entidade*>(tiroamigo));
	pode_atirar=false;
}

void Jogador::setFase(Fase* Fase){
	fase = Fase;
}