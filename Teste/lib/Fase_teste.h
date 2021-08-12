#pragma once

#include "ArameFarpado.h"
#include "GerenciadorColisao.h"
#include "GerenciadorComandos.h"
#include "GerenciadorGrafico.h"
#include "Inimigo.h"
#include "Japao.h"
#include "Jogador.h"
#include "Lista.h"
#include "ListaEntidade.h"
#include "Mina.h"
#include "Obstaculo.h"
#include "OuricoTcheco.h"
#include <SFML/Graphics.hpp>
#include <time.h>

class Fase_teste
{
private:
	GerenciadorComandos* gerenciador_comandos_fase_teste;
	GerenciadorColisoes* gerenciador_colisoes_fase_teste;
	sf::Clock relogio;
	GerenciadorGrafico* gerenciador_grafico_fase_teste;
	ListaEntidade ListaEntidades;
	std::set<Inimigo*> inimigos;
	Jogador* j;

public:
	Fase_teste();
	~Fase_teste();
	void inicializar(GerenciadorGrafico* gg);
	int executar(GerenciadorGrafico* gg);
	void adicionar(Entidade* e);
	void inicializarTextura(Entidade* e);
	void remover(Entidade* e);
	GerenciadorGrafico* getGerenciadorGrafico();
	void verificarInimigos();
	void adicionarInimigo(Inimigo* ini);
};