#include "../lib/Fase.h"

#include <iostream>
#include <list>
using namespace std;


Fase::Fase()
{
	gerenciador_grafico_Fase = NULL;
	gerenciador_comandos_Fase = NULL;
	gerenciador_colisoes_Fase = NULL;
	j = NULL;
	al = NULL;
	p2 = NULL;
}
Fase::~Fase()
{
    ListaEntidades.destruirEntidades();
	delete gerenciador_colisoes_Fase;
}

void Fase::inicializar(GerenciadorGrafico* gg)
{
}

int Fase::executar(GerenciadorGrafico* gg)
{
	sf::Time t;
	t = relogio.restart();
	limpar();
	gg->desenharBackground();
	ListaEntidades.atualizarEntidades(t.asSeconds());
	gerenciador_colisoes_Fase->verificarColisoes();
	gerenciarP2(gg);
	ListaEntidades.desenharEntidades(*gg);
	gg->mostrar();
	verificarInimigos();

	if(al->getVida() == false){
		limpar();
		gg->desenharBackground();
		ListaEntidades.desenharEntidades(*gg);
		gg->mostrar();
		gg->mostrar();
		gerenciador_grafico_Fase->mostrarTexto("Venceu ! ! !");
		return proximaFase();
	}
	if (j->getVida() == false || j->getPosicao().y > 1500.f)
	{
		gerenciador_grafico_Fase->mostrarTexto("Perdeu ! ! !");
		return reiniciaFase();
	}
	if(p2)
	{
		if(p2->getVida() == false || p2->getPosicao().y > 1500.f)
		{
			gerenciador_grafico_Fase->mostrarTexto("Perdeu ! ! !");
			return reiniciaFase();
		}
	}
	if (gerenciador_comandos_Fase->comandosFuncionalidades() == GerenciadorComandos::Comandos::comeco)
	{
		return IdsMenu::menu_abre;
	}
	return IdsMenu::fase_continua;
}

void Fase::adicionar(Entidade* e)
{
	ListaEntidades.inserir(e);
	gerenciador_colisoes_Fase->adicionarEntidade(e);
}


void Fase::inicializarTextura(Entidade* e)
{
	e->inicializarTextura(gerenciador_grafico_Fase);
}


void Fase::remover(Entidade* e)
{
	gerenciador_colisoes_Fase->removerEntidade(e);
	ListaEntidades.removerEntidades(e);
}

GerenciadorGrafico* Fase::getGerenciadorGrafico()
{
	return gerenciador_grafico_Fase;
}

void Fase::verificarInimigos()
{
	std::set<Inimigo*>::iterator itr1;
	std::list<Inimigo*> mortos;
	for (itr1 = inimigos.begin(); itr1 != inimigos.end(); itr1++)
	{
		Inimigo* ini = *itr1;
		if (!ini->getVida())
		{
			mortos.push_back(ini);
		}
	}

	std::list<Inimigo*>::iterator itr2;
	for (itr2 = mortos.begin(); itr2 != mortos.end(); itr2++)
	{
		Inimigo* morto = *itr2;
		remover(static_cast<Entidade*>(morto));
		inimigos.erase(morto);
		delete morto;
	}

}

void Fase::adicionarInimigo(Inimigo* ini)
{
	adicionar(static_cast<Entidade*>(ini));
	inimigos.insert(ini);
}
/*
int Fase::reiniciaFase()
{
	return IdsMenu::fase0_abre;
}

int Fase::proximaFase()
{
	return IdsMenu::fase1_abre;
}

void Fase::limpar()
{
	gerenciador_grafico_Fase->limpar(0x62, 0x3e, 0x26);
}
*/
void Fase::gerenciarP2(GerenciadorGrafico* gg)
{
	unsigned int pressionados = gerenciador_comandos_Fase->comandosBolas();
	if (!p2)
	{

		if(((pressionados >> GerenciadorComandos::adicionar2)%2))
		{
			p2 = new Russia(j->getPosicao(), "Russia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f));
			ListaEntidades.inserir(static_cast<Entidade*>(p2));
			gerenciador_colisoes_Fase->adicionarEntidade(static_cast<Entidade*>(p2));
			p2->setFase(this);
			p2->inicializarTextura(gg);

		}
	}
	else if (((pressionados >> GerenciadorComandos::remover2)%2))
	{
		remover(p2);
		delete p2;
		p2 = nullptr;
	}
}