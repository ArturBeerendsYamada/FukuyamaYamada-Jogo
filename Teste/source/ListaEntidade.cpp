#include "../lib/ListaEntidade.h"

ListaEntidade::ListaEntidade()
{

}

ListaEntidade::~ListaEntidade()
{
	destruirEntidades();
}

void ListaEntidade::inserir(Entidade* info)
{
	lista.inserir(info);
}


void ListaEntidade::inicializarEntidades(GerenciadorGrafico &g)
{
	Entidade* p = lista.voltarInicio();

	while (p)
	{
		p->inicializarTextura(&g);
		p->inicializar();
		p = lista.irProximo();
	}
}

void ListaEntidade::atualizarEntidades(float t)
{
	Entidade* p = lista.voltarInicio();

	while (p)
	{
		p->atualizar(t);
		p = lista.irProximo();
	}

}

void ListaEntidade::desenharEntidades(GerenciadorGrafico &g)
{
	Entidade* p = lista.voltarInicio();

	while (p)
	{
		p->desenhar(g);
        p = lista.irProximo();
	}
}

void ListaEntidade::destruirEntidades()
{
	Entidade* p = lista.voltarInicio();

	while (p)
	{
		delete p;
        p = lista.irProximo();
	}

	lista.esvaziar();
}

void ListaEntidade::removerEntidades(Entidade* info)
{
	lista.removerElemento(info);
}