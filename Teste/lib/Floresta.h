#pragma once

#include "Fase_teste.h"

class Floresta : public Fase_teste
{
private:
	int reiniciaFase();
public:
	void inicializar(GerenciadorGrafico* gg);
};