#pragma once
#include "Personagem.h"
#include "Lista.h"
class ListaPersonagem
{
private:
	Lista<Personagem*> lista;

public:
	ListaPersonagem();
	~ListaPersonagem();

	void inserir(Personagem* info);
	//void esvaziar();

	void inicializarPersonagens(GerenciadorGrafico &g);
	void atualizarPersonagens(float t);
	void desenharPersonagens(GerenciadorGrafico &g);
	void destruirPersonagens();
};