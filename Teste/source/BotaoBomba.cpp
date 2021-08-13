#include "../lib/BotaoBomba.h"

BotaoBombas::BotaoBombas(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, bool existir) :
Entidade(pos, caminho, tam, vel)
{
	idColisao = IdsColisao::botao;
    existe = existir;
    alemao = nullptr;
}

BotaoBombas::~BotaoBombas()
{
}

bool BotaoBombas::getExiste() const
{
    return existe;
}

void BotaoBombas::setExiste(const bool existir)
{
    existe = existir;
}

void BotaoBombas::naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY){
    interX = interX;
    if(outro->getIdColisao() == IdsColisao::solido)
    {
        if (direcao == ABAIXO)
		{
            this->mover(Vetor2F(0.0f, interY));
		}
    }
    else if (outro->getIdColisao() == IdsColisao::jogador)
	{
		if (direcao == ACIMA)
		{
            setExiste(false);
            alemao->setVida(false);
		}
	}
}

void BotaoBombas::inicializar(){

}
void BotaoBombas::atualizar(float deltaT){
    deltaT = deltaT;
}
void BotaoBombas::setAlemanha(Alemanha* A){
    alemao = A;
}