#pragma once

#include "Projetil.h"

class ProjetilInimigo : public Projetil
{
private:
    float alcance;
public:
    ProjetilInimigo(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, const bool Existe);
    ~ProjetilInimigo();

    float getAlcance() const {return alcance;}

    void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
    void inicializar();
};
