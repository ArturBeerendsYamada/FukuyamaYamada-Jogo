#include "../lib/GerenciadorColisao.h"
#include "../lib/Entidade.h"

#include "../lib/Vetor2D.h"

#include <math.h>

#include <iostream>

GerenciadorColisoes::GerenciadorColisoes() {

}

GerenciadorColisoes::~GerenciadorColisoes() {

}

bool GerenciadorColisoes::estaoColidindo(Entidade* e1, Entidade* e2) {

    Vetor2F posicao1 = e1->getPosicao();
    Vetor2F dimensoes1 = e1->getTamanho();

    Vetor2F posicao2 = e2->getPosicao();
    Vetor2F dimensoes2 = e2->getTamanho();

    Vetor2F distancia = posicao1 - posicao2;

    if (e1 == e2) return false;

    return (fabs(distancia.x) < (dimensoes1.x + dimensoes2.x)/2.) && (fabs(distancia.y) < (dimensoes1.y + dimensoes2.y)/2.);
}

void GerenciadorColisoes::adicionarEntidade(Entidade* e) {
    colidiveis.insert(e);
}

void GerenciadorColisoes::removerEntidade(Entidade* e) {
    colidiveis.erase(e);
}

void GerenciadorColisoes::removerTodos() {
    colidiveis.clear();
}

void GerenciadorColisoes::verificarColisoes()
{
    std::set<Entidade *>::iterator itr1;
    for (itr1 = colidiveis.begin(); itr1 != colidiveis.end(); itr1++)
    {
        std::set<Entidade *>::iterator itr2;
        itr2 = itr1;
        for (itr2; itr2 != colidiveis.end(); itr2++)
        {
            Entidade *e1 = *itr1;
            Entidade *e2 = *itr2;

            if (estaoColidindo(e1, e2))
            {
                e1->colidir(e2->getId(), e2->getPosicao(), e2->getTamanho());
                e2->colidir(e1->getId(), e1->getPosicao(), e1->getTamanho());
            }
        }
    }
}