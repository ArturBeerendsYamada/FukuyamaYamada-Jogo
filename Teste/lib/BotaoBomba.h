#pragma once

#include "Entidade.h"
#include "Alemanha.h"

//podemos usar ideia similiar ao projetil? Rever pois parece q o projetil eh um botao mais complexo

class BotaoBombas : public Entidade
{
private: 
    bool existe; 
    Alemanha* alemao;

public:
    BotaoBombas(const Vetor2F pos, const char *caminho, const Vetor2F tam, Vetor2F vel, bool Existe);
    ~BotaoBombas();

    void naColisao(Vetor2F direcao, Entidade* outro, float interX, float interY);

    void inicializar() ;
	void atualizar(float deltaT) ;

    bool getExiste() const;
    void setExiste(const bool ativa);

    void setAlemanha(Alemanha* A);
};


