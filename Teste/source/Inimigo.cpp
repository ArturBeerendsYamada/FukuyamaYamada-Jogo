#include "../lib/Inimigo.h"
#include <iostream>
using namespace std;

Inimigo::Inimigo(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
	Personagem(pos, caminhoTextura, tam, vel)
{
	idColisao = IdsCollisao::inimigo;
}
Inimigo::~Inimigo()
{
}

void Inimigo::inicializar()
{

}
void Inimigo::atualizar(float deltaT)
{
	posicao += velocidade * deltaT;
}

void Inimigo::colidir(Entidade* outro){
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		if(interX > interY){
			if(deltaX > 0.0f){
				if (outro->getIdColisao()==IdsCollisao::jogador){
					printf("morte pela esquerda\n");
					this->mover(Vetor2F(interX/2.0, 0.0f));
					outro->mover(Vetor2F(-interX/2.0, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido){
					this->mover(Vetor2F(interX, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(interX/2.0, 0.0f));
					outro->mover(Vetor2F(-interX/2.0, 0.0f));
				}
			}
			else{
				if (outro->getIdColisao()==IdsCollisao::jogador){
					printf("morte pela direita\n");
					this->mover(Vetor2F(-interX/2.0, 0.0f));
					outro->mover(Vetor2F(interX/2.0, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido){
					this->mover(Vetor2F(-interX, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(-interX/2.0, 0.0f));
					outro->mover(Vetor2F(interX/2.0, 0.0f));
				}
			}
		}
		else{
			if(deltaY > 0.0f){
				if(outro->getIdColisao()==IdsCollisao::jogador){
					printf("morte por cima\n");
					this->mover(Vetor2F(0.0f, interY/2.0));
					outro->mover(Vetor2F(0.0f, -interY/2.0));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido)
				{
					this->mover(Vetor2F(0.0f, interY));
				}
				else if (outro->getIdColisao()==IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(0.0f, interY/2.0));
					outro->mover(Vetor2F(0.0f, -interY/2.0));
				}
			}
			else{
				if(outro->getIdColisao()==IdsCollisao::jogador){
					printf("Pulo por inimigo :D\n");
					this->mover(Vetor2F(0.0f, -interY/2.0));
					outro->mover(Vetor2F(0.0f, interY/2.0));
				}
				else if (outro->getIdColisao()==IdsCollisao::solido)
				{
					this->mover(Vetor2F(0.0f, -interY));
				}
				else if (outro->getIdColisao()==IdsCollisao::inimigo)
				{
					this->mover(Vetor2F(0.0f, -interY/2.0));
					outro->mover(Vetor2F(0.0f, interY/2.0));
				}
			}
		}
	}
}