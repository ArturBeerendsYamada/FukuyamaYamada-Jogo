#include "../lib/Obstaculo.h"

Obstaculo::Obstaculo(Vetor2F pos, const char *textu, Vetor2F tam, Vetor2F vel):
	Entidade(pos, textu, tam, vel)
{
	vel = Vetor2F(0.0f, 0.0f);
	velocidade = vel;
	idColisao = IdsColisao::solido;
}

Obstaculo::~Obstaculo(){}

void Obstaculo::inicializar() {}
void Obstaculo::atualizar(float deltaT) {deltaT = deltaT;}

void Obstaculo::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY)
{
	direcao = direcao;
	outro = outro;
	interY = interY;
	interX = interX;
}