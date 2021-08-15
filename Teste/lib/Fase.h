#pragma once

#include "ArameFarpado.h"
#include "GerenciadorColisao.h"
#include "GerenciadorComandos.h"
#include "GerenciadorGrafico.h"
#include "Italia.h"
#include "Japao.h"
#include "Alemanha.h"
#include "Brasil.h"
#include "Russia.h"
#include "Lista.h"
#include "ListaEntidade.h"
#include "Mina.h"
#include "Obstaculo.h"
#include "OuricoTcheco.h"
#include "BotaoBomba.h"
#include <SFML/Graphics.hpp>
#include <time.h>

#define TILE 100.0f

class Fase
{
protected:
	GerenciadorComandos* gerenciador_comandos_Fase;
	GerenciadorColisoes* gerenciador_colisoes_Fase;
	sf::Clock relogio;
	GerenciadorGrafico* gerenciador_grafico_Fase;
	ListaEntidade ListaEntidades;
	std::set<Inimigo*> inimigos;
	Brasil* j;
	Russia* p2;
	Alemanha* al;
	virtual int reiniciaFase()=0;
	virtual int proximaFase()=0;
	virtual void limpar()=0;

public:
	Fase();
	virtual ~Fase();
	virtual void inicializar(GerenciadorGrafico* gg) = 0 ;
	int executar(GerenciadorGrafico* gg);
	void adicionar(Entidade* e);
	void inicializarTextura(Entidade* e);
	void remover(Entidade* e);
	GerenciadorGrafico* getGerenciadorGrafico();
	void verificarInimigos();
	void adicionarInimigo(Inimigo* ini);

	void gerenciarP2(GerenciadorGrafico* gg);
};