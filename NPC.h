#pragma once
#include "principal.h"
class NPC :
    public principal
    
{
private:
    int ancho, alto;
public:
    NPC();
    void colocarTextura(int _tipo, int _posNPC);
    void actualizar(sf::RenderWindow& ventana) override;
    void actualizarPosicion(int _posNPC);
    void dibujar(sf::RenderWindow& ventana) override;
    bool pegar(sf::RenderWindow& ventana);
};

