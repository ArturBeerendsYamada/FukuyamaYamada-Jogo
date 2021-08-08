#include "Obstaculo.h"

Obstaculo::Obstaculo(Vetor2F pos, const char *textu, Vetor2F tam, Vetor2F vel):
	Entidade(pos, textu, tam, vel)
{
	vel = Vetor2F(0.0f, 0.0f);
	velocidade = vel;
	idColisao = IdsCollisao::solido;
}

Obstaculo::~Obstaculo(){}

void Obstaculo::inicializar() {}
void Obstaculo::atualizar(float deltaT) {deltaT = deltaT;}

void Obstaculo::colidir(Entidade *outro)
{
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		if(interX > interY){
			if(deltaX > 0.0f){
				if (outro->getIdColisao()==IdsCollisao::inimigo){
					outro->mover(Vetor2F(-interX, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::jogador){
					printf("parede pela esquerda\n");
					outro->mover(Vetor2F(-interX, 0.0f));
				}
			}
			else{
				if (outro->getIdColisao()==IdsCollisao::inimigo){
					outro->mover(Vetor2F(interX, 0.0f));
				}
				else if (outro->getIdColisao()==IdsCollisao::jogador){
					printf("parede pela direita\n");
					outro->mover(Vetor2F(interX, 0.0f));
				}
			}
		}
		else{
			if(deltaY > 0.0f){
				if(outro->getIdColisao()==IdsCollisao::inimigo){
					outro->mover(Vetor2F(0.0f, -interY));
				}
				else if (outro->getIdColisao()==IdsCollisao::jogador)
				{
					printf("teto acima\n");
					outro->mover(Vetor2F(0.0f, -interY));
					//outro->setPular(true);
				}
			}
			else{
				if(outro->getIdColisao()==IdsCollisao::inimigo){
					outro->mover(Vetor2F(0.0f, interY));
				}
				else if (outro->getIdColisao()==IdsCollisao::jogador)
				{
					printf("chao abaixo\n");
					outro->setVelocidade(Vetor2F(outro->getVelocidade().x, 0.0f));
					outro->mover(Vetor2F(0.0f, interY));
				}
			}
		}
	}
}