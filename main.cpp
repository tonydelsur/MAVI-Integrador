#include<SFML/graphics.hpp>
#include<SFML/system.hpp>
#include<SFML/window.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "principal.h"
#include "fondo.h"
#include "NPC.h"
#include "Mira.h"
#include "HUD.h"

using namespace sf;
using namespace std;

int main() {
	sf::Texture Tback;
	Tback.loadFromFile("./assets/FONDO-NIVEL1.png");
	sf::Texture Tmira;
	Tmira.loadFromFile("./assets/MIRA.png");
	// VARIABLES DE JUEGO
	int estado = 1; //0- Intro 1- menu, 2- jugar, 3- game over
	int vidas = 0;
	int tipo = 0;
	int posNPC = 0;
	bool  jugando = false;
	int bajasMalos = 0;
	int bajasBuenos = 0;
	int puntos = 0;
	float tiempoEspera = 3000; // mili-segundos
	clock_t tiempoInicial = clock();
	int nada;
	sf::Sprite Menu;
	sf::Texture MenuT;
	HUD interface;

	fondo back;
	back.colocarTextura(Tback);
	NPC personaje;
	// personaje.colocarTextura(Tnpc);
	// personaje.setPosition(80, 150);
	Mira jugador;
	jugador.colocarTextura(Tmira);
	jugador.setPosition(400, 300);
	

	
	//Creamos la ventana
	sf::RenderWindow Ventana(sf::VideoMode(800, 600, 32),"3-2-1 Dispara");
	Ventana.setFramerateLimit(30);
	// Loop principal
	while (Ventana.isOpen()) {
		switch (estado)
		{
		case 1:
			Ventana.setMouseCursorVisible(true);
			MenuT.loadFromFile("./assets/INICIO.png");
			Menu.setTexture(MenuT);
			Menu.setPosition(0,0);
			Ventana.clear();
			Ventana.draw(Menu);
			Ventana.display();
			sf::Event evento;
			while (Ventana.pollEvent(evento)) {
				if (evento.type == sf::Event::Closed){
					Ventana.close();
				}
				if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
					int posX = sf::Mouse::getPosition(Ventana).x;
					int posY = sf::Mouse::getPosition(Ventana).y;
					if (posX > 230 && posX< 390 && posY> 450 && posY < 500) {
						estado = 2;
						break;
					}
					if (posX > 410 && posX < 570 && posY> 450 && posY < 500) {
						Ventana.close();
						break;
					}
				}
				
			}


			break;

		case 2:
			Ventana.setMouseCursorVisible(false);
			vidas = 3;
			puntos = 0;
			bajasBuenos = 0;
			bajasMalos = 0;
			while (vidas > 0) {
				bool colision = false;
				if (!jugando) {
					tipo = rand() % 2 + 1;
					posNPC = rand() % 5 + 1;
					tiempoInicial = clock();
					jugando = true;
					personaje.colocarTextura(tipo, posNPC);
					personaje.actualizarPosicion(posNPC);
					interface.actualizar(puntos, vidas);

				}
			
			
				sf::Event evento;
				while (Ventana.pollEvent(evento)) {
					if (evento.type == sf::Event::Closed)
						Ventana.close();
					if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
						if (personaje.pegar(Ventana)) {
							if (tipo == 2) {
								bajasMalos++;
								puntos = bajasMalos - bajasBuenos * 2;
								jugando = false;
								std::cout << "Puntos: " << puntos << endl;
								interface.actualizar(puntos, vidas);
							}
							else {
								bajasBuenos++;
								vidas--;
								puntos = bajasMalos - bajasBuenos * 2;
								jugando = false;
								std::cout << "Puntos: " << puntos << endl;
								interface.actualizar(puntos, vidas);
							}
						}
					}

				}
				jugador.actualizar(Ventana);

				// Limpiamos la ventana
				Ventana.clear();
				back.dibujar(Ventana);
				personaje.dibujar(Ventana);
				jugador.dibujar(Ventana);
				interface.dibujar(Ventana);
				Ventana.display();
				if ((clock()-tiempoInicial) > (tiempoEspera * CLOCKS_PER_SEC / 1000)) {
					if (tipo == 2) {
						vidas--;
						std::cout << "Vidas: " << vidas << endl;
					}
					jugando = false;
					interface.actualizar(puntos, vidas);
				}
			}
			estado = 3;
			break;
		case 3:
			Ventana.setMouseCursorVisible(true);
			MenuT.loadFromFile("./assets/FINAL.png");
			Menu.setTexture(MenuT);
			Menu.setPosition(0, 0);
			Ventana.clear();
			Ventana.draw(Menu);
			interface.dibujarPuntos(Ventana);
			Ventana.display();
			while (Ventana.pollEvent(evento)) {
				if (evento.type == sf::Event::Closed) {
					Ventana.close();
				}
				if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
					
						estado = 1;
						break;
					
					
				}

			}


			break;
		}
	}
	return 0;
}

