#include "../lib/Jogador.h"
#include <iostream>
using namespace std;

Jogador::Jogador(Vetor2F pos, const char* caminhoTextura, Vetor2F vel, Vetor2F tam):
	Personagem(pos, caminhoTextura, vel, tam)
{
	gerenciador_comandos_jogador = GerenciadorComandos::getComandos();
}
Jogador::~Jogador()
{
}

void Jogador::inicializar()
{

}
void Jogador::atualizar(float deltaT)
{
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if(((pressionados >> GerenciadorComandos::esquerda1) % 2) == 1)//verifica se o bit relativo ao comando estah setado
	{
		posicao.x -= velocidade.x * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::direita1) % 2))
	{
		posicao.x += velocidade.x * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::pular1) % 2))
	{
		posicao.y -= velocidade.y * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::atirar1) % 2))
	{
		posicao.y += velocidade.y * deltaT;
	}
}

void Jogador::colidir(IdsCollisao Id, Vetor2F Pos, Vetor2F Tam)
{
	float deltaX = Pos.x - getPosicao().x;
	float deltaY = Pos.y - getPosicao().y;
	float interX = abs(deltaX) - (Tam.x / 2 + getTamanho().x / 2);
	float interY = abs(deltaY) - (Tam.y / 2 + getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		printf("Colidiu %d %d", idColisao, Id);
	}
}