#pragma once

#include "Desenhavel.h"
#include "Ids.h"
#include "GerenciadorColisao.h"

class Entidade : public Desenhavel
{
protected:
	Vetor2F velocidade;
	IdsCollisao idColisao;

public:
	Entidade(Vetor2F pos={0.0f, 0.0f}, const char *textu=nullptr, Vetor2F tam={0.f, 0.f}, Vetor2F vel={0.f, 0.f});
	virtual ~Entidade();

	void setVelocidade (const Vetor2F vel);
	const Vetor2F getVelocidade () const;

	virtual void inicializar() = 0;
	virtual void atualizar(float deltaT) = 0;

	void mover(Vetor2F deslocamento);

	virtual void colidir(Entidade* outro);
	IdsCollisao getIdColisao() const;

};