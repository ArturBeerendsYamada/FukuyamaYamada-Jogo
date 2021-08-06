#pragma once
#include <set>

#include "Entidade.h"

class Entidade;

class GerenciadorColisoes {
private:
    std::set<Entidade*> colidiveis;
    bool estaoColidindo(Entidade* e1, Entidade* e2);

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    void adicionarEntidade(Entidade* e);
    void removerEntidade(Entidade* e);
    void removerTodos();
    void verificarColisoes();
};

