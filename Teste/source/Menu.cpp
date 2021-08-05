#include "../lib/Menu.h"

#include "../lib/Principal.h"

Menu::Menu():janela{new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "TheBallGame - MENU")}
{

	if (!font.loadFromFile("mytype.ttf"))
	{
		cout << "Fonte nao carregada" << endl;
	}

	indices_itens_menu[0].setFont(font);
	indices_itens_menu[0].setFillColor(sf::Color::Red);
	indices_itens_menu[0].setStyle(0b11);
	indices_itens_menu[0].setCharacterSize(SEL_TAM_FONT);
	indices_itens_menu[0].setString("Fases");
	indices_itens_menu[0].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 1));

	indices_itens_menu[1].setFont(font);
	indices_itens_menu[1].setFillColor(sf::Color::Black);
	indices_itens_menu[1].setString("Rankings");
	indices_itens_menu[1].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 2));

	indices_itens_menu[2].setFont(font);
	indices_itens_menu[2].setFillColor(sf::Color::Black);
	indices_itens_menu[2].setString("Creditos");
	indices_itens_menu[2].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 3));

	indices_itens_menu[3].setFont(font);
	indices_itens_menu[3].setFillColor(sf::Color::Black);
	indices_itens_menu[3].setString("Sair");
	indices_itens_menu[3].setPosition(sf::Vector2f(LARGURA / 6, ALTURA / (N_ITENS + 1) * 4));

	opcao_atual = 0;

	info.setFont(font);
	info.setCharacterSize(SEL_TAM_FONT/4);
	info.setFillColor(sf::Color::Black);
	info.setString("Para navegar pelo menu, use as setas do teclado. Para selecionar uma opcao, aperte Enter");
	info.setPosition(sf::Vector2f(10.f, 6.f));
}
Menu::~Menu(){}

int Menu::executar()
{
	while(janela->isOpen())
	{
		sf::Event event;
		while(janela->pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased)
			{
				switch(event.key.code)
				{
					case sf::Keyboard::Up:
						opcao_acima();
						break;

					case sf::Keyboard::Down:
						opcao_abaixo();
						break;

					case sf::Keyboard::Return:
						switch (opcao_atual)
						{
							case 0:
							janela->close();
								return 0;

							case 1:
								mostrar_ranking();
								break;

							case 2:
								mostrar_creditos();
								break;

							default:
								janela->close();
								return 1;
						};
						break;

					default:
						break;
				}

			}

			else if(event.type == sf::Event::Closed)
				janela->close();
		}

		janela->clear(sf::Color(BEGE));//rgb para bege
		for (int i=0;i<N_ITENS;i++)
			janela->draw(indices_itens_menu[i]);
		janela->draw(info);
		janela->display();


	}
	exit(0);
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

void Menu::mostrar_ranking()
{
	janela->clear(sf::Color(BEGE));
	sf::Text em_breve;
	em_breve.setFont(font);
	em_breve.setFillColor(sf::Color::Red);
	em_breve.setString("Ainda nao implementado\n:(");
	janela->draw(em_breve);
	janela->display();

	while(janela->isOpen())
	{
		sf::Event event;
		while(janela->pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased)
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

void Menu::mostrar_creditos()
{
	janela->clear(sf::Color(BEGE));
	sf::Text em_breve;
	em_breve.setFont(font);
	em_breve.setFillColor(sf::Color::Red);
	em_breve.setString("Bla bla\n:)");
	janela->draw(em_breve);
	janela->display();

	while(janela->isOpen())
	{
		sf::Event event;
		while(janela->pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased)
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