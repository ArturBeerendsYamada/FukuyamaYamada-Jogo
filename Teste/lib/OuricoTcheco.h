#include "Obstaculo.h"

class OuricoTcheco : public Obstaculo
{
public:
	OuricoTcheco(Vetor2F pos, const char* textu, Vetor2F tam, Vetor2F vel);
	~OuricoTcheco();

	void atualizar(float deltaT);
	void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);
};