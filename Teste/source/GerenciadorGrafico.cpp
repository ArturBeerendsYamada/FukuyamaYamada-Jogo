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
	camera.setCenter(centro.x, min(centro.y, 580.f));
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
	background.setPosition(-2000, 100);
	background.setScale(1, 1.2);

}

void GerenciadorGrafico::desenharBackground()
{
	janela->draw(background);
}

void GerenciadorGrafico::mostrarTexto(const char* texto)
{
	sf::Font font;
	if (!font.loadFromFile("mytype.ttf"))
	{
		cout << "Fonte nao carregada" << endl;
	}
	sf::Text texto_a_mostrar;
	texto = texto;
	texto_a_mostrar.setFont(font);
	texto_a_mostrar.setPosition(camera.getCenter().x, camera.getCenter().y);
	texto_a_mostrar.setStyle(1);
	texto_a_mostrar.setCharacterSize(50);
	texto_a_mostrar.setFillColor(sf::Color::Red);
	texto_a_mostrar.setString(texto);
	janela->draw(texto_a_mostrar);
	janela->display();

	sf::Clock relogio;
	relogio.restart();
	while(janela->isOpen())
	{
		sf::Event event;
		if(relogio.getElapsedTime().asSeconds() >= 2)
			return;
		while(janela->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				exit(0);
			}
		}
	}
}