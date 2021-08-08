//#include "../headers/Personagem.h"
#include "../lib/Personagem.h"

Personagem::Personagem(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
	Entidade(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsCollisao::jogador;
}

Personagem::~Personagem()
{
}

void Personagem::inicializar()
{
}

void Personagem::atualizar(float deltaT)
{
	posicao += velocidade * deltaT;
}