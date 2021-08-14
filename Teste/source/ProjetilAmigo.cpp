#include "../lib/ProjetilAmigo.h"
#include <iostream>

ProjetilAmigo::ProjetilAmigo(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, const bool Existe) :
Projetil(pos, caminho, tam, vel, Existe)
{
    alcance = 1500;
    idColisao = IdsColisao::projetilAmigo;
}

ProjetilAmigo::~ProjetilAmigo()
{
}

void ProjetilAmigo::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY){
    direcao = direcao;
	outro = outro;
	interY = interY;
	interX = interX;
    if(outro->getIdColisao() != IdsColisao::jogador && outro->getIdColisao() != IdsColisao::projetilInimigo && outro->getIdColisao() != IdsColisao::arame_farpado)
    {
        this->setExiste(false);
    }
}

void ProjetilAmigo::inicializar(){

}
