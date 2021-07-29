#include "../headers/Principal.h"

Principal::Principal():
    janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1")},
    amigo{0, 0, "Brasil_Countryball.png"}{
}

Principal::~Principal(){
    delete janela;
}

int Principal::executar(){
    while (true){
        janela->clear();
        amigo.atualizar();
        amigo.desenhar(janela);
        janela->display();
    }
    return 0;
}