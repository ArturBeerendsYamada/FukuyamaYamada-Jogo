#include "../lib/Principal.h"

#define WIDTH 800
#define HEIGHT 600

Principal::Principal() :
	fase(nullptr) 
{
    menu_inicial = new Menu;
    fase = NULL;
	gg = new GerenciadorGrafico;
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
        }
        if(controle == IdsMenu::menu_continua){
            controle = menu_inicial->executar(gg);
        }
        if(controle == IdsMenu::creditos){
            menu_inicial->mostrar_creditos(gg);
            controle = IdsMenu::menu_continua;
        }
        if(controle == IdsMenu::fecha){
            gg->fechaJanela();
        }

        if(controle == IdsMenu::fase0_abre){
            if(fase)
                delete fase;
            fase = NULL;
            fase = new Tutorial();
            fase->inicializar(gg);
            controle = fase_continua;
        }
        if(controle == IdsMenu::fase1_abre){
            if(fase)
                delete fase;
            fase = NULL;
            fase = new Floresta();
            fase->inicializar(gg);
            controle = fase_continua;
        }
        if(controle == IdsMenu::fase2_abre){
            delete fase;
            fase = new Praia;
            fase->inicializar(gg);
            controle = fase_continua;
        }
        if(controle == IdsMenu::fase_continua){
            controle = fase->executar(gg);
        }
    }
}