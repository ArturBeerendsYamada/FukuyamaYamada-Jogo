#include "Obstaculo.h"

class Mina : public Obstaculo
{
public:
	Mina(Vetor2F pos, const char *textu, Vetor2F tam, Vetor2F vel);
	~Mina();

	void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};