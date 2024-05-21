#include "Rondas.hpp"

Ronda::Ronda(){
    this->balas=3;
    this->puntuacion=0;
    this->enemigos=0;
}

void Ronda::update(){
    
}
void Ronda::drawTo(RenderWindow &window){
    RectangleShape shape;
    shape.setFillColor(Color::White);
    shape.setPosition(1150, 150);
    shape.setSize(Vector2f(30, 100));

    window.draw(this->shape);

}

void Ronda::disparaBala(){//si se llega al limite de balas ya no dispara y da una advertencia
    if(balas>0){
    balas--;}
    else{
    //implementar un fin de ronda
    }
}
