#include "../lib/Projetil.h"
#include <stdio.h>
#include <iostream>

Projetil::Projetil(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, bool existir) :
Entidade(pos, caminho, tam, vel)
{
	idColisao = IdsColisao::nulo;
    existe = existir;
	alcance = 300;
}

Projetil::~Projetil()
{
}

bool Projetil::getExiste() const
{
    return existe;
}

void Projetil::setExiste(const bool existir)
{
    existe = existir;
}

void Projetil::atualizar(float deltaT)
{
	posicao.x += velocidade.x * deltaT;
}
