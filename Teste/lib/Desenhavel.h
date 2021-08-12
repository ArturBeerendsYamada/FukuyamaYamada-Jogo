#pragma once

#include "GerenciadorGrafico.h"
#include "Vetor2D.h"

class Desenhavel
{
protected:
	Vetor2F posicao;
	const char *textura;
	Vetor2F tamanho;

public:
	Desenhavel(Vetor2F pos={0.0f, 0.0f}, const char *textu=nullptr, const Vetor2F tam={0.0f, 0.0f});
	virtual ~Desenhavel();

	void setPosicao (const Vetor2F pos);
	const Vetor2F getPosicao() const;

	void setTamanho(const Vetor2F tamanho);
    Vetor2F getTamanho() const;

	virtual void desenhar(GerenciadorGrafico& g);
	//void inicializarTextura(GerenciadorGrafico& g);
	void inicializarTextura(GerenciadorGrafico* g);
};