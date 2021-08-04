#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Lista.h"
#include "ListaPersonagem.h"
#include "GerenciadorGrafico.h"

class Fase_teste
{
private:
	GerenciadorGrafico *gerenciadorGrafico;
	sf::Clock relogio;
	ListaPersonagem ListaBolas;

public:
	Fase_teste();
	~Fase_teste();
	void inicializar();
	void executar();

};