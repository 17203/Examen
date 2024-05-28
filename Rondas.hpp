#ifndef rondas_h
#define rondas_h

#include "Rrectangle.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class Ronda{
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
void spawn();
void rondaTerminada();
};

#endif
