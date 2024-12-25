#pragma once
#include "principal.h"
class Mira :
    public principal
{
public:
    Mira();
    void colocarTextura(sf::Texture& textura);
    void actualizar(sf::RenderWindow &ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;
   
};

