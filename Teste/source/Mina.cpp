#include "../lib/Mina.h"

Mina::Mina(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel) :
	Obstaculo(pos, textu, tam, vel)
{
	idColisao = IdsColisao::mina;
}

Mina::~Mina()
{}