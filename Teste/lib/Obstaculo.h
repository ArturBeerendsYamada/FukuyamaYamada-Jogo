#pragma once

#include "Entidade.h"

class Obstaculo : public Entidade
{
public:
	Obstaculo(Vetor2F pos, const char *textu, Vetor2F tam, Vetor2F vel);
	~Obstaculo();

	void inicializar();
	void atualizar(float deltaT);

	void colidir(Entidade *outro);
};