#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F vel, Vetor2F tam):
	Personagem(pos, caminhoTextura, vel, tam)
{
	idColisao = IdsCollisao::inimigo;
}
Inimigo::~Inimigo()
{
}

void Inimigo::inicializar()
{

}
void Inimigo::atualizar(float deltaT)
{
	posicao += velocidade * deltaT;
}