#include <SFML/Graphics.hpp>
#include "Rrectangle.hpp"
#include "Rondas.hpp"
#include <vector>
using namespace std;
using namespace sf;

Ronda rondas;
vector <Rectangle>rectangulos;
float speedX=1.f;
float speedY=1.f;
int main()
{
    RenderWindow window(VideoMode(1200, 1000), "SFML works!");
    
    
    window.setFramerateLimit(120);

Rectangle rect(Vector2f(60.f,30.f),window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // escucha una vez cuando se presiona el click izquierdo del mouse
            if (event.type == Event::Closed)
                window.close();
            if (event.type==Event::MouseButtonPressed){
                if(event.mouseButton.button== Mouse::Left){
                    float x=float(50);
                    float y=float(50);
                    Rectangle r= Rectangle (Vector2f(x,y),window);
                    rectangulos.push_back(r);
                    r.drawTo(window);
                }
             if(event.mouseButton.button== Mouse::Right){
            for(auto &r : rectangulos){
            r.changeColorIfClicked(Mouse::getPosition(window));
            rondas.disparaBala();
        }
             }
            }
        }

//entra al if si el click iquerido esta presionado
        if(Mouse::isButtonPressed(Mouse::Left));

        window.clear();
        for(auto &r: rectangulos){
            r.update();
            r.drawTo(window);
        }
        // rect.update();
        // rect.drawTo(window);
        window.display();
    }

    return 0;
}