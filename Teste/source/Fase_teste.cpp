#include "../lib/Fase_teste.h"

#include <iostream>
#include <list>
using namespace std;

Fase_teste::Fase_teste()
{
}
Fase_teste::~Fase_teste()
{
	ListaEntidades.destruirEntidades();
	delete gerenciador_colisoes_fase_teste;
	delete j;
}

void Fase_teste::inicializar(GerenciadorGrafico* gg)
{
	gerenciador_comandos_fase_teste = GerenciadorComandos::getComandos();
	gerenciador_colisoes_fase_teste = new GerenciadorColisoes;

	gerenciador_grafico_fase_teste = gg;

	Entidade* temp;

	temp = static_cast<Entidade*>(new ArameFarpado(Vetor2F(-800.0f, 1200.0f), "ArameFarpado.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(150.0f, 900.0f), "OuricoTcheco.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Mina(Vetor2F(-300.0f, 1125.0f), "Mina.png", Vetor2F(50.0f, 50.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(1200.0f, 0.0f), "Russia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(0.0f, 1200.0f), "Praia.jpg", Vetor2F(1000.f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 600.0f), "Italia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	/*ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);*/
	adicionarInimigo(static_cast<Inimigo*>(temp));

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 600.0f), "Italia_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	/*ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);*/
	adicionarInimigo(static_cast<Inimigo*>(temp));

	j = (new Jogador(Vetor2F(0.0f, 1000.0f), "Brasil_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(static_cast<Entidade*>(j));
	gerenciador_colisoes_fase_teste->adicionarEntidade(static_cast<Entidade*>(j));

	j->setFase(this);

	temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(-150.0f, 900.0f), "OuricoTcheco.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(-150.0f, 600.0f), "OuricoTcheco.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(-150.0f, 700.0f), "OuricoTcheco.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);
	temp = static_cast<Entidade*>(new OuricoTcheco(Vetor2F(-150.0f, 600.0f), "OuricoTcheco.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Mina(Vetor2F(300.0f, 1125.0f), "Mina.png", Vetor2F(50.0f, 50.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(1000.0f, 1300.0f), "Floresta.jpg", Vetor2F(1000.f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	temp = static_cast<Entidade*>(new Obstaculo(Vetor2F(-1000.0f, 1300.0f), "Floresta.jpg", Vetor2F(1000.f, 100.0f), Vetor2F(0.f, 0.f)));
	ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);

	//temp = static_cast<Entidade*>(new Japao(Vetor2F(1000.0f, 300.0f), "Japan_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	/*ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);*/
	//adicionarInimigo(static_cast<Inimigo*>(temp));

	//static_cast<Japao*>(temp)->setFase(this);

	temp = static_cast<Entidade*>(new Inimigo(Vetor2F(600.0f, 0.0f), "Alemanha_Countryball.png", Vetor2F(100.0f, 100.0f), Vetor2F(0.f, 0.f)));
	/*ListaEntidades.inserir(temp);
	gerenciador_colisoes_fase_teste->adicionarEntidade(temp);*/
	adicionarInimigo(static_cast<Inimigo*>(temp));
	ListaEntidades.inicializarEntidades(*gg);
}

int Fase_teste::executar(GerenciadorGrafico* gg)
{
	sf::Time t;

	t = relogio.restart();
	gg->limpar();
	ListaEntidades.atualizarEntidades(t.asSeconds());
	gerenciador_colisoes_fase_teste->verificarColisoes();
	ListaEntidades.desenharEntidades(*gg);
	gg->mostrar();
	verificarInimigos();	

	if (j->getVida() == false)
	{
		j->setVida(true);
		j->setPosicao(Vetor2F(0.0f, 1000.0f));
		//return IdsMenu::fase0_abre;
	}
	if (gerenciador_comandos_fase_teste->comandosFuncionalidades() == GerenciadorComandos::Comandos::comeco)
	{
		return IdsMenu::menu_abre;
	}
	return IdsMenu::fase0_continua;
}

void Fase_teste::adicionar(Entidade *e)
{
    ListaEntidades.inserir(e);
    gerenciador_colisoes_fase_teste->adicionarEntidade(e);
}

void Fase_teste::inicializarTextura(Entidade *e)
{
    e->inicializarTextura(gerenciador_grafico_fase_teste);
}

void Fase_teste::remover(Entidade *e)
{
    gerenciador_colisoes_fase_teste->removerEntidade(e);
    ListaEntidades.removerEntidades(e);
}

GerenciadorGrafico* Fase_teste::getGerenciadorGrafico(){
	return gerenciador_grafico_fase_teste;
}

void Fase_teste::verificarInimigos()
{
    std::set<Inimigo *>::iterator itr1;
    std::list<Inimigo* > mortos;
    for (itr1 = inimigos.begin(); itr1 != inimigos.end(); itr1++)
    {
        Inimigo* ini = *itr1;
        if(!ini->getVida()){
			mortos.push_back(ini);
        }
    }
	
    std::list<Inimigo* >::iterator itr2;
    for (itr2 = mortos.begin(); itr2 != mortos.end(); itr2++)
    {
		Inimigo* morto = *itr2;
        remover(morto);
        inimigos.erase(morto);
        delete morto;
    }
	/*Era para imprimir nada e acaba imprimindo o endereço do ultimo termo:
	for(itr2 = mortos.begin(); itr2 != mortos.end(); ++itr2)
	{
		std::cout << *itr2 << " . " <<std::endl;
	}
	*/
}

void Fase_teste::adicionarInimigo(Inimigo* ini)
{
    adicionar(ini);
    inimigos.insert(ini);
}