#pragma once

#include "Personagem.h"
#include "GerenciadorComandos.h"

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
	void naColisao(Vetor2F direcao, Entidade* outro);
};