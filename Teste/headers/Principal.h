#pragma once

#include <SFML/Graphics.hpp>
#include "Personagem.h"

class Principal{
    private:
        sf::RenderWindow* janela;
        Personagem amigo;
    
    public:
        Principal();
        ~Principal();
        int executar();
};
