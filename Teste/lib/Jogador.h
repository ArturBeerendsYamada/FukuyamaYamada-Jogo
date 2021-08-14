#pragma once

#include "GerenciadorComandos.h"
#include "Personagem.h"
#include "ProjetilAmigo.h"
//#include "Fase_teste.h"

class Fase_teste;

class Jogador : public Personagem
{
protected:
	GerenciadorComandos* gerenciador_comandos_jogador;
	bool pode_pular;
	bool pode_atirar;
	int direcao_projetil;
	Fase_teste* fase;
	ProjetilAmigo* tiroamigo;
	float tzinho;

public:
	Jogador(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
	virtual ~Jogador();

	virtual void setPular(const bool p);
	virtual bool getPular();

	//virtual void desenhar(GerenciadorGrafico& g);
	virtual void atualizar(float deltaT) = 0;
	virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
	virtual void atirar();
	virtual void setFase(Fase_teste* fase);
};