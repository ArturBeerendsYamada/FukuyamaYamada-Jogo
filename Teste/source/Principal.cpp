//#include "../headers/Principal.h"
#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal():menu_inicial(),fase()//:
    //janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "TheBallGame")}
    //amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png")
    {
        //janela->setPosition({0, 0});
    }

void Principal::inicia_fase()
{
    Principal::fase.inicializar();
}

Principal::~Principal(){
    //delete janela;

}

void Principal::executar(){
    int controle_menu = menu_inicial.executar();
    while(controle_menu!=1)
    {
        if(controle_menu==0)
        {
            controle_menu = 1;
            fase.inicializar();
        }
    }
}