#pragma once

#include "Fase.h"

class Praia : public Fase
{
private:
	int reiniciaFase();
	int proximaFase();
	void limpar();

public:
	Praia();
	~Praia();
	void inicializar(GerenciadorGrafico* gg);
};