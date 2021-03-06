#include "../lib/Alemanha.h"
#include <iostream>
using namespace std;

#define GRAV 4000.0
#define PULO 300.0

Alemanha::Alemanha(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Inimigo(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsColisao::alemanha;
}

Alemanha::~Alemanha()
{
}


void Alemanha::atualizar(float deltaT)
{
    mover(velocidade * deltaT);
}


void Alemanha::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	direcao = direcao;
	outro = outro;
	interX = interX;
	interY = interY;
}


void Alemanha::setFase(Fase* Fase){
    fase = Fase;
}
