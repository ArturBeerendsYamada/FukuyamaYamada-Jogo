#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#define LARGURA 800
#define ALTURA 600
#define N_ITENS 4
#define SEL_TAM_FONT 48

#define BEGE 0xda, 0xc8, 0xb3


class Menu
{
	private:
		int opcao_atual;
		sf::Font font;
		sf::Text indices_itens_menu[N_ITENS];
		sf::Text info;
		sf::RenderWindow *janela;

	public:
		Menu();
		~Menu();

		int executar();
		void opcao_acima();
		void opcao_abaixo();

		void mostrar_ranking();
		void mostrar_creditos();
};