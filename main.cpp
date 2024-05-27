#include <SFML/Graphics.hpp>
#include "Rondas.hpp"
#include "Rrectangle.hpp"
#include <vector>

using namespace std;
using namespace sf;

int main()
{
    Ronda ron1;
    RenderWindow window(VideoMode(1200, 1000), "SFML works!");

    window.setFramerateLimit(120);

    vector<Pato1> patos;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    float x = float(50);
                    float y = float(50);
                    Pato1 p = Pato1(Vector2f(x, y), window);
                    patos.push_back(p);
                    p.drawTo(window);
                }

                if (event.mouseButton.button == Mouse::Right)
                {
                    for (auto &p : patos)
                    {
                        p.changeColorIfClicked(Mouse::getPosition(window));
                    }
                    ron1.disparaBala();
                }
            }
        }

        window.clear();
        for (auto &p : patos)
        {
            p.update();
            p.drawTo(window);
        }
        ron1.drawTo(window);//balas de la ronda actual
        window.display();
        ron1.update();//reinincia rondnas
    }

    return 0;
}