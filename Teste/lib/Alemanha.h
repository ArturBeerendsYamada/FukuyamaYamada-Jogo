#pragma once

#include "Inimigo.h"
#include "ProjetilInimigo.h"
//#include "BotaoBomba.h"

class Fase_teste;

class Alemanha: public Inimigo
{
private:
    Fase_teste* fase;
    //BotaoBombas* botao;
public:
    Alemanha(Vetor2F pos = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vetor2F tam = { 0.f, 0.f }, Vetor2F vel = { 0.0f, 0.0f });
    ~Alemanha();

    void atualizar(float deltaT);
    void setFase(Fase_teste* Fase);
    //void setBotao(BotaoBombas* Botao);
    void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
    //void setVida(BotaoBombas* Botao);
};