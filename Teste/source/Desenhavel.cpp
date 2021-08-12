#include "../lib/Desenhavel.h"
#include <iostream>

Desenhavel::Desenhavel(Vetor2F pos, const char *textu, Vetor2F tam):
	posicao(pos), textura(textu), tamanho(tam){}
Desenhavel::~Desenhavel(){}

void Desenhavel::setPosicao (const Vetor2F pos) {posicao = pos;}
const Vetor2F Desenhavel::getPosicao() const {return posicao;}

void Desenhavel::setTamanho(const Vetor2F tam){tamanho = tam;}
Vetor2F Desenhavel::getTamanho() const {return tamanho;}

void Desenhavel::desenhar(GerenciadorGrafico& g) {g.desenhar(textura, posicao, tamanho);}
//void Desenhavel::inicializarTextura(GerenciadorGrafico& g) {
//	g.carregarTextura(textura);}

void Desenhavel::inicializarTextura(GerenciadorGrafico* g) {
	if(!g)
		printf("Gerenciar TExtura\n");
	g->carregarTextura(textura);}

