#pragma once

#include "GerenciadorGrafico.h"
#include "Vetor2D.h"

class Desenhavel
{
protected:
	Vetor2F posicao;
	const char *textura;

public:
	Desenhavel(Vetor2F pos={0.0f, 0.0f}, const char *textu="");
	virtual ~Desenhavel();

	void setPosicao (const Vetor2F pos);
	const Vetor2F getPosicao() const;

	void desenhar(GerenciadorGrafico& g);
	void inicializarTextura(GerenciadorGrafico& g);
};