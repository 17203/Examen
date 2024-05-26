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

    vector<Rectangle> rectangulos;

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
                    Rectangle r = Rectangle(Vector2f(x, y), window);
                    rectangulos.push_back(r);
                    r.drawTo(window);
                }

                if (event.mouseButton.button == Mouse::Right)
                {
                    for (auto &r : rectangulos)
                    {
                        r.changeColorIfClicked(Mouse::getPosition(window));
                    }
                    ron1.disparaBala();
                }
            }
        }

        window.clear();
        for (auto &r : rectangulos)
        {
            r.update();
            r.drawTo(window);
        }
        ron1.drawTo(window);//balas de la ronda actual
        window.display();
        ron1.update();//reinincia rondnas
    }

    return 0;
}