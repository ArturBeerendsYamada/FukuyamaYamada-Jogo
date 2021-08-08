#pragma once
#include <set>

#include "Entidade.h"

#define ACIMA Vetor2F(0.0f, -1.0f)
#define ABAIXO Vetor2F(0.0f, 1.0f)
#define DIREITA Vetor2F(1.0f, 0.0f)
#define ESQUERDA Vetor2F(1.0f, 0.0f)

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

