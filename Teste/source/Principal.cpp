#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal() :
	menu_inicial(nullptr),
	fase(nullptr) //:
//janela{new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "TheBallGame")}
//amigo(WIDTH/2, HEIGHT/2, "Brasil_Countryball.png")
{
    menu_inicial = new Menu;
    fase = NULL;
	gg = new GerenciadorGrafico;
	//janela->setPosition({0, 0});
}

Principal::~Principal()
{
	delete gg;
	if (menu_inicial)
	{
		delete menu_inicial;
	}
	if (fase)
	{
		delete fase;
	}
}

void Principal::executar()
{
    int controle = menu_abre;

    sf::Event event;
    while(gg->janelaAberta()){
        while (gg->getJanela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gg->getJanela()->close();
		}

        if(controle == IdsMenu::menu_abre){
            menu_inicial->inicializar(gg);
            controle = IdsMenu::menu_continua;
            //printf("%f %f\n", gg->getJanela()->getView().getCenter().x,  gg->getJanela()->getView().getCenter().y);
        }
        if(controle == IdsMenu::menu_continua){
            controle = menu_inicial->executar(gg);
        }
        if(controle == IdsMenu::ranking){
            menu_inicial->mostrar_ranking(gg);
            controle = IdsMenu::menu_continua;
        }
        if(controle == IdsMenu::creditos){
            menu_inicial->mostrar_creditos(gg);
            controle = IdsMenu::menu_continua;
        }
        if(controle == IdsMenu::fecha){
            gg->fechaJanela();
        }

        if(controle == IdsMenu::fase0_abre){
            delete fase;
            fase = new Fase_teste;
            fase->inicializar(gg);
            controle = fase0_continua;
        }
        if(controle == IdsMenu::fase0_continua){
            controle = fase->executar(gg);
        }
    }
    //exit(0);
}