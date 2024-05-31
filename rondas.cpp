#include "Rondas.hpp"
#include <iostream>

Ronda::Ronda()
{
    this->balas = 3;
    this->puntuacion = 0;
    this->enemigos = 0;
    this->cont = 0;
}

void Ronda::update()
{
    if (balas == 0 && enemigos == 0)
    {
        reiniciarBalas();
        puntuacion++;
        this->cont++;
    }
}

int Ronda::disparaBala()
{
    if (this->balas > 0)
    {
        this->balas--;
    }
    return this->balas;
}

void Ronda::reiniciarBalas()
{
    this->balas = 3;
}

void Ronda::rondaTerminada()
{
    puntuacion++;
    reiniciarBalas();
    enemigos--;
    std::cout << "Ronda terminada" << std::endl;
}

void Ronda::drawTo(RenderWindow &window)
{
    for (int i = 0; i < balas; i++)
    {
        RectangleShape shape;
        shape.setFillColor(Color::White);
        shape.setPosition(1150, 150 + i * 120);
        shape.setSize(Vector2f(30, 100));
        window.draw(shape);
    }
}

int Ronda::getBalas() const
{
    return balas;
}
