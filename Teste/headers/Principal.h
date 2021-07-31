#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Lista.h"

class Principal{
    private:
        sf::RenderWindow* janela;
        sf::Clock relogio;
        Lista ListaBolas;
    
    public:
        Principal();
        ~Principal();
        int executar();
};
