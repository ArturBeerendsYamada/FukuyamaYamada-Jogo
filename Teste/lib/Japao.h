#pragma once

#include "Inimigo.h"
#include "ProjetilInimigo.h"

class Fase_teste;

class Japao: public Inimigo
{
private:
    Fase_teste* fase;
    ProjetilInimigo* tiroinimigo;
    bool pode_atirar;

public:
    Japao(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
    ~Japao();

    void atualizar(float deltaT);
    void atirar();
    void setFase(Fase_teste* Fase);
};