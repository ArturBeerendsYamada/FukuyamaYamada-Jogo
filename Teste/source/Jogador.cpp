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

void Jogador::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(textura, posicao);
	g.centralizar(posicao);
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

/*void Jogador::colidir(Entidade* outro)
{
	float deltaX = outro->getPosicao().x - this->getPosicao().x;
	float deltaY = outro->getPosicao().y - this->getPosicao().y;
	float interX = abs(deltaX) - (outro->getTamanho().x / 2 + this->getTamanho().x / 2);
	float interY = abs(deltaY) - (outro->getTamanho().y / 2 + this->getTamanho().y / 2);

	if(interY < 0.0f && interX < 0.0f){
		printf("Colidiu %d %d\n", idColisao, outro->getIdColisao());
		if(interX > interY){
			printf("Colidiu de lado");
			if(deltaX > 0.0f){
				printf("colisao pela esquerda");
				this->mover(Vetor2F(-interX/2.0, 0.0f));
				outro->mover(Vetor2F(interX/2.0, 0.0f));
			}
			else{
				printf("colisao pela direita");
				this->mover(Vetor2F(interX/2.0, 0.0f));
				outro->mover(Vetor2F(-interX/2.0, 0.0f));
			}
		}
		else{
			printf("colidiu de cima");
			if(deltaY > 0.0f){
				printf("colisao por baixo");
				this->mover(Vetor2F(0.0f, interY/2.0));
				outro->mover(Vetor2F(0.0f, -interY/2.0));
			}
			else{
				printf("colisao por cima");
				this->mover(Vetor2F(0.0f, -interY/2.0));
				outro->mover(Vetor2F(0.0f, interY/2.0));
			}
		}
	}
}*/