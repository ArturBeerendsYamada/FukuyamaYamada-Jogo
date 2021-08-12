#include "../lib/ArameFarpado.h"

ArameFarpado::ArameFarpado(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel) :
	Obstaculo(pos, textu, tam, vel)
{
	idColisao = IdsColisao::arame_farpado;
}

ArameFarpado::~ArameFarpado()
{}
