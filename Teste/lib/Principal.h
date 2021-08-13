#pragma once

#include "Fase_teste.h"
#include "Floresta.h"
#include "GerenciadorGrafico.h"
#include "Ids.h"
#include "ListaEntidade.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <time.h>

class Principal
{
private:
	GerenciadorGrafico* gg;
	Menu* menu_inicial;
	Fase_teste* fase;

public:
	Principal();
	~Principal();
	void executar();
};
