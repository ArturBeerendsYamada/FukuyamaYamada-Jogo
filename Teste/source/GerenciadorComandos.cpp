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
}

GerenciadorComandos::Comandos  GerenciadorComandos::comandosFuncionalidades()
{
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


GerenciadorComandos::Comandos GerenciadorComandos::comandosBolas()
{

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
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
	return nulo;
}

GerenciadorComandos* GerenciadorComandos::g = nullptr;