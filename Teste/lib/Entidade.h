#pragma once

#include "Desenhavel.h"
#include "GerenciadorColisao.h"
#include "Ids.h"

class Entidade : public Desenhavel
{
protected:
	Vetor2F velocidade;
	IdsColisao idColisao;
	bool vida;

public:
	Entidade(Vetor2F pos = { 0.0f, 0.0f }, const char* textu = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.f, 0.f });
	virtual ~Entidade();

	void setVelocidade(const Vetor2F vel);
	const Vetor2F getVelocidade() const;

	void setVida(const bool v)
	{
		vida = v;
	}
	bool getVida() const
	{
		return vida;
	}

	virtual void inicializar() = 0;
	virtual void atualizar(float deltaT) = 0;

	void mover(Vetor2F deslocamento);

	virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY) = 0;
	IdsColisao getIdColisao() const;
};