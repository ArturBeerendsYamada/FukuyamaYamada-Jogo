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
	virtual int reiniciaFase();
	virtual int proximaFase();
	virtual void limpar();

public:
	Fase();
	virtual ~Fase();
	virtual void inicializar(GerenciadorGrafico* gg) = 0 ;
	virtual int executar(GerenciadorGrafico* gg);
	virtual void adicionar(Entidade* e);
	virtual void inicializarTextura(Entidade* e);
	virtual void remover(Entidade* e);
	virtual GerenciadorGrafico* getGerenciadorGrafico();
	virtual void verificarInimigos();
	virtual void adicionarInimigo(Inimigo* ini);

	virtual void gerenciarP2(GerenciadorGrafico* gg);
};