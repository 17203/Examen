#ifndef rondas_h
#define rondas_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Ronda{
private:
   int balas;
   int puntuacion;
   int enemigos;
public:
Ronda();
void disparaBala();
void update();
void drawTo(RenderWindow &window);

};

#endif