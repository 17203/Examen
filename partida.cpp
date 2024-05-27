#include "partida.hpp"
#include "Rondas.hpp"
#include "Rrectangle.hpp"
#include <SFML/Graphics.hpp>

Partida::Partida(int r,bool JS){
    rondas=r;
    juegoSigue=JS;
    prob=rand()%5;
}
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
