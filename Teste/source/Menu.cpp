#include "../lib/Menu.h"

#include "../lib/Principal.h"

Menu::Menu()
{
	opcao_atual = 0;
	gc = NULL;
}
Menu::~Menu(){
}

void Menu::inicializar(GerenciadorGrafico *gg)
{
	gg->limpar();
	gg->centralizar(Vetor2F(400.0f, 300.0f));

	gc = GerenciadorComandos::getComandos();
	if (!font.loadFromFile("mytype.ttf"))
	{
		cout << "Fonte nao carregada" << endl;
	}

	indices_itens_menu[0].setFont(font);
	indices_itens_menu[0].setFillColor(sf::Color::Red);
	indices_itens_menu[0].setStyle(0b11);
	indices_itens_menu[0].setCharacterSize(SEL_TAM_FONT);
	indices_itens_menu[0].setString("Tutorial");
	indices_itens_menu[0].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 1));

	indices_itens_menu[1].setFont(font);
	indices_itens_menu[1].setFillColor(sf::Color::Black);
	indices_itens_menu[1].setString("Floresta");
	indices_itens_menu[1].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 2));

	indices_itens_menu[2].setFont(font);
	indices_itens_menu[2].setFillColor(sf::Color::Black);
	indices_itens_menu[2].setString("Praia");
	indices_itens_menu[2].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 3));

	indices_itens_menu[3].setFont(font);
	indices_itens_menu[3].setFillColor(sf::Color::Black);
	indices_itens_menu[3].setString("Rankings");
	indices_itens_menu[3].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 4));

	indices_itens_menu[4].setFont(font);
	indices_itens_menu[4].setFillColor(sf::Color::Black);
	indices_itens_menu[4].setString("Creditos");
	indices_itens_menu[4].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 5));

	indices_itens_menu[5].setFont(font);
	indices_itens_menu[5].setFillColor(sf::Color::Black);
	indices_itens_menu[5].setString("Sair");
	indices_itens_menu[5].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 6));

	opcao_atual = 0;

	info.setFont(font);
	info.setCharacterSize(SEL_TAM_FONT/4);
	info.setFillColor(sf::Color::Black);
	info.setString("Para navegar pelo menu, use as setas do teclado. Para selecionar uma opcao, aperte Enter");
	info.setPosition(sf::Vector2f(10.f, 6.f));
}

int Menu::executar(GerenciadorGrafico *gg)
{
	switch(gc->comandosMenu())
	{
		case GerenciadorComandos::Comandos::acima:
			opcao_acima();
			break;

		case GerenciadorComandos::Comandos::abaixo:
			opcao_abaixo();
			break;

		case GerenciadorComandos::Comandos::selecionar:
			switch (opcao_atual)
			{
				case 0:
					return IdsMenu::fase0_abre;

				case 1:
					return IdsMenu::fase1_abre;

				case 2:
					return IdsMenu::ranking;

				case 3:
					return IdsMenu::ranking;

				case 4:
					return IdsMenu::creditos;

				default:
					return IdsMenu::fecha;
			};
			break;

		default:
			break;
	}

	gg->getJanela()->clear(sf::Color(BEGE));//rgb para bege
	for (int i=0;i<N_ITENS;i++)
		gg->getJanela()->draw(indices_itens_menu[i]);
	gg->getJanela()->draw(info);
	gg->getJanela()->display();

	return menu_continua;
}

void Menu::opcao_acima()
{
	if(opcao_atual > 0)
	{
		indices_itens_menu[opcao_atual].setFillColor(sf::Color::Black);
		indices_itens_menu[opcao_atual].setStyle(0);
		indices_itens_menu[opcao_atual].setCharacterSize(SEL_TAM_FONT/2);

		opcao_atual--;

		indices_itens_menu[opcao_atual].setFillColor(sf::Color::Red);
		indices_itens_menu[opcao_atual].setStyle(0b11);
		indices_itens_menu[opcao_atual].setCharacterSize(SEL_TAM_FONT);
	}
}

void Menu::opcao_abaixo()
{
	if(opcao_atual < N_ITENS - 1)
	{
		indices_itens_menu[opcao_atual].setFillColor(sf::Color::Black);
		indices_itens_menu[opcao_atual].setStyle(0);
		indices_itens_menu[opcao_atual].setCharacterSize(SEL_TAM_FONT/2);

		opcao_atual++;

		indices_itens_menu[opcao_atual].setFillColor(sf::Color::Red);
		indices_itens_menu[opcao_atual].setStyle(0b11);
		indices_itens_menu[opcao_atual].setCharacterSize(SEL_TAM_FONT);
	}
}

void Menu::mostrar_ranking(GerenciadorGrafico *gg)
{
	gg->getJanela()->clear(sf::Color(BEGE));
	sf::Text em_breve;
	em_breve.setFont(font);
	em_breve.setFillColor(sf::Color::Red);
	em_breve.setString("Ainda nao implementado\n:(");
	gg->getJanela()->draw(em_breve);
	gg->getJanela()->display();

	while(gg->getJanela()->isOpen())
	{
		sf::Event event;
		while(gg->getJanela()->pollEvent(event))
		{
			if(gc->comandosMenu()!=GerenciadorComandos::Comandos::nulo)
			{
				return;
			}
			else if(event.type == sf::Event::Closed)
			{
				exit(0);
			}
		}
	}
}

void Menu::mostrar_creditos(GerenciadorGrafico *gg)
{
	gg->getJanela()->clear(sf::Color(BEGE));
	sf::Text texto;
	texto.setFont(font);
	texto.setFillColor(sf::Color::Black);
	texto.setCharacterSize(SEL_TAM_FONT/3);
	texto.setString(
	"\nJogo desenvolvido pelos alunos Artur Beerends Yamada e Eric Yutaka Fukuyama\n"
		"\nAgradecimentos (mais detalhes no documento relatorio):\n"
		"- aos monitores da disciplina Tecnicas de Programacao por auxilio no desenvolvimento\n"
		"- ao professor Jean Marcelo Simao pela orientacao do trabalho\n"
		"- Aos ex-monitores que disponibilizaram material guia\n"
		"- Aos canais Professor Aquino, Barji, Hilze Vonck por videos educativos\n\n"
		"- A"

		"\nPressione Enter para retornar");
	gg->getJanela()->draw(texto);
	gg->getJanela()->display();

	while(gg->getJanela()->isOpen())
	{
		sf::Event event;
		while(gg->getJanela()->pollEvent(event))
		{
			if(gc->comandosMenu()!=GerenciadorComandos::Comandos::nulo)
			{
				return;
			}
			else if(event.type == sf::Event::Closed)
			{
				exit(0);
			}
		}
	}
}