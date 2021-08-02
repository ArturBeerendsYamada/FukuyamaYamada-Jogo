#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "ListaPersonagem.h"
#include "GerenciadorGrafico.h"

class Principal{
    private:
        GerenciadorGrafico gerenciadorGrafico;
        sf::Clock relogio;
        ListaPersonagem ListaBolas;
    
    public:
        Principal();
        ~Principal();
        int executar();
};
