#include "../lib/ProjetilInimigo.h"
ProjetilInimigo::ProjetilInimigo(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, const bool Existe) :
Projetil(pos, caminho, tam, vel, Existe)
{
    idColisao = IdsColisao::projetilInimigo;
    alcance = 200;
}

ProjetilInimigo::~ProjetilInimigo()
{
}

void ProjetilInimigo::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY){
    direcao = direcao;
	outro = outro;
	interY = interY;
	interX = interX;
    if(outro->getIdColisao() != IdsColisao::alemanha && outro->getIdColisao() != IdsColisao::italia && outro->getIdColisao() != IdsColisao::japao && outro->getIdColisao() != IdsColisao::projetilInimigo && outro->getIdColisao() != IdsColisao::arame_farpado)
    {
        this->setExiste(false);
    }
}

void ProjetilInimigo::inicializar(){

}