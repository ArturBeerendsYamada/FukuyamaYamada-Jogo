#pragma once

#include "GerenciadorComandos.h"
#include "Personagem.h"
#include "ProjetilAmigo.h"
//#include "Fase.h"

class Fase;

class Jogador : public Personagem
{
protected:
	GerenciadorComandos* gerenciador_comandos_jogador;
	bool pode_pular;
	bool pode_atirar;
	int direcao_projetil;
	Fase* fase;
	ProjetilAmigo* tiroamigo;
	float tzinho;

public:
	Jogador(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Jogador();

	void setPular(const bool p);
	bool getPular();

//	virtual void atualizar(float deltaT) = 0;
	virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
	void atirar();
	void setFase(Fase* fase);
};