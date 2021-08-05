#pragma once

#include "Personagem.h"
#include "GerenciadorComandos.h"

class Jogador : public Personagem
{
private:
	GerenciadorComandos* gerenciador_comandos_jogador;

public:
	Jogador(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F vel = {0.0f, 0.0f});
	~Jogador();

	void inicializar();
	void atualizar(float deltaT);
};