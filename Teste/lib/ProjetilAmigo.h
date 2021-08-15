#pragma once

#include "Projetil.h"

class ProjetilAmigo : public Projetil
{
private:
    float alcance;
public:
    ProjetilAmigo(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, const bool Existe);
    ~ProjetilAmigo();

    float getAlcance() const {return alcance;}

    void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);


};
