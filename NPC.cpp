#include "NPC.h"

NPC::NPC() : principal() {
	alto = 0;
	ancho = 0;
}

void NPC::colocarTextura(int _tipo, int _posNPC) {
	std::string nombreArchivo;
	if (_tipo == 1) {
		nombreArchivo = "./assets/NPC-" + std::to_string(_posNPC) + ".png";
	}
	else {
		nombreArchivo = "./assets/NPC-" + std::to_string(_posNPC) + "Z.png";
	}
	textura.loadFromFile(nombreArchivo);
	sprite.setTexture(textura);
	sprite.setTextureRect(sf::IntRect(0, 0, textura.getSize().x, textura.getSize().y)); // no se aadapta a las texturas de 2 digitos
	ancho = textura.getSize().x;
	alto = textura.getSize().y;
}
void NPC::actualizar(sf::RenderWindow& ventana) { }

void NPC::actualizarPosicion(int _posNPC) {
	switch (_posNPC)
	{
	case 1:
		x = 637;
		y = 239;
		break;
	case 2:
		x = 526;
		y = 100;
		break;
	case 3:
		x = 142;
		y = 298;
		break;
	case 4:
		x = 165;
		y = 84;
		break;
	case 5:
		x = 384;
		y = 316;
		break;

	default:
		break;
	}
	sprite.setPosition(x, y);

}
void NPC::dibujar(sf::RenderWindow& ventana) {
	ventana.draw(sprite);
}
bool NPC::pegar(sf::RenderWindow& ventana) {
	int posX = sf::Mouse::getPosition(ventana).x;
	int posY = sf::Mouse::getPosition(ventana).y;
	if (posX > x && posX< (x + ancho) && posY> y && posY < (y + alto)) {
		return true;
	}
	else {
		return false;
	}
}

