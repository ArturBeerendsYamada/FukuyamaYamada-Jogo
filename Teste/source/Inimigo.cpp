#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

#define GRAV 4000.0
#define PULO 300.0

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsColisao::inimigo;
}
Inimigo::~Inimigo()
{
}