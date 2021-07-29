#include <SFML/Graphics.hpp>
#include <iostream>

class Personagem{
    private:
        float x, y;
        sf::Texture* text;
        sf::RectangleShape corpo;
        
    public:
        Personagem(float xIn = 0.0f, float yIn = 0.0f, const char* caminhoTextura = nullptr );
        ~Personagem();
        void atualizar();
        void desenhar(sf::RenderWindow* janela);
};