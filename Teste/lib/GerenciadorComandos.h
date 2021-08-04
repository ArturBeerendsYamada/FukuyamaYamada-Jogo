#pragma once
#include "GerenciadorGrafico.h"

class GerenciadorComandos
{
private:
	GerenciadorComandos();

	static GerenciadorComandos* g;
public:
	~GerenciadorComandos();

	static GerenciadorComandos* getComandos();

	enum Comandos
	{
		comeco, esquerda1, direita1, pular1, esquerda2, direita2, pular2, atirar1, atirar2,
		adicionar2, remover2, pausar, continuar, nulo

	};

	Comandos comandosBolas();
	Comandos comandosFuncionalidades();
};
