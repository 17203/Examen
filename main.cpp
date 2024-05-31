#include <SFML/Graphics.hpp>
#include "Rondas.hpp"
#include "Rrectangle.hpp"
#include "partida.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

Ronda ron1;
Pato1* pato = nullptr;
Partida partida(10, true);

void crearPato(RenderWindow &window);
int main()
{
    RenderWindow window(VideoMode(1200, 1000), "cazapato");
    window.setFramerateLimit(120);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left && ron1.getBalas() > 0)
                {
                    ron1.disparaBala();
                    if (pato != nullptr && pato->disparoAcertado(Mouse::getPosition(window)))
                    {
                        ron1.rondaTerminada();
                        delete pato;
                        pato = nullptr;
                    }
                }
            }
        }

        window.clear();

        if (pato != nullptr)
        {
            pato->update();
            pato->drawTo(window);
            if (pato->getRebotesY() >= 5)
            {
                ron1.rondaTerminada();
                delete pato;
                pato = nullptr;
            }
        }
        else if (ron1.getBalas() > 0)
        {
            crearPato(window);
        }

        ron1.drawTo(window); // balas de la ronda actual
        window.display();
        ron1.update(); // reinicia rondas
    }

    return 0;
}

void crearPato(RenderWindow &window)
{
    float x = float(50);
    float y = float(50);
    pato = new Pato1(Vector2f(x, y), window);
    pato->drawTo(window);
}
