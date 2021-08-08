#include "../lib/Jogador.h"
#include <iostream>
using namespace std;

Jogador::Jogador(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
	Personagem(pos, caminhoTextura, tam, vel)
{
	gerenciador_comandos_jogador = GerenciadorComandos::getComandos();
	pode_pular = false;
}
Jogador::~Jogador()
{
}

void Jogador::inicializar()
{

}

void Jogador::setPular (const bool p) {pode_pular = p;}
bool Jogador::getPular () {return pode_pular;}

void Jogador::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(textura, posicao, tamanho);
	g.centralizar(posicao);
}

void Jogador::atualizar(float deltaT)
{
	velocidade = Vetor2F(0.f, 0.f);
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if(((pressionados >> GerenciadorComandos::esquerda1) % 2) == 1)//verifica se o bit relativo ao comando estah setado
	{
		velocidade.x -= ACCEL * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::direita1) % 2))
	{
		velocidade.x += ACCEL * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::pular1) % 2))
	{
		velocidade.y -= ACCEL * deltaT;
	}
	if(((pressionados >> GerenciadorComandos::atirar1) % 2))
	{
		velocidade.y += ACCEL * deltaT;
	}

	this->mover(velocidade);
}

void Jogador::colidir(Entidade* outro){
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		if(interX > interY){
			if(deltaX > 0.0f){
				if (outro->getIdColisao()==IdsCollisao::inimigo){
					printf("morte pela direita\n");
					this->mover(Vetor2F(interX/2.0, 0.0f));
					outro->mover(Vetor2F(-interX/2.0, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido){
					printf("parede pela direita\n");
					this->mover(Vetor2F(interX, 0.0f));
				}
			}
			else{
				if (outro->getIdColisao()==IdsCollisao::inimigo){
					printf("morte pela esquerda\n");
					this->mover(Vetor2F(-interX/2.0, 0.0f));
					outro->mover(Vetor2F(interX/2.0, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido){
					printf("parede pela esquerda\n");
					this->mover(Vetor2F(-interX, 0.0f));
				}
			}
		}
		else{
			if(deltaY > 0.0f){
				if(outro->getIdColisao()==IdsCollisao::inimigo){
					printf("pulo por inimigo :D\n");
					this->mover(Vetor2F(0.0f, interY/2.0));
					outro->mover(Vetor2F(0.0f, -interY/2.0));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido)
				{
					printf("chao abaixo\n");
					this->mover(Vetor2F(0.0f, interY));
					this->setPular(true);
				}
			}
			else{
				if(outro->getIdColisao()==IdsCollisao::inimigo){
					printf("morte por cima\n");
					this->mover(Vetor2F(0.0f, -interY/2.0));
					outro->mover(Vetor2F(0.0f, interY/2.0));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido)
				{
					printf("teto acima\n");
					this->mover(Vetor2F(0.0f, -interY));
				}
			}
		}
	}
}