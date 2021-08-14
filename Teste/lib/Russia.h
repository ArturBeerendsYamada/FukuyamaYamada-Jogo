#pragma once

#include "Jogador.h"

class Fase_teste;

class Russia : public Jogador
{
private:

public:
	Russia(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Russia();

	void atualizar(float deltaT);
};