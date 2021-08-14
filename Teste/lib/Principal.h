#pragma once

#include "Fase.h"
#include "Floresta.h"
#include "Praia.h"
#include "Tutorial.h"
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
	Fase* fase;

public:
	Principal();
	~Principal();
	void executar();
};
