#pragma once

#include "GerenciadorColisao.h"
#include "GerenciadorComandos.h"
#include "GerenciadorGrafico.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Lista.h"
#include "ListaEntidade.h"
#include "Obstaculo.h"
#include "Mina.h"
#include "ArameFarpado.h"
#include "OuricoTcheco.h"
#include <SFML/Graphics.hpp>
#include <time.h>

class Fase_teste
{
private:
	GerenciadorComandos* gerenciador_comandos_fase_teste;
	GerenciadorColisoes* gerenciador_colisoes_fase_teste;
	sf::Clock relogio;
	ListaEntidade ListaBolas;
	Jogador* j;

public:
	Fase_teste();
	~Fase_teste();
	void inicializar(GerenciadorGrafico* gg);
	int executar(GerenciadorGrafico* gg);
};