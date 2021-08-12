#include "../lib/Japao.h"
#include "../lib/Fase_teste.h"
#include <iostream>

Japao::Japao(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    tiroinimigo = NULL;
    pode_atirar = true;
    idColisao = IdsColisao::japao;
}

Japao::~Japao(){
    fase->remover(tiroinimigo);
    delete tiroinimigo;
}

void Japao::atualizar(float deltaT)
{
    deltaT = deltaT;
    if (tiroinimigo)
    {
        if (abs(tiroinimigo->getPosicao().x - getPosicao().x) >= 100)
        {
            fase->remover(tiroinimigo);
            tiroinimigo = nullptr;
            pode_atirar = true;
        }
    }

    if (pode_atirar)
    {
        atirar();
        pode_atirar = false;
    }
}

void Japao::atirar()
{
    tiroinimigo = new ProjetilInimigo(Vetor2F(posicao.x, posicao.y), "projetilInimigo.png", Vetor2F(50.0, 50.0), Vetor2F(200.0, 0.0), true);
    fase->adicionar(tiroinimigo);
    fase->inicializarTextura(tiroinimigo);
    pode_atirar = false;
}

void Japao::setFase(Fase_teste* Fase){
	fase = Fase;
}