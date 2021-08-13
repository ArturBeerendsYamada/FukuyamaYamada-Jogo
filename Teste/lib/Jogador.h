#pragma once

#include "GerenciadorComandos.h"
#include "Personagem.h"
#include "ProjetilAmigo.h"

class Fase_teste;

class Jogador : public Personagem
{
private:
	GerenciadorComandos* gerenciador_comandos_jogador;
	bool pode_pular;
	bool pode_atirar;
	int direcao_projetil;
	Fase_teste* fase;
	ProjetilAmigo* tiroamigo;

public:
	Jogador(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Jogador();

	void setPular(const bool p);
	bool getPular();

	void inicializar();
	void desenhar(GerenciadorGrafico& g);
	void atualizar(float deltaT);
	void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
	void atirar();
	void setFase(Fase_teste* fase);
};