#pragma once

#include "Fase.h"

class Floresta : public Fase
{
private:
	int reiniciaFase();
	int proximaFase();
	void limpar();
public:
	Floresta();
	~Floresta();
	void inicializar(GerenciadorGrafico* gg);
};