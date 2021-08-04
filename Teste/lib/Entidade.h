#pragma once

#include "Desenhavel.h"

class Entidade : public Desenhavel
{
protected:
	Vetor2F velocidade;

public:
	Entidade(Vetor2F pos={0.0f, 0.0f}, const char *textu="", Vetor2F vel={0.f, 0.f});
	virtual ~Entidade();

	void setVelocidade (const Vetor2F vel);
	const Vetor2F getVelocidade () const;

	virtual void inicializar() = 0;
	virtual void atualizar(float deltaT) = 0;
};