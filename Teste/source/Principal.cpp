#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal():menu_inicial(nullptr),fase(nullptr)//:
    //janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "TheBallGame")}
    //amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png")
    {
        //janela->setPosition({0, 0});
    }

Principal::~Principal(){
    //delete janela;
    if (menu_inicial)
    {
        delete menu_inicial;
    }
    if (fase)
    {
        delete fase;
    }
}

void Principal::executar(){
    menu_inicial = new Menu;
    int controle_menu = menu_inicial->executar();
    delete menu_inicial;

    while(controle_menu!=1)
    {
        if(controle_menu==0)
        {
            fase = new Fase_teste;
            fase->inicializar();
            delete fase;
        }

        menu_inicial = new Menu;
        controle_menu = menu_inicial->executar();
        delete menu_inicial;
    }
    cout << "ERRO?" << endl;
}