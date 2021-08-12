#include "../lib/GerenciadorGrafico.h"
#include <iostream>
using namespace std;

GerenciadorGrafico::GerenciadorGrafico() :
	janela { new sf::RenderWindow(sf::VideoMode(800, 600), "Game") },
	camera { sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f) }
{
	//janela->setFramerateLimit(60);
	janela->setView(camera);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela)
	{
		janela->close();
	}
	delete janela;

	for (auto i = texturas.begin(); i != texturas.end(); ++i)
	{
		delete i->second;
	}
}

void GerenciadorGrafico::mostrar() const
{
	janela->display();
}

void GerenciadorGrafico::limpar(int r, int g, int b)
{
	janela->clear(sf::Color(r, g, b));
}

void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor2F posicao, const Vetor2F tamanho)
{
	if (texturas.count(caminho) == 0)
	{
		std::cout << "OPA! Imagem nao carregada em " << caminho << std::endl;
		exit(121);
	}

	sf::Texture* text = texturas[caminho];

	sf::Sprite sprite;

	text->setSmooth(true);

	sprite.setTexture(*text);
	sprite.setScale(sf::Vector2f((tamanho.x / text->getSize().x), (tamanho.y / text->getSize().y)));
	sprite.setOrigin(sf::Vector2f(text->getSize().x / 2.0, text->getSize().y / 2.0));
	sprite.setPosition(posicao.x, posicao.y);
	janela->setView(camera);
	janela->draw(sprite);
}

bool GerenciadorGrafico::carregarTextura(const std::string& caminho)
{
	if (texturas.count(caminho) > 0)
	{
		return true;
	}
	else
	{
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(caminho))
		{
			std::cout << "OPA! Imagem nao encontrada em " << caminho << std::endl;
			exit(120);
		}
		texturas.emplace(caminho, text);
		return true;
	}
}

void GerenciadorGrafico::centralizar(const Vetor2F centro)
{
	camera.setCenter(sf::Vector2f(centro.x, centro.y));
	janela->setView(camera);
}

sf::RenderWindow* GerenciadorGrafico::getJanela() const
{
	return janela;
}

std::map<const std::string, sf::Texture*> GerenciadorGrafico::getTextura()
{
	return texturas;
}

void GerenciadorGrafico::inicializarBackground(const std::string& caminho, Vetor2F tamanho)
{
	background_textura.loadFromFile(caminho);

	background_textura.setSmooth(true);
	background_textura.setRepeated(true);

	background.setTextureRect(sf::IntRect(0, 0, tamanho.x*2, background_textura.getSize().y));
	background.setTexture(background_textura);
	background.setOrigin(background_textura.getSize().x, background_textura.getSize().y/2);
	background.setPosition(tamanho.x/2, tamanho.y/12);
	background.setScale(1, 1.9);

}

void GerenciadorGrafico::desenharBackground()
{
	janela->draw(background);
}