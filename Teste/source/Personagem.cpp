#include "../lib/Personagem.h"

Personagem::Personagem(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel) :
	Entidade(pos, caminhoTextura, tam, vel)
{
	vida = true;
}

Personagem::~Personagem()
{
}