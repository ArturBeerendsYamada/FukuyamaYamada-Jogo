#pragma once

#include "Vetor2D.h"
#include "GerenciadorGrafico.h"

class Personagem{
    private:
        Vetor2F posicao;
        Vetor2F v;
        const char* caminho;
        
    public:
        Personagem(Vetor2F pos = {0.0f, 0.0f}, Vetor2F vel = {0.0f, 0.0f}, const char* caminhoTextura = nullptr);
        ~Personagem();
        void atualizar(float t);
        void desenhar(GerenciadorGrafico &g);
        void inicializar(GerenciadorGrafico &g);
};
