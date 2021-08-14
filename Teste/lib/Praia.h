#pragma once

#include "Fase_teste.h"

class Praia : public Fase_teste
{
private:
	int reiniciaFase();
	void limpar();

public:
	void inicializar(GerenciadorGrafico* gg);
};