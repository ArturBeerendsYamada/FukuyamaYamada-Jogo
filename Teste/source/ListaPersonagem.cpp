#include "../lib/ListaPersonagem.h"

ListaPersonagem::ListaPersonagem()
{

}

ListaPersonagem::~ListaPersonagem()
{
	destruirPersonagens();
}

void ListaPersonagem::inserir(Personagem* info)
{
	lista.inserir(info);
}


void ListaPersonagem::inicializarPersonagens(GerenciadorGrafico &g)
{
	Personagem* p = lista.voltarInicio();

	while (p)
	{
		p->inicializar(g);

		p = lista.irProximo();
	}
}

void ListaPersonagem::atualizarPersonagens(float t)
{
	Personagem* p = lista.voltarInicio();

	while (p)
	{
		p->atualizar(t);
		p = lista.irProximo();
	}

}

void ListaPersonagem::desenharPersonagens(GerenciadorGrafico &g)
{
	Personagem* p = lista.voltarInicio();

	while (p)
	{
		p->desenhar(g);
        p = lista.irProximo();
	}
}

void ListaPersonagem::destruirPersonagens()
{
	Personagem* p = lista.voltarInicio();

	while (p)
	{
		delete p;
        p = lista.irProximo();
	}

	lista.esvaziar();
}