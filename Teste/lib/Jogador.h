#pragma once

#include "Personagem.h"
#include "GerenciadorComandos.h"

#define VEL_MAX 100.0f
#define PULO 600.0f
#define ACCEL 1000.0f
#define GRAV 1000.0f

class Jogador : public Personagem
{
private:
	GerenciadorComandos* gerenciador_comandos_jogador;
	bool pode_pular;

public:
	Jogador(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F tam={0.f, 0.f}, Vetor2F vel = {0.0f, 0.0f});
	~Jogador();

	void setPular (const bool p);
	bool getPular ();

	void inicializar();
	void desenhar(GerenciadorGrafico& g);
	void atualizar(float deltaT);
	void colidir(Entidade* outro);
};