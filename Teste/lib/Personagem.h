#pragma once

#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    bool vida;
public:
    Personagem(Vetor2F pos = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vetor2F tam={0.f, 0.f}, Vetor2F vel = {0.0f, 0.0f});
    virtual ~Personagem();

    void setVida (const bool v) {vida = v;}
    bool getVida () const {return vida;}

    virtual void inicializar();
    virtual void atualizar(float deltaT);
    //virtual void colidir(const IdsCollisao id,const Vetor2F pos,const Vetor2F tam);
};
