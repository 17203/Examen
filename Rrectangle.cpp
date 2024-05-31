#include "Rrectangle.hpp"
#include <SFML/Graphics.hpp>

Pato1::Pato1(Vector2f size, RenderWindow &window)
{
    shape = RectangleShape(size);
    shape.setPosition({rand() % 1200, 940});
    shape.setFillColor(Color::Red);
    if (rand() % 5 == 2)
    {
        speed = Vector2f(6.f, 6.f);
        shape.setFillColor(Color::Cyan);
    }
    else
    {
        speed = Vector2f(4.f, 4.f);
    }
    acc = Vector2f(0.f, 0.f);
    shape.setOutlineThickness(3);
    shape.setOutlineColor(Color::Cyan);
    rebotesx = 0;
    rebotesy = 0;
    vivo = true;
}

void Pato1::update()
{
    speed -= acc;
    shape.move(speed);
    if (shape.getPosition().x + shape.getSize().x >= 1200 || shape.getPosition().x < 0)
    {
        speed.x *= -1;
        shape.setOutlineColor(Color::White);
        rebotesx++;
    }
    if (vivo == true)
    {
        if (shape.getPosition().y + shape.getSize().y >= 1000 || shape.getPosition().y < 0)
        {
            speed.y *= -1;
            shape.setOutlineColor(Color::Green);
            rebotesy++;
        }
    }
    else if (shape.getPosition().y + shape.getSize().y >= 1000)
    {
        speed.y = 0; // no desaparece de pantalla estatico abajo
    }
    if (rebotesy > 5)
    {
        if (shape.getPosition().y <= 0)
        {
            shape.setPosition(-1000, -1000);
        }
    }
    if (vivo == true)
    {
        if (rebotesy > 1)
        {
            if (shape.getPosition().y + shape.getSize().y >= 600)
            {
                rebotesy++;
                speed.y *= -1;
            }
        }
    }
}

void Pato1::drawTo(RenderWindow &window)
{
    window.draw(shape);
}

bool Pato1::disparoAcertado(Vector2i position)
{
    float x = shape.getPosition().x;
    float y = shape.getPosition().y;
    float w = shape.getSize().x;
    float h = shape.getSize().y;
    int mouseX = position.x;
    int mouseY = position.y;
    if (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h)
    {
        shape.setFillColor(Color::Green);
        vivo = false;
        speed.y = 4;
        speed.x = 0;
        return true;
    }
    else return false;
}

int Pato1::getRebotesY() const
{
    return rebotesy;
}
