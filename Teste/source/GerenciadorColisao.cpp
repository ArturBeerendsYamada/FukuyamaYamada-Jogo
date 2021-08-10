#include "../lib/GerenciadorColisao.h"
#include "../lib/Entidade.h"

#include "../lib/Vetor2D.h"

#include <math.h>

#include <iostream>

GerenciadorColisoes::GerenciadorColisoes()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

bool GerenciadorColisoes::estaoColidindo(Entidade* e1, Entidade* e2)
{

	Vetor2F posicao1 = e1->getPosicao();
	Vetor2F dimensoes1 = e1->getTamanho();

	Vetor2F posicao2 = e2->getPosicao();
	Vetor2F dimensoes2 = e2->getTamanho();

	Vetor2F distancia = posicao1 - posicao2;

	if (e1 == e2)
		return false;

	return (fabs(distancia.x) < (dimensoes1.x + dimensoes2.x) / 2.) && (fabs(distancia.y) < (dimensoes1.y + dimensoes2.y) / 2.);
}

void GerenciadorColisoes::adicionarEntidade(Entidade* e)
{
	colidiveis.insert(e);
}

void GerenciadorColisoes::removerEntidade(Entidade* e)
{
	colidiveis.erase(e);
}

void GerenciadorColisoes::removerTodos()
{
	colidiveis.clear();
}

void GerenciadorColisoes::verificarColisoes()
{
	std::set<Entidade*>::iterator itr1;
	for (itr1 = colidiveis.begin(); itr1 != colidiveis.end(); itr1++)
	{
		std::set<Entidade*>::iterator itr2;
		for (itr2 = itr1; itr2 != colidiveis.end(); itr2++)
		{
			Entidade* e1 = *itr1;
			Entidade* e2 = *itr2;
			if (e1 != e2 && //soh testa se forem objetos diferentes e pelo menos um pode se mexer
				((e1->getIdColisao() != IdsCollisao::mina && e1->getIdColisao() != IdsCollisao::arame_farpado && e1->getIdColisao() != IdsCollisao::solido)
				|| (e2->getIdColisao() != IdsCollisao::mina && e2->getIdColisao() != IdsCollisao::arame_farpado && e2->getIdColisao() != IdsCollisao::solido)))
			{
				float deltaX = e1->getPosicao().x - e2->getPosicao().x;
				float deltaY = e1->getPosicao().y - e2->getPosicao().y;
				float interX = abs(deltaX) - (e1->getTamanho().x / 2 + e2->getTamanho().x / 2);
				float interY = abs(deltaY) - (e1->getTamanho().y / 2 + e2->getTamanho().y / 2);

				if (interY < 0.0f && interX < 0.0f)
				{
					if (interX > interY)
					{
						if (deltaX > 0.0f)
						{
							e1->naColisao(ESQUERDA, e2, interX, interY);
							e2->naColisao(DIREITA, e1, interX, interY);
						}
						else
						{
							e1->naColisao(DIREITA, e2, interX, interY);
							e2->naColisao(ESQUERDA, e1, interX, interY);
						}
					}
					else
					{
						if (deltaY > 0.0f)
						{
							e1->naColisao(ACIMA, e2, interX, interY);
							e2->naColisao(ABAIXO, e1, interX, interY);
						}
						else
						{
							e1->naColisao(ABAIXO, e2, interX, interY);
							e2->naColisao(ACIMA, e1, interX, interY);
						}
					}
				} //fecha if que verifica se estao de fato colidindo
			}	  //fecha if que verifica se eh plausivel colidir
		}		  //fecha for da segunda entidade
	}
}
