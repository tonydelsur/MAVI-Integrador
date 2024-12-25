#pragma once
#include<SFML/graphics.hpp>

class principal
{

protected:
	sf::Sprite sprite;
	sf::Texture textura;
	float x, y;

public:
	principal();
	virtual void actualizar(sf::RenderWindow& ventana) = 0;
	virtual void dibujar(sf::RenderWindow& ventana) = 0;
	void setPosition(float _x, float _y);
	float verX();
	float verY();
};

