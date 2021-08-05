#include "../lib/GerenciadorComandos.h"
#include <iostream>

GerenciadorComandos::GerenciadorComandos()
{

}

GerenciadorComandos* GerenciadorComandos::getComandos()
{
	if (!g)
	{
		g = new GerenciadorComandos();
	}
	return g;
}

GerenciadorComandos::~GerenciadorComandos()
{
	if(g)
	{
		delete g;
	}
}

GerenciadorComandos::Comandos  GerenciadorComandos::comandosFuncionalidades()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		return comeco;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
	{
		return adicionar2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
	{
		return remover2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		return pausar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		return continuar;
	}
	return nulo;
}


unsigned int GerenciadorComandos::comandosBolas()
{
	//ideia de controle com varias teclas pressionadas
		//cada tecla eh representada por um bit na variavel pressionados
		//esse bit eh determinado pelo deslocamento fornecido pelo enum
		//dessa forma, o retorno dessa funcao vai dizer TODAS as teclas que estao sendo pressionadas
			//nao soh a primeira da lista que estiver
			//dessa forma tambem dah pra mover mais de um jogador de cada vez
		//no receptor deve-se verificar nao o enum em si, mas o bit com o deslocamento de enum
		//de quebra elimina o problema que fez ter o nulo no enum, que era chegar no fim de uma non-void function
	unsigned int pressionados = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		pressionados += 1 << esquerda1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		pressionados += 1 << direita1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		pressionados += 1 << pular1;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		pressionados += 1 << atirar1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		pressionados += 1 << esquerda2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		pressionados += 1 << direita2;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		pressionados += 1 << pular2;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		pressionados += 1 << atirar2;
	}
	return pressionados;
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		return esquerda1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		return direita1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		return pular1;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		return atirar1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		return esquerda2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		return direita2;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		return pular2;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		return atirar2;
	}
	return nulo;*/
}

GerenciadorComandos* GerenciadorComandos::g = nullptr;