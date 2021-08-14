#pragma once

#include "Fase.h"

class Tutorial : public Fase
{
private:
	int reiniciaFase();
	int proximaFase();
	void limpar();

public:
	Tutorial();
	~Tutorial();
	void inicializar(GerenciadorGrafico* gg);
};