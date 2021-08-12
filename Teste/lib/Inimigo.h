#pragma once

#include "GerenciadorComandos.h"
#include "Personagem.h"

class Inimigo : public Personagem
{
private:
	bool pode_pular;

public:
	Inimigo(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Inimigo();

	virtual void inicializar();
	virtual void atualizar(float deltaT);
	virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};