#pragma once

#include "Jogador.h"

class Fase;

class Brasil : public Jogador
{
private:
public:
	Brasil(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Brasil();

	void atualizar(float deltaT);
	void desenhar(GerenciadorGrafico& g);
};