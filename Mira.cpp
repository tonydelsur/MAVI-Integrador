#include "Mira.h"

Mira::Mira() : principal() {
	
}

void Mira::colocarTextura(sf::Texture& textura) {
	sprite.setTexture(textura);
	sprite.setOrigin(textura.getSize().x / 2, textura.getSize().y / 2);
}
void Mira::actualizar(sf::RenderWindow& ventana) {
	x = sf::Mouse::getPosition(ventana).x;
	y = sf::Mouse::getPosition(ventana).y;
	if (x < 0) x = 0;
	if (x > 800) x = 800;
	if (y < 0) y = 0;
	if (y > 600) y = 600;
	sprite.setPosition(x, y);
}
void Mira::dibujar(sf::RenderWindow& ventana) {
	ventana.draw(sprite);
}


