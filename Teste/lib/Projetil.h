#pragma once

#include "Entidade.h"

class Projetil : public Entidade
{
private:
    bool existe;
    int alcance;
    bool frente;
public:
    Projetil(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, bool Existe);
    ~Projetil();

    virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY) = 0;

    bool getExiste() const;
    void setExiste(const bool ativa);
    virtual void atualizar(float deltaT);
    void setFrente(bool direcao);
};
