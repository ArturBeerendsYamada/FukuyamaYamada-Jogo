#include "../lib/Entidade.h"

Entidade::Entidade(Vetor2F pos, const char *textu, Vetor2F vel, Vetor2F tam):
	Desenhavel(pos, textu), velocidade(vel), tamanho(tam), idColisao(IdsCollisao::nulo){}
Entidade::~Entidade(){}

void Entidade::setVelocidade (const Vetor2F vel) {velocidade = vel;}
const Vetor2F Entidade::getVelocidade () const {return velocidade;}

void Entidade::setTamanho(const Vetor2F tamanho)
{
    this->tamanho = tamanho;
}
Vetor2F Entidade::getTamanho() const
{
	return tamanho;
}

void Entidade::colidir(const IdsCollisao Id,const Vetor2F Pos,const Vetor2F Tam){
	float deltaX = Pos.x - getPosicao().x;
	float deltaY = Pos.y - getPosicao().y;
	float interX = abs(deltaX) - (Tam.x / 2 + getTamanho().x / 2);
	float interY = abs(deltaY) - (Tam.y / 2 + getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		printf("Colidiu %d %d\n", idColisao, Id);
		if(interX > interY){
			if(deltaX > 0.0f){
				this->setPosicao(posicao - Vetor2F(fabs((interX/2)),0.0f));
			}
			else{
				this->setPosicao(posicao + Vetor2F(fabs((interX/2)),0.0f));
			}
		}
		else{
			if(deltaY > 0.0f){
				this->setPosicao(posicao - Vetor2F(0.0f,fabs((interY/2))));
			}
			else{
				this->setPosicao(posicao + Vetor2F(0.0f,fabs((interY/2))));
			}
		}
	}
}

IdsCollisao Entidade::getIdColisao() const{
	return idColisao;
}
