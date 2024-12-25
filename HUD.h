#pragma once
#include<SFML/graphics.hpp>

class HUD
{
private:
	sf::Sprite textoVidas, textoPuntos, valorVidas, valorPuntos;
	sf::Texture textoTvidas, textoTpuntos, valorTvidas, valorTpuntos;


public:
	HUD();
	void actualizar(int _puntos, int _vidas);
	void dibujar(sf::RenderWindow& ventana);
	void dibujarPuntos(sf::RenderWindow& ventana);
};

