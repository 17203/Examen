#ifndef PARTIDA_H
#define PARTIDA_H

#include "Rrectangle.hpp"
#include "Rondas.hpp"

class Partida
{
private:
    int rondas;
    bool juegoSigue;
    int prob;

public:
    Partida(int r, bool JS);
    void jugar(RenderWindow &window);
};

#endif
