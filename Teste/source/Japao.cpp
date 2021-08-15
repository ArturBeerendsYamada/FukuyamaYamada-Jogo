#include "../lib/Japao.h"
#include "../lib/Fase.h"
#include <iostream>

Japao::Japao(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    tiroinimigo = NULL;
    pode_atirar = true;
    idColisao = IdsColisao::japao;
    direcao_projetil = 1;
}

Japao::Japao(int dir, Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Inimigo(pos, caminhoTextura, tam, vel)
{
    tiroinimigo = NULL;
    pode_atirar = true;
    idColisao = IdsColisao::japao;
    direcao_projetil = dir;
}

Japao::~Japao(){
 //   fase->remover(tiroinimigo);
//    delete tiroinimigo;
}

void Japao::atualizar(float deltaT)
{
    deltaT = deltaT;
    if (tiroinimigo)
    {
        if (abs(tiroinimigo->getPosicao().x - getPosicao().x) >= tiroinimigo->getAlcance() || !tiroinimigo->getExiste())
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
    tiroinimigo = new ProjetilInimigo(Vetor2F(posicao.x, posicao.y), "projetilInimigo.png", Vetor2F(50.0, 50.0), Vetor2F(direcao_projetil*500.0, 0.0), true);
    fase->adicionar(tiroinimigo);
    fase->inicializarTextura(tiroinimigo);
    pode_atirar = false;
}

void Japao::setFase(Fase* Fase){
	fase = Fase;
}