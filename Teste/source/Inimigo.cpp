#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F vel):
	Personagem(pos, caminhoTextura, vel)
{
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