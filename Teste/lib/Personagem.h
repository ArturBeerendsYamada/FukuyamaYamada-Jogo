#pragma once

#include "Entidade.h"

class Personagem : public Entidade
{
protected:
public:
	Personagem(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Personagem();

	//virtual void atualizar(float deltaT);
};
