#include "HUD.h"

HUD::HUD() {
	textoTpuntos.loadFromFile("./assets/numeros/puntos.png");
	textoTvidas.loadFromFile("./assets/numeros/vidas.png");
	textoPuntos.setTexture(textoTpuntos);
	textoVidas.setTexture(textoTvidas);
}

void HUD::actualizar(int _puntos, int _vidas) {
	std::string nombreArchivo = "./assets/numeros/" + std::to_string(_vidas) + ".png";
	valorTvidas.loadFromFile(nombreArchivo);
	if (_puntos < 0) {
		nombreArchivo = "./assets/numeros/0.png";
	}
	else {
		nombreArchivo = "./assets/numeros/" + std::to_string(_puntos) + ".png";
	}
	valorTpuntos.loadFromFile(nombreArchivo);
	valorPuntos.setTexture(valorTpuntos);
	valorPuntos.setTextureRect(sf::IntRect(0, 0, valorTpuntos.getSize().x, valorTpuntos.getSize().y)); // no se aadapta a las texturas de 2 digitos
	valorVidas.setTexture(valorTvidas);
	

}

void HUD::dibujarPuntos(sf::RenderWindow& ventana) {
	textoPuntos.setPosition(300, 280);
	valorPuntos.setPosition(500, 280);
	ventana.draw(textoPuntos);
	ventana.draw(valorPuntos);

}

void HUD::dibujar(sf::RenderWindow& ventana) {
	textoVidas.setPosition(100, 10);
	valorVidas.setPosition(250, 10);
	textoPuntos.setPosition(500, 10);
	valorPuntos.setPosition(700, 10);
	ventana.draw(textoVidas);
	ventana.draw(textoPuntos);
	ventana.draw(valorVidas);
	ventana.draw(valorPuntos);


}


