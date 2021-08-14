#include "../lib/ListaEntidade.h"
#include <vector>
#include <iostream>

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

	/*std::vector<Entidade*> v;

	while(p)
	{
		v.push_back(p);
		p = lista.irProximo();
	}
		for (std::size_t i = 0; i < v.size(); ++i) {
		for (std::size_t j = i + 1; j < v.size(); ++j) {
			if (v[i] == v[j]) printf("REPETIU!!!");
		}
    }
	*/
	p = lista.voltarInicio();

	while (p)
	{
		//printf("%d\n", p);
		//printf("%d\n", p->getIdColisao());
		std::cout << p->getTextura() <<std::endl;
		delete p;
		//printf("OLS\n");
        p = lista.irProximo();
		//printf("OL\n");
	}

	lista.esvaziar();
}

void ListaEntidade::removerEntidades(Entidade* info)
{
	lista.removerElemento(info);
}