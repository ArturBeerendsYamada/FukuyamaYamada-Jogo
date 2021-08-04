#pragma once

#include "Entidade.h"

class Personagem : public Entidade
{
public:
    Personagem(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F vel = {0.0f, 0.0f});
    ~Personagem();

    void inicializar();
    void atualizar(float deltaT);
};
