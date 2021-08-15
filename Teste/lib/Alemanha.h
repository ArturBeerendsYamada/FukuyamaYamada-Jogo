#pragma once

#include "Inimigo.h"
#include "ProjetilInimigo.h"

class Fase;

class Alemanha: public Inimigo
{
private:
    Fase* fase;
public:
    Alemanha(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
    ~Alemanha();

    void atualizar(float deltaT);
    void setFase(Fase* Fase);
    void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};