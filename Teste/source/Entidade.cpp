#include "../lib/Entidade.h"

Entidade::Entidade(Vetor2F pos, const char *textu, Vetor2F vel):
	Desenhavel(pos, textu), velocidade(vel){}
Entidade::~Entidade(){}

void Entidade::setVelocidade (const Vetor2F vel) {velocidade = vel;}
const Vetor2F Entidade::getVelocidade () const {return velocidade;}