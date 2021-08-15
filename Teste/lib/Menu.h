#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorComandos.h"
#include <iostream>
using namespace std;

#define LARGURA 800
#define ALTURA 600
#define N_ITENS 5
#define SEL_TAM_FONT 48

#define BEGE 0xda, 0xc8, 0xb3

class Menu
{
private:
	int opcao_atual;
	sf::Font font;
	sf::Text indices_itens_menu[N_ITENS];
	sf::Text info;
	GerenciadorComandos* gc;

	void opcao_acima();
	void opcao_abaixo();

public:
	Menu();
	~Menu();

	void inicializar(GerenciadorGrafico* gg);
	int executar(GerenciadorGrafico* gg);

	void mostrar_creditos(GerenciadorGrafico* gg);
};