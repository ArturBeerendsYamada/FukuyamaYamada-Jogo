#include "../lib/Projetil.h"
#include <stdio.h>
#include <iostream>

Projetil::Projetil(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, bool existir) : 
Entidade(pos, caminho, tam, vel)                                                     
{
    existe = existir;
	alcance = 300;
	//frente = true;
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

void Projetil::naColisao(Vetor2F Direcao, Entidade* Outro, float InterX, float InterY){
/*  direcao = Direcao;
	outro = Outro;
	interY = InterY;
	interX = InterX;*/
}

void Projetil::atualizar(float deltaT)
{
	posicao.x += velocidade.x * deltaT;
	//std::cout << textura << std::endl;
	//std::cout << velocidade.x << " " << velocidade.y << std::endl;
	//std::cout << tamanho.x << " " << tamanho.y << std::endl;
}

/*void Projetil::setFrente(bool direcao){
	frente = direcao;
}*/