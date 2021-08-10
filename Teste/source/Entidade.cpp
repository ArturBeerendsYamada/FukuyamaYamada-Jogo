#include "../lib/Entidade.h"

Entidade::Entidade(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel) :
	Desenhavel(pos, textu, tam),
	velocidade(vel),
	idColisao(IdsCollisao::nulo)
{}
Entidade::~Entidade()
{}

void Entidade::setVelocidade(const Vetor2F vel)
{
	velocidade = vel;
}
const Vetor2F Entidade::getVelocidade() const
{
	return velocidade;
}

void Entidade::mover(Vetor2F deslocamento)
{
	posicao = posicao + deslocamento;
}

IdsCollisao Entidade::getIdColisao() const
{
	return idColisao;
}
