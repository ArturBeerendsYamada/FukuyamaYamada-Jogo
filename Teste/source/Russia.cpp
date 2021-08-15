#include "../lib/Russia.h"
#include "../lib/Fase.h"

#define VEL_MAX 100.0f
#define PULO 210.0f
#define ACCEL 1000.0f
#define GRAV 4000.0f

Russia::Russia(Vetor2F pos, const char* caminhoTextura, Vetor2F tam, Vetor2F vel):
Jogador(pos, caminhoTextura, tam, vel)
{
}

Russia::~Russia()
{
}

void Russia::atualizar(float deltaT)
{
	tzinho = deltaT;
	velocidade.x = 0.0f;
	unsigned int pressionados = gerenciador_comandos_jogador->comandosBolas();
	if (((pressionados >> GerenciadorComandos::esquerda2) % 2) == 1) //verifica se o bit relativo ao comando estah setado
	{
		velocidade.x -= ACCEL;
		direcao_projetil = -1;
	}
	if (((pressionados >> GerenciadorComandos::direita2) % 2))
	{
		velocidade.x += ACCEL;
		direcao_projetil = 1;
	}
	if (((pressionados >> GerenciadorComandos::pular2) % 2) && pode_pular)
	{
		pode_pular = false;
		velocidade.y = -sqrtf(2.0 * GRAV * PULO);
	}
	velocidade.y += GRAV * deltaT;

	this->mover(velocidade * deltaT);

	if(((pressionados >> GerenciadorComandos::atirar2)%2) && pode_atirar)
	{
		atirar();
	}
	if(tiroamigo){
		if(!pode_atirar)
		{
			if(!tiroamigo->getExiste() || abs(tiroamigo->getPosicao().x - getPosicao().x) >= tiroamigo->getAlcance())
			{
				fase->remover(tiroamigo);
				delete tiroamigo;
				tiroamigo = NULL;
				pode_atirar = true;
			}
		}
	}
}