#include "../lib/Japao.h"
#include "../lib/Fase_teste.h"
#include <iostream>

Japao::Japao(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    pode_atirar = true;
}

Japao::~Japao(){    
}

void Japao::atualizar(float deltaT)
{
    if (tiroinimigo)
    {
        if (abs(tiroinimigo->getPosicao().x - getPosicao().x) >= 100)
        {
            printf("1\n");
            fase->remover(tiroinimigo);
            tiroinimigo = nullptr;
            pode_atirar = true;
        }
    }

    if (pode_atirar)
    {
        printf("2\n");
        atirar();
        pode_atirar = false;
    }
} 

void Japao::atirar()
{
    printf("3\n");
    tiroinimigo = new ProjetilInimigo(Vetor2F(posicao.x, posicao.y), "projetilInimigo.png", Vetor2F(50.0, 50.0), Vetor2F(200.0, 0.0), true);
    fase->adicionar(tiroinimigo);
    fase->inicializarTextura(tiroinimigo);
    pode_atirar = false;
}

void Japao::setFase(Fase_teste* Fase){
	fase = Fase;
}