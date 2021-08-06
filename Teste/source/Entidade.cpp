#include "../lib/Entidade.h"

Entidade::Entidade(Vetor2F pos, const char *textu, Vetor2F vel):
	Desenhavel(pos, textu), velocidade(vel){}
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

void Entidade::colidir(const Ids Id,const Vetor2F Pos,const Vetor2F Tam){
	if(Id == Ids::inimigo)
	{
		float deltaX = Pos.x - getPosicao().x;
        float deltaY = Pos.y - getPosicao().y;
        float interX = abs(deltaX) - (Tam.x / 2 + getTamanho().x / 2);
        float interY = abs(deltaY) - (Tam.y / 2 + getTamanho().y / 2);

	}
}

Ids Entidade::getId() const{
	return id;
}
