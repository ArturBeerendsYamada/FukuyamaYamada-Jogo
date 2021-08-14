#pragma once

#include "Inimigo.h"
#include "ProjetilInimigo.h"

class Fase_teste;

class Italia: public Inimigo
{
private:
    Fase_teste* fase;
    ProjetilInimigo* tiroinimigo;
    bool pode_pular;

public:
    Italia(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
    ~Italia();

    void atualizar(float deltaT);
    virtual void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};