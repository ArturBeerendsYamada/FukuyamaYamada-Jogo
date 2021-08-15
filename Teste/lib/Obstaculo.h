#pragma once

#include "Entidade.h"

class Obstaculo : public Entidade
{
public:
	Obstaculo(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel);
	virtual ~Obstaculo();

	void atualizar(float deltaT);

	virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};