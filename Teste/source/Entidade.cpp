#include "../lib/Entidade.h"

Entidade::Entidade(Vetor2F pos, const char *textu, Vetor2F tam, Vetor2F vel):
	Desenhavel(pos, textu, tam), velocidade(vel), idColisao(IdsCollisao::nulo){}
Entidade::~Entidade(){}

void Entidade::setVelocidade (const Vetor2F vel) {velocidade = vel;}
const Vetor2F Entidade::getVelocidade () const {return velocidade;}

void Entidade::mover(Vetor2F deslocamento)
{
	posicao = posicao + deslocamento;
}

void Entidade::colidir(Entidade* outro){
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		printf("Colidiu %d %d\n", idColisao, outro->getIdColisao());
		if(interX > interY){
			printf("Colidiu de lado - ");
			if(deltaX > 0.0f){
				printf("colisao pela esquerda\n");
				this->mover(Vetor2F(interX/2.0, 0.0f));
				outro->mover(Vetor2F(-interX/2.0, 0.0f));
			}
			else{
				printf("colisao pela direita\n");
				this->mover(Vetor2F(-interX/2.0, 0.0f));
				outro->mover(Vetor2F(interX/2.0, 0.0f));
			}
		}
		else{
			printf("colidiu de pe - ");
			if(deltaY > 0.0f){
				printf("colisao por baixo\n");
				this->mover(Vetor2F(0.0f, interY/2.0));
				outro->mover(Vetor2F(0.0f, -interY/2.0));
			}
			else{
				printf("colisao por cima\n");
				this->mover(Vetor2F(0.0f, -interY/2.0));
				outro->mover(Vetor2F(0.0f, interY/2.0));
			}
		}
	}
}

IdsCollisao Entidade::getIdColisao() const{
	return idColisao;
}
