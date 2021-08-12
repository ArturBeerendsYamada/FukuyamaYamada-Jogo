#pragma once
#include "Entidade.h"
#include "Lista.h"
class ListaEntidade
{
private:
	Lista<Entidade*> lista;

public:
	ListaEntidade();
	~ListaEntidade();

	void inserir(Entidade* info);
	//void esvaziar();

	void inicializarEntidades(GerenciadorGrafico &g);
	void atualizarEntidades(float t);
	void desenharEntidades(GerenciadorGrafico &g);
	void destruirEntidades();
	void removerEntidades(Entidade* info);
};