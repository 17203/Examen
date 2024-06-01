#include "partida.hpp"

Partida::Partida(int r, bool JS)
{
    rondas = r;
    juegoSigue = JS;
    prob = rand() % 5;
}