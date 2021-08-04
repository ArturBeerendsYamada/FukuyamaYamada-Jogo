#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "ListaPersonagem.h"
#include "GerenciadorGrafico.h"
#include "Fase_teste.h"
#include "Menu.h"

class Principal{
    private:
        Menu menu_inicial;
        Fase_teste fase;

    public:
        Principal();
        ~Principal();
        void executar();
        void inicia_fase();
};
