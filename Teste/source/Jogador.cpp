#include "Jogador.h"
#include <iostream>
using namespace std;

Jogador::Jogador(Vetor2F pos, const char* caminhoTextura, Vetor2F vel):
	Personagem(pos, caminhoTextura, vel)
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