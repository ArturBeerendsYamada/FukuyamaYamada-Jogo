#include "../lib/Japao.h"
#include "../lib/Fase.h"
#include <iostream>

Japao::Japao(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    tiroinimigo = NULL;
    pode_atirar = true;
    idColisao = IdsColisao::japao;
    direcao_projetil = 1;
}

Japao::Japao(int dir, Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    tiroinimigo = NULL;
    pode_atirar = true;
    idColisao = IdsColisao::japao;
    direcao_projetil = dir;
}

Japao::~Japao(){

}

void Japao::atualizar(float deltaT)
{
    deltaT = deltaT;
    if (tiroinimigo)
    {
        if (abs(tiroinimigo->getPosicao().x - getPosicao().x) >= tiroinimigo->getAlcance() || !tiroinimigo->getExiste())
        {
            fase->remover(tiroinimigo);
            tiroinimigo = nullptr;
            pode_atirar = true;
        }
    }

    if (pode_atirar)
    {
        atirar();
        pode_atirar = false;
    }
}

void Japao::atirar()
{
    tiroinimigo = new ProjetilInimigo(Vetor2F(posicao.x, posicao.y), "projetilInimigo.png", Vetor2F(50.0, 50.0), Vetor2F(direcao_projetil*500.0, 0.0), true);
    fase->adicionar(tiroinimigo);
    fase->inicializarTextura(tiroinimigo);
    pode_atirar = false;
}

void Japao::setFase(Fase* Fase){
	fase = Fase;
}

void Japao::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	if (outro->getIdColisao() == IdsColisao::solido || outro->getIdColisao() == IdsColisao::ourico_tcheco)
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
	else if (outro->getIdColisao() == IdsColisao::inimigo)
	{
		if (direcao == ABAIXO)
		{
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