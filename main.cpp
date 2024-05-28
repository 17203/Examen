#include <SFML/Graphics.hpp>
#include "Rondas.hpp"
#include "Rrectangle.hpp"
#include "partida.hpp"
#include <vector>
using namespace std;
using namespace sf;

Ronda ron1;
vector<Pato1> patos;
Partida partida(10,true);

void crearPato(RenderWindow &window);
int main()
{
    
    RenderWindow window(VideoMode(1200, 1000), "SFML works!");

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
                if (event.mouseButton.button == Mouse::Left)
                {
                    partida.jugar(window);
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


Partida::Partida(int r,bool JS){
    rondas=r;
    juegoSigue=JS;
    prob=rand()%5;
}

void crearPato(RenderWindow &window){
float x = float(50);
    float y = float(50);
    Pato1 p = Pato1(Vector2f(x, y), window);
    patos.push_back(p);
    p.drawTo(window);
}
void Partida::jugar(RenderWindow &window){
    for (int i=0; i!=10; i++){
    crearPato(window);


    }

};
Ronda::Ronda(){
    this->balas = 3;
    this->puntuacion = 0;
    this->enemigos = 0;
    this->cont = 0;
}

void Ronda::update(){
    if (balas == 0) {
        balas = 3;
        puntuacion++;//se incrementa puntuación para probar que el codigo pase de ronda
        this->cont++;
    }
}

void Ronda::drawTo(RenderWindow &window){// representacion de balas
    for (int i = 0; i < balas; i++) {
        RectangleShape shape;
        shape.setFillColor(Color::White);
        shape.setPosition(1150, 150 + i * 120);
        shape.setSize(Vector2f(30, 100));
        window.draw(shape);
    }
}

void Ronda::disparaBala(){//Comprobación de balas
    if (balas > 0) {
        balas--;
    } else {//mismo que en drawTo
        balas = 3;
        //drawTo(RenderWindow &window){//spawnea un nuevo enemigo cada nueva ronda
      //   window.draw(this->shape);
      //  }
    }
}
