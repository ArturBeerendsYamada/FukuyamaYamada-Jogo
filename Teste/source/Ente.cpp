#include "../lib/Ente.h"
#include <iostream>

Ente::Ente(Vetor2F pos, const char *textu, Vetor2F tam):
	posicao(pos), textura(textu), tamanho(tam){}
Ente::~Ente(){}

void Ente::setPosicao (const Vetor2F pos) {posicao = pos;}
const Vetor2F Ente::getPosicao() const {return posicao;}

void Ente::setTamanho(const Vetor2F tam){tamanho = tam;}
Vetor2F Ente::getTamanho() const {return tamanho;}

void Ente::desenhar(GerenciadorGrafico& g) {g.desenhar(textura, posicao, tamanho);}
//nao devia ser virtual?
void Ente::inicializarTextura(GerenciadorGrafico* g) {
	if(!g)
		printf("Gerenciar Textura\n");
	g->carregarTextura(textura);}
