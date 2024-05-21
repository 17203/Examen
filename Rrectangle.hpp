#ifndef rectangle_h
#define rectangle_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Rectangle{
private:
    Vector2f speed;
    Vector2f acc;
    RectangleShape shape;
public:
    Rectangle(Vector2f size,RenderWindow &window);

    void changeColorIfClicked(Vector2i position);
    void update();
    void drawTo(RenderWindow &window);


};

#endif