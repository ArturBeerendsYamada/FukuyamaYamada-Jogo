#pragma once

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Vetor2D.h"

class GerenciadorGrafico{
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        std::map<const std::string, sf::Texture*> texturas;

    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();
        void mostrar() const;
        void limpar(int r = 0, int g = 0, int b = 0);
        void desenhar(const std::string& caminho, const Vetor2F posicao, const Vetor2F tamanho);
        bool carregarTextura(const std::string& caminho);
        void centralizar(const Vetor2F centro);
        sf::RenderWindow* getJanela() const;
        std::map<const std::string, sf::Texture*> getTextura();

};