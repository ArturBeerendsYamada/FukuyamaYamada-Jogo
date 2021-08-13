#pragma once

#include "ArameFarpado.h"
#include "GerenciadorColisao.h"
#include "GerenciadorComandos.h"
#include "GerenciadorGrafico.h"
#include "Inimigo.h"
#include "Japao.h"
#include "Alemanha.h"
#include "Jogador.h"
#include "Lista.h"
#include "ListaEntidade.h"
#include "Mina.h"
#include "Obstaculo.h"
#include "OuricoTcheco.h"
#include "BotaoBomba.h"
#include <SFML/Graphics.hpp>
#include <time.h>

#define TILE 100.0f

class Fase_teste
{
protected:
	GerenciadorComandos* gerenciador_comandos_fase_teste;
	GerenciadorColisoes* gerenciador_colisoes_fase_teste;
	sf::Clock relogio;
	GerenciadorGrafico* gerenciador_grafico_fase_teste;
	ListaEntidade ListaEntidades;
	std::set<Inimigo*> inimigos;
	Jogador* j;
	virtual int reiniciaFase();

public:
	Fase_teste();
	virtual ~Fase_teste();
	virtual void inicializar(GerenciadorGrafico* gg);
	int executar(GerenciadorGrafico* gg);
	void adicionar(Entidade* e);
	void inicializarTextura(Entidade* e);
	void remover(Entidade* e);
	GerenciadorGrafico* getGerenciadorGrafico();
	void verificarInimigos();
	void adicionarInimigo(Inimigo* ini);
};