#pragma once

#include "Personagem.h"
#include "GerenciadorComandos.h"

class Inimigo : public Personagem
{
private:


public:
	Inimigo(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F vel = {0.0f, 0.0f}, Vetor2F tam={0.f, 0.f});
	~Inimigo();

	void inicializar();
	void atualizar(float deltaT);
};