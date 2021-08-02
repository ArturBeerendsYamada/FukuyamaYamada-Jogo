#pragma once

template <typename TF>
class Lista
{
private:
	template <typename TE>
	class ElementoLista
	{
	private:
		TE info;
		ElementoLista* pElLProx;
		ElementoLista* pElLAnt;

	public:
		ElementoLista(TE info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
		~ElementoLista();

		ElementoLista* getAnt() const;
		void setAnt(ElementoLista* Ant);
		ElementoLista* getProx() const;
		void setProx(ElementoLista* Prox);
		TE getInfo() const;
		void setInfo(TE Info);
	};

	ElementoLista<TF>* pElLIn;
	ElementoLista<TF>* pElLFin;
	ElementoLista<TF>* pElLAt;

public:
	Lista();
	~Lista();

	void inserir(TF info);
	void esvaziar();

	TF voltarInicio();
	TF irProximo();
};

#include "ListaImplementacao.h"