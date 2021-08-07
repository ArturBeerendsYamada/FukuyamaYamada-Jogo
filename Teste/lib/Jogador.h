#pragma once

#include "Personagem.h"
#include "GerenciadorComandos.h"

class Jogador : public Personagem
{
private:
	GerenciadorComandos* gerenciador_comandos_jogador;

public:
	Jogador(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F vel = {0.0f, 0.0f}, Vetor2F tam={0.f, 0.f});
	~Jogador();

	void inicializar();
	void atualizar(float deltaT);
	void colidir(const IdsCollisao id,const Vetor2F pos,const Vetor2F tam);
};