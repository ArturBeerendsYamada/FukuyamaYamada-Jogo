#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Lista.h"
#include "GerenciadorGrafico.h"

class Principal{
    private:
        GerenciadorGrafico gerenciadorGrafico;
        sf::Clock relogio;
        Lista ListaBolas;
    
    public:
        Principal();
        ~Principal();
        int executar();
};
