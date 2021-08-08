#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Lista.h"
#include "ListaEntidade.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorComandos.h"
#include "GerenciadorColisao.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Obstaculo.h"

class Fase_teste
{
private:
	GerenciadorGrafico *gerenciadorGrafico;
	GerenciadorComandos *gerenciador_comandos_fase_teste;
	GerenciadorColisoes *gerenciador_colisoes_fase_teste;
	sf::Clock relogio;
	ListaEntidade ListaBolas;

public:
	Fase_teste();
	~Fase_teste();
	void inicializar();
	void executar();

};