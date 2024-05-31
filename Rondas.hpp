#ifndef RONDAS_H
#define RONDAS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ronda
{
private:
    int balas;
    int puntuacion;
    int enemigos;
    int cont;

public:
    Ronda();
    int disparaBala();
    void reiniciarBalas();
    void update();
    void drawTo(RenderWindow &window);
    void rondaTerminada();
    int getBalas() const;
};

#endif
