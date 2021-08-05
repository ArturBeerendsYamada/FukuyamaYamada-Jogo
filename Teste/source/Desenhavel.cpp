#include "../lib/Desenhavel.h"

Desenhavel::Desenhavel(Vetor2F pos, const char *textu):
	posicao(pos), textura(textu){}
Desenhavel::~Desenhavel(){}

void Desenhavel::setPosicao (const Vetor2F pos) {posicao = pos;}
const Vetor2F Desenhavel::getPosicao() const {return posicao;}

void Desenhavel::desenhar(GerenciadorGrafico& g) {g.desenhar(textura, posicao);}
void Desenhavel::inicializarTextura(GerenciadorGrafico& g) {g.carregarTextura(textura);}